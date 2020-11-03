#ifndef VEHICULE_H
#define VEHICULE_H
#include <iomanip>
#include <iostream>
#include <fstream>

struct Caracteristiques {
	std::string carburant;
	int autonomieMax = 0;
	int coefficientPerte = 1;
};

class Vehicule {
public:
	Vehicule() :type_(""), autonomieMaximale_(0), coefficientPerte_(1) {};
	Vehicule(Caracteristiques caracteristique) :type_(caracteristique.carburant), autonomieMaximale_(caracteristique.autonomieMax), coefficientPerte_(caracteristique.coefficientPerte) {};
	Vehicule(std::string type, int autonomieMaximale, int coefficientPerte) : type_(type), autonomieMaximale_(autonomieMaximale), coefficientPerte_(coefficientPerte) {};
	int getCoefficientPerte() { return coefficientPerte_; };
	std::string getType() { return type_; };
	int getAutonomieDepart() { return autonomieDepart_; };
	void setAutonomieDepart(int autonomieDepart) { autonomieDepart_ = autonomieDepart; };
private: 
	std::string type_;
	int autonomieMaximale_=0;
	int autonomieDepart_ = 100;
	int coefficientPerte_= 1;

};
#endif