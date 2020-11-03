/////////////////////////////////////////////////////////////////////////////////////////////////
// Arc.h
// Ce fichier contient la définiton de la classe Arc
//Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa
////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ARC_H
#define ARC_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include "Sommet.h"
class Arc {
public:
	// Constructeur par paramètre qui permet de créer un objet de type Arc.
	Arc(Sommet* sommetDepart, Sommet* sommetArrive, int distance) :sommetDepart_(sommetDepart),sommetArrive_(sommetArrive),distance_(distance) {};

	//Méthode d’accès à l'attribut sommetDepart_ 
	Sommet* getSommetDepart(){return sommetDepart_;};

	//Méthode d’accès à l'attribut sommetArrive_
	Sommet* getSommetArrive(){return sommetArrive_;};

	//Méthode d’accès à l'attribut distance_
	int getDistance() { return distance_; };
private:
	
	Sommet* sommetDepart_;
	Sommet* sommetArrive_;
	int distance_;
};
#endif
