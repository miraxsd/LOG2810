#ifndef VEHICULE_H
#define VEHICULE_H
#include <iomanip>
#include <iostream>
#include <fstream>

struct Caracteristiques {
	std::string carburant;
	int autonomieMax = 0;
	int autonomieActu = 0;
};

class Vehicule {
public:
	Vehicule() :type_(""), autonomieMaximale_(0), autonomieActuelle_(0) {};
	Vehicule(Caracteristiques caracteristique) :type_(caracteristique.carburant), autonomieMaximale_(caracteristique.autonomieMax), autonomieActuelle_(caracteristique.autonomieActu) {};
	Vehicule(std::string type, int autonomieMaximale, int autonomieActuelle) : type_(type), autonomieMaximale_(autonomieMaximale), autonomieActuelle_(autonomieActuelle) {};
	int getAutonomieMaximale() { return autonomieMaximale_; };
	int getAutonomieActuelle() { return autonomieActuelle_; };
	std::string getType() { return type_; };
	void setType(std::string type) { type_ = type; };
	void setAutonomieActuelle(int autonomieActuelle) {
		autonomieActuelle_ = autonomieActuelle;
	};
	void rechargerAutonomie() { setAutonomieActuelle(autonomieMaximale_); };
	int autonomieRestante(int distanceParcourue) {
		autonomieActuelle_ -= distanceParcourue;
		return autonomieActuelle_;
	};
private: 
	std::string type_;
	int autonomieMaximale_=0;
	int autonomieActuelle_=0;
	

};
#endif