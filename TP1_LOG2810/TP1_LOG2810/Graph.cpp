#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Graph Graph::creerGraph(std::string nomFichier)
{
	std::ifstream fichier;
	fichier.open(nomFichier + "txt");
	std::string ligne1 = "";
	std::string ligne2 = "";
	if (fichier.is_open())
	{
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
			getline(line2, identifiantSommetDepart, ',');
			getline(line2, identifiantSommetArrive, ',');
			getline(line2,distance,';');
			arcs.push_back(Arc(identifiantSommetDepart,identifiantSommetArrive,std::stoi(distance)));
		}
		fichier.close();
	}
	else std::cout << "Unable to open file";

	return *this;
}
void Graph::lireGraph()
{
	for (Sommet sommet:sommets)
	{
		std::cout <<"(" << sommet.getIdentifiant() << ", " << sommet.getType() << "( ";
		for(Arc arc:arcs)
			{
			if (sommet.getIdentifiant() == arc.getSommetDepart())
				std::cout << arc.getSommetArrive();
				if (arc.getSommetArrive()!=arcs.back().getSommetArrive())
					std::cout << ", ";
			}
		std::cout << "))" << std::endl;
	}
	
}

Graph Graph::extractionGraph( Voiture voiture )
{
	Graph sousGraph;
	for (Sommet sommet:sommets)
	{
		for(Arc arc:arcs)
			{
				if ((sommet.getIdentifiant() == arc.getSommetDepart()) && (arc.getDistance() < voiture.getAutonomieMaximale()))
				{
					sousGraph.sommets.push_back(sommet);
					sousGraph.arcs.push_back(arc);
				}
	}
		return sousGraph;
}

