#include "Graph.h"
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>

Sommet Graph::trouverSommet(int indice) {
	return sommets[indice];
}

Graph Graph::creerGraph(std::ifstream& fichier)
{
	Graph graphDoubleSens;
	std::string ligne1 = "";
	std::string ligne2 = "";
	
		std::string identifiant, type, identifiantSommetDepart, identifiantSommetArrive,distance;
		getline(fichier, ligne1);
		std::stringstream line1(ligne1);
		getline(fichier, ligne2);
		std::stringstream line2(ligne2);
		while (!line1.eof())
		{
			getline(line1, identifiant, ',');
			getline(line1, type, ';');
			if (identifiant != "")
			{ 
				sommets.push_back(Sommet(identifiant, type));
				graphDoubleSens.sommets.push_back(Sommet(identifiant, type));
			}
		}
		while (!line2.eof())
		{
			Sommet* sommetDepart=nullptr;
			Sommet* sommetArrive=nullptr;
			getline(line2, identifiantSommetDepart, ',');
			getline(line2, identifiantSommetArrive, ',');
			getline(line2, distance, ';');
			if((identifiantSommetDepart!="") && (identifiantSommetArrive!="")  )
			{
			for (Sommet& sommet : sommets)
			{
				if (identifiantSommetDepart == sommet.getId() && sommetDepart==nullptr)
					sommetDepart = &sommet;
				if (identifiantSommetArrive == sommet.getId() && sommetArrive == nullptr)
					sommetArrive = &sommet;
				
			}
				arcs.push_back(Arc(sommetDepart,sommetArrive,std::stoi(distance)));
				graphDoubleSens.arcs.push_back(Arc(sommetDepart, sommetArrive, std::stoi(distance)));
				graphDoubleSens.arcs.push_back(Arc(sommetArrive, sommetDepart, std::stoi(distance)));
			}
		}
		fichier.close();
	
	return graphDoubleSens;
}

void Graph::lireGraph()
{
	int indice = 0;
	for (Sommet sommet:sommets)
	{
		bool premierArc = true;
		std::cout << indice << ". " <<"(" << sommet.getId() << ", " << sommet.getType() << "(";
		for(Arc arc:arcs)
			{
				if (sommet.getId() == arc.getSommetDepart()->getId())
				{
					if (!premierArc)
						std::cout << ", ";
					premierArc = false;
					std::cout << arc.getSommetArrive()->getId();
				}
			}

		std::cout << "))" << std::endl;
		indice++;
	}

	std::cout << std::endl << sommets.size();
	
}

Graph Graph::extractionGraph(Sommet sommetDepart, Vehicule vehicule)
{
	std::map<std::string, int> listeDistances;
	std::map<std::string, std::string> listeParcours;
	std::map<std::string, int> listeAutonomiesRestantes;
	std::map<std::string, Graph> listeSousGraphes;
	int distanceMaximale = 0;
	bool fin = false;

	Sommet sommetDistanceMaximale = sommetDepart;
	for (Sommet sommet : sommets)
		listeDistances[sommet.getId()] = -1;
	listeDistances[sommetDepart.getId()] = 0;
	listeParcours[sommetDepart.getId()] = sommetDepart.getId();
	listeAutonomiesRestantes[sommetDepart.getId()] = 100;

	std::set<std::string> sommetsVisites;

	while (!fin)
	{
		distanceMaximale = 0;
		for (Sommet sommet : sommets)
		{
			if ((sommetsVisites.find(sommet.getId()) == sommetsVisites.end()) && (listeDistances[sommet.getId()] > distanceMaximale))
			{
				distanceMaximale = listeDistances[sommet.getId()];
				sommetDistanceMaximale = sommet;
			}
		}
		sommetsVisites.insert(sommetDistanceMaximale.getId());
		if (sommetDistanceMaximale.getId() != sommetDepart.getId())
			fin = true;
		for (Sommet sommet : sommets)
		{
			if (sommetsVisites.find(sommet.getId()) == sommetsVisites.end())
				fin = false;
			else
				fin = true;
			if(listeSousGraphes[sommet.getId()].sommets.empty())
				listeSousGraphes[sommet.getId()].sommets.push_back(sommetDepart);
			for (Arc arc : arcs)
			{
				if ((arc.getSommetDepart()->getId() == sommetDistanceMaximale.getId())
					&&
					(arc.getSommetArrive()->getId() == sommet.getId())
					&&
					(distanceMaximale + arc.getDistance() > listeDistances[sommet.getId()])
					&&
					listeAutonomiesRestantes[sommetDistanceMaximale.getId()] >= vehicule.getCoefficientPerte() * (arc.getDistance()))

				{
					listeDistances[sommet.getId()] = listeDistances[sommetDistanceMaximale.getId()] + arc.getDistance();
					listeSousGraphes[sommet.getId()] = listeSousGraphes[sommetDistanceMaximale.getId()];
					//listeSousGraphes[sommet.getId()].sommets.push_back(sommetDistanceMaximale);
					listeSousGraphes[sommet.getId()].sommets.push_back(sommet);
					listeSousGraphes[sommet.getId()].arcs.push_back(arc);
					if (sommet.getId() != sommetDepart.getId()) 
						listeParcours[sommet.getId()] = listeParcours[sommetDistanceMaximale.getId()] + " -> " + sommet.getId();
					else
					{
						listeParcours[sommet.getId()] = sommet.getId();
					}
						
					listeAutonomiesRestantes[sommet.getId()] = listeAutonomiesRestantes[sommetDistanceMaximale.getId()] - (arc.getDistance() * vehicule.getCoefficientPerte());
					/*if (((arc.getSommetArrive()->getType() == vehicule.getType())
						|| ((vehicule.getType() == "hybrid") && (arc.getSommetArrive()->getType() != "rien"))
						|| (arc.getSommetArrive()->getType() == "hybrid"))
						&& (arc.getSommetArrive()->getId() != sommetArrive.getId()))
						listeAutonomiesRestantes[sommet.getId()] = 100;*/
					
				}
			}
		}
	}
	std::string sommetMax;
	int maxDistance = 0;
	for (auto itr = listeDistances.begin(); itr != listeDistances.end(); ++itr)
	{
		if (itr->second > maxDistance)
		{
			maxDistance = itr->second;
			sommetMax = itr->first;
		}
	}
	std::cout << std::endl;
	std::cout <<  "Le parcours est : " << listeParcours[sommetMax] << std::endl 
		<< "Le cout du chemin est : " << listeDistances[sommetMax] << std::endl 
		<< "L'autonomie restante du vehicule est : " << listeAutonomiesRestantes[sommetMax] << std::endl << std::endl;

	return listeSousGraphes[sommetMax];

}

void Graph::plusCourtChemin(Sommet sommetDepart, Sommet sommetArrive, Vehicule& vehicule)
{
	std::map<std::string, int> listeDistances;
	std::map<std::string, std::string> listeParcours;
	std::map<std::string, int> listeAutonomiesRestantes;
	int distanceMinimale = INFINI;
	bool fin = false;
	Sommet sommetDistanceMinimale = sommetDepart;
	for (Sommet sommet : sommets)
		listeDistances[sommet.getId()] = INFINI;
	listeDistances[sommetDepart.getId()] = 0;
	listeParcours[sommetDepart.getId()] = sommetDepart.getId();
	listeAutonomiesRestantes[sommetDepart.getId()] = 100;
	std::set<std::string> sommetsVisites;
	while ((sommetsVisites.find(sommetArrive.getId()) == sommetsVisites.end()) && !fin)
	{
		distanceMinimale = INFINI;
		for (Sommet sommet : sommets)
		{
			if ((sommetsVisites.find(sommet.getId()) == sommetsVisites.end()) && (listeDistances[sommet.getId()] < distanceMinimale))
			{
				distanceMinimale = listeDistances[sommet.getId()];
				sommetDistanceMinimale = sommet;
			}
		}
		sommetsVisites.insert(sommetDistanceMinimale.getId());
		if(sommetDistanceMinimale.getId()!=sommetDepart.getId())
			fin = true;
		for (Sommet sommet : sommets)
		{
			if (sommetsVisites.find(sommet.getId()) == sommetsVisites.end())
				fin = false;
			else
				fin = true;
				for (Arc arc : arcs)
				{
					if ((arc.getSommetDepart()->getId() == sommetDistanceMinimale.getId()) 
						&&
						(arc.getSommetArrive()->getId() == sommet.getId()) 
						&&
						(distanceMinimale + arc.getDistance() < listeDistances[sommet.getId()])
						&&
						listeAutonomiesRestantes[sommetDistanceMinimale.getId()]>= vehicule.getCoefficientPerte()*(arc.getDistance()))

					{
						listeDistances[sommet.getId()] = listeDistances[sommetDistanceMinimale.getId()] + arc.getDistance();
						if(sommet.getId()!=sommetDepart.getId())
							listeParcours[sommet.getId()] = listeParcours[sommetDistanceMinimale.getId()] + " -> " + sommet.getId();
						else
							listeParcours[sommet.getId()] = sommet.getId();
						listeAutonomiesRestantes[sommet.getId()]= listeAutonomiesRestantes[sommetDistanceMinimale.getId()]-(arc.getDistance()*vehicule.getCoefficientPerte());
						if (((arc.getSommetArrive()->getType() == vehicule.getType()) 
							|| ((vehicule.getType() == "hybrid") && (arc.getSommetArrive()->getType() != "rien")) 
							|| (arc.getSommetArrive()->getType() == "hybrid"))
							&& (arc.getSommetArrive()->getId()!=sommetArrive.getId()))
							listeAutonomiesRestantes[sommet.getId()] = 100;						
					}
				}
		}
	}
	if (listeParcours[sommetArrive.getId()] != "")
	{
		std::cout << "l'autonomie finale restante du vehicule est de " << listeAutonomiesRestantes[sommetArrive.getId()] << "%" << std::endl;
		std::cout << "Le plus court chemin utilise est: " << listeParcours[sommetArrive.getId()] << std::endl
			<< "La longueur du chemin le plus court est " << listeDistances[sommetArrive.getId()] << " Km" << std::endl << std::endl;
	}
	else
		std::cout << "Il n'y a pas de chemin de " + sommetDepart.getId() + " vers " + sommetArrive.getId();
}



