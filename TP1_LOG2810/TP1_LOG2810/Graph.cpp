#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Graph Graph::creerGraph(std::ifstream& fichier)
{
	//std::ifstream fichier;
	//fichier.open(nomFichier + ".txt");
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
			sommets.push_back(Sommet(identifiant, type));
		}
		while (!line2.eof())
		{
			Sommet* sommetDepart=nullptr;
			Sommet* sommetArrive=nullptr;
			getline(line2, identifiantSommetDepart, ',');
			getline(line2, identifiantSommetArrive, ',');
			getline(line2, distance, ';');
			for (Sommet& sommet : sommets)
			{
				if (identifiantSommetDepart == sommet.getId())
					sommetDepart = &sommet;
				if (identifiantSommetArrive == sommet.getId())
					sommetArrive = &sommet;
			}
			arcs.push_back(Arc(sommetDepart,sommetArrive,std::stoi(distance)));
		}
		fichier.close();
	

	return *this;
}
void Graph::lireGraph()
{
	for (Sommet sommet:sommets)
	{
		std::cout <<"(" << sommet.getId() << ", " << sommet.getType() << "( ";
		for(Arc arc:arcs)
			{
			if (sommet.getId() == arc.getSommetDepart()->getId())
			{
				std::cout << arc.getSommetArrive()->getId();
				if (arc.getSommetArrive()->getId()!=arcs.back().getSommetArrive()->getId())
					std::cout << ", ";
			}
			}

		std::cout << "))" << std::endl;
	}
	
}

Graph Graph::extractionGraph(Vehicule vehicule)
{
	Graph sousGraph;
	/*for (Sommet sommet : sommets)
	{

		while()
	//for (Arc arc : arcs)
		/*{
			if ((sommet.getIdentifiant() == arc.getSommetDepart()->getIdentifiant()) && (arc.getDistance() < vehicule.getAutonomieActuelle()))
			{
				sousGraph.sommets.push_back(sommet);
				sousGraph.arcs.push_back(arc);
				vehicule.autonomieRestante(arc.getDistance());
				if ((arc.getSommetArrive()->getType() == vehicule.getType()) || ((vehicule.getType() == "hybrid") && (arc.getSommetArrive()->getType() != "null")) || (arc.getSommetArrive()->getType() == "multi"))
					vehicule.rechargerAutonomie();
			}
		}*/
		return sousGraph;
}



