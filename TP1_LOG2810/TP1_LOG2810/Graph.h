#define GRAPH_H 
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sommet.h"
#include "Arc.h"
#include "Voiture.h"

class Graph {
public:
	Graph creerGraph (std::string);
	void lireGraph();
	Graph extractionGraph(Voiture);
private:
	std::vector<Sommet> sommets;
	std::vector<Arc> arcs;
};