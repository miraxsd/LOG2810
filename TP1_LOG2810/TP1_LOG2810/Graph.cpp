#include "Graph.h"
#include <string>
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
					if ((arc.getSommetArrive()->getType() == vehicule.getType()) || ((vehicule.getType() == "hybrid") && (arc.getSommetArrive()->getType() != "null")) || (arc.getSommetArrive()->getType() == "multi"))
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



