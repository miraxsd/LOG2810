#define VOITURE_H
#include <iomanip>
#include <iostream>
#include <fstream>
class Voiture {
public:
	Voiture(std::string type,int autonomieMaximale,int autonomieActuelle) :  type_(type),autonomieMaximale_(autonomieMaximale),autonomieActuelle_(autonomieActuelle) {};
	int getAutonomieMaximale() { return autonomieMaximale_; };
	int getAutonomieActuelle() { return autonomieActuelle_; };
	std::string getType() { return type_; };
	void setAutonomieActuelle(int autonomieActuelle) {
		autonomieActuelle_ = autonomieActuelle;
	};
	int autonomieRestante(int distanceParcourue) {
		autonomieActuelle_ -= distanceParcourue;
		return autonomieActuelle_;
	};
private: 
	std::string type_;
	int autonomieMaximale_;
	int autonomieActuelle_;
	

};
