#ifndef GRAPHE_H
#define GRAPH_H 

#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sommet.h"
#include "Arc.h"
#include "Vehicule.h"

class Graph {
public:
	Graph() :sommets(std::vector<Sommet>()), arcs(std::vector<Arc>()) {};
	Graph creerGraph (std::ifstream&);
	void lireGraph();
	Graph extractionGraph(Sommet,Vehicule);
private:
	std::vector<Sommet> sommets;
	std::vector<Arc> arcs;
};
#endif

