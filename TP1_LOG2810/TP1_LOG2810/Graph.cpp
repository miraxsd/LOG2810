#include "Graph.h"
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>

Graph Graph::creerGraph(std::ifstream& fichier)
{
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
			if(identifiant!="")
				sommets.push_back(Sommet(identifiant, type));
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
			}
		}
		fichier.close();
	

	return *this;
}
void Graph::lireGraph()
{
	
	for (Sommet sommet:sommets)
	{
		bool premierArc = true;
		std::cout <<"(" << sommet.getId() << ", " << sommet.getType() << "(";
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
	}
	
}

Graph Graph::extractionGraph(Sommet sommetDebut, Vehicule vehicule)
{
	Graph sousGraph;
	Graph sousGraphPlusLong;
	int distanceParcourue = 0;
	int distancePlusLongue = 0;
	std::vector<Arc> arcsParcourus;
	bool nouveauArc = true;
	/*for (Sommet sommet:sommets)
		while()*/
	Sommet sommetDepart = sommetDebut;

	for (Arc arc : arcs)
	{
		for (Arc arcPrecedent : arcsParcourus)
			if (arc.getSommetDepart() == arcPrecedent.getSommetDepart() && arc.getSommetArrive() == arcPrecedent.getSommetArrive() && arc.getDistance() == arcPrecedent.getDistance())
				nouveauArc = false;
		if(nouveauArc)
			if ((sommetDepart.getId() == arc.getSommetDepart()->getId()) && (arc.getDistance() <= vehicule.getAutonomieActuelle()))
			{
					sousGraph.sommets.push_back(sommetDepart);
					sousGraph.arcs.push_back(arc);
					vehicule.autonomieRestante(arc.getDistance());
					distanceParcourue += arc.getDistance();
					arcsParcourus.push_back(arc);
					if ((arc.getSommetArrive()->getType() == vehicule.getType()) || ((vehicule.getType() == "hybrid") && (arc.getSommetArrive()->getType() != "rien")) || (arc.getSommetArrive()->getType() == "hybrid"))
						vehicule.rechargerAutonomie();
					


				}
	}
	if (distancePlusLongue < distanceParcourue)
	{
		sousGraphPlusLong = sousGraph;
		distancePlusLongue = distanceParcourue;
	}	
	return sousGraph;
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
			<< "La longueur du chemin le plus court est " << listeDistances[sommetArrive.getId()] << " Km";
	}
	else
		std::cout << "Il n'y a pas de chemin de " + sommetDepart.getId() + " vers " + sommetArrive.getId();
}



