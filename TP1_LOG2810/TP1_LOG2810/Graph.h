#define GRAPH_H 
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sommet.h"
#include "Arc.h"
class Graph {
public:
	Graph creerGraph (std::ifstream fichier);

private:
	std::vector<Sommet> sommets;
	std::vector<Arc> arcs;
};