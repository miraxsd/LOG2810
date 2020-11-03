/////////////////////////////////////////////////////////////////////////////////////////////////
// Vehicule.h
// Ce fichier contient la définiton de la classe Vehicule
//Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa
///////////////////////////////////////////////////////////////////////////////////////////////
#ifndef VEHICULE_H
#define VEHICULE_H
#include <iomanip>
#include <iostream>
#include <fstream>


//Cette structure représente les caractéristiques du véhicule. Ces caractéristique sont carburant
//(type du carburant), automieMax (autonomie maximale) et coefficientPerte.
struct Caracteristiques {
	std::string carburant;
	int autonomieMax = 0;
	int coefficientPerte = 1;
};

class Vehicule {
public:
	// Constructeur par défaut qui nous permet de construire un objet de type Vehicule.
	Vehicule() :type_(""), autonomieMaximale_(0), coefficientPerte_(1) {};

	//Constructeur par paramètre qui permet de créer un objet de type Véhicule en prenant en paramètre des caractéristique de type Caractéristiques.
	Vehicule(Caracteristiques caracteristique) :type_(caracteristique.carburant), autonomieMaximale_(caracteristique.autonomieMax), coefficientPerte_(caracteristique.coefficientPerte) {};

	//Constructeur par paramètre qui permet de créer un objet de type Véhicule.
	Vehicule(std::string type, int autonomieMaximale, int coefficientPerte) : type_(type), autonomieMaximale_(autonomieMaximale), coefficientPerte_(coefficientPerte) {};

	//Méthode d’accès à l'attribut coefficientPerte_
	int getCoefficientPerte() { return coefficientPerte_; };

	//Méthode d’accès à l'attribut type_ 
	std::string getType() { return type_; };

	//Méthode d’accès à l'attribut autonomieDepart_
	int getAutonomieDepart() { return autonomieDepart_; };

	//Méthode qui permet de modifier l’autonomieDepart_ du vehicule en lui attribuant l’autonomie mise en paramètre
	void setAutonomieDepart(int autonomieDepart) { autonomieDepart_ = autonomieDepart; };
private: 
	std::string type_;
	int autonomieMaximale_=0;
	int autonomieDepart_ = 100;
	int coefficientPerte_= 1;

};
#endif