#ifndef VEHICULE_H
#define VEHICULE_H
#include <iomanip>
#include <iostream>
#include <fstream>

struct Caracteristiques {
	std::string carburant;
	int autonomieMax = 0;
	int autonomieActu = 0;
	int coefficientPerte = 1;
};

class Vehicule {
public:
	Vehicule() :type_(""), autonomieMaximale_(0), autonomieActuelle_(0), coefficientPerte_(1){};
	Vehicule(Caracteristiques caracteristique) :type_(caracteristique.carburant), autonomieMaximale_(caracteristique.autonomieMax), autonomieActuelle_(caracteristique.autonomieActu), coefficientPerte_(caracteristique.coefficientPerte){};
	Vehicule(std::string type, int autonomieMaximale, int autonomieActuelle, int coefficientPerte) : type_(type), autonomieMaximale_(autonomieMaximale), autonomieActuelle_(autonomieActuelle), coefficientPerte_(coefficientPerte) {};
	int getAutonomieMaximale() { return autonomieMaximale_; };
	int getAutonomieActuelle() { return autonomieActuelle_; };
	int getCoefficientPerte() { return coefficientPerte_; };
	std::string getType() { return type_; };
	void setType(std::string type) { type_ = type; };
	void setAutonomieActuelle(int autonomieActuelle) {
		autonomieActuelle_ = autonomieActuelle;
	};
	void rechargerAutonomie() { setAutonomieActuelle(autonomieMaximale_); };
	int autonomieRestante(int distanceParcourue) {
		autonomieActuelle_ -= coefficientPerte_*distanceParcourue;
		return autonomieActuelle_;
	};
private: 
	std::string type_;
	int autonomieMaximale_=0;
	int autonomieActuelle_=0;
	int coefficientPerte_= 1;

};
#endif