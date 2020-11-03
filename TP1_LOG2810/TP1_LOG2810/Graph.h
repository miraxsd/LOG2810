#ifndef GRAPHE_H
#define GRAPH_H 

#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sommet.h"
#include "Arc.h"
#include "Vehicule.h"

const int INFINI = 9999;
class Graph {
public:
	Graph() :sommets(std::vector<Sommet>()), arcs(std::vector<Arc>()) {};
	Graph creerGraph (std::ifstream&);
	Sommet trouverSommet(std::string indice);
	void lireGraph();
	//int getTailleSommets() { return sommets.size(); };
	Graph extractionGraph(Sommet,Vehicule);
	void plusCourtChemin (Sommet,Sommet, Vehicule&);
private:
	std::vector<Sommet> sommets;
	std::vector<Arc> arcs;
};
#endif

