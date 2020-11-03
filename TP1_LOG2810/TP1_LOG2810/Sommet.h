/////////////////////////////////////////////////////////////////////////////////////////////////
// Sommet.h
// Ce fichier contient la définiton de la classe Sommet
//Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SOMMET_H
#define SOMMET_H
#include <iomanip>
#include <iostream>
#include <fstream>

class Sommet {
public:
	//Constructeur par paramètres qui permet de créer un objet de type Sommet.
	Sommet(std::string identifiant, std::string type):identifiant_(identifiant),type_(type){};

	//Méthode d’accès à l'attribut identifiant_
	std::string getId(){return identifiant_;};

	//Méthode d’accès à l’attribut type_.
	std::string getType(){return type_;};
private :
	std::string identifiant_;
	std::string type_;

};
#endif

