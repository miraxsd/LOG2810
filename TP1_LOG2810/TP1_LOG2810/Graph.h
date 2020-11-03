/////////////////////////////////////////////////////////////////////////////////////////////////
// Graph.h
// Ce fichier contient la définiton de la classe Graph
//Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa
/////////////////////////////////////////////////////////////
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
	//Constructeur par défaut qui permet d’initialiser un objet de type Graphe avec un vecteur de sommets et un vecteur d’arcs vides.
	Graph() :sommets(std::vector<Sommet>()), arcs(std::vector<Arc>()) {};

	//Cette méthode prend en paramètre le fichier à partir duquel elle extrait les sommets et les arcs du graphe. Elle retourne dans l’objet courant un graphe
	//unidirectionnel et renvoie un graphe bidirectionnel comme valeur de retour.
	Graph creerGraph (std::ifstream&);

	//La fonction trouverSommet trouve le sommet associé à l'indice mis en paramètre.Elle retourne le sommet si il est trouvé ou null dans le cas écheant.
	Sommet trouverSommet(std::string indice);

	//Cette méthode permet d’afficher l’objet Graph courant sous la forme exigée dans l’énoncé du TP
	void lireGraph();

	// Méthode qui permet d'extraire et afficher le plus long chemin que le vehicule peut parcourir selon son autonomie sans la recharger.
	Graph extractionGraph(Sommet,Vehicule);

	//Méthode qui permet d'afficher le plus court chemin entre deux sommets en tenant compte de l'autonomie du vehicule et les stations de recharges dans les sommets.
	void plusCourtChemin (Sommet,Sommet, Vehicule&);
private:
	std::vector<Sommet> sommets;
	std::vector<Arc> arcs;
};
#endif

