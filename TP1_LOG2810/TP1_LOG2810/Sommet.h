#ifndef SOMMET_H
#define SOMMET_H
#include <iomanip>
#include <iostream>
#include <fstream>

class Sommet {
public:
	Sommet(std::string identifiant, std::string type):identifiant_(identifiant),type_(type){};
	std::string getId(){return identifiant_;};
	std::string getType(){return type_;};
private :
	std::string identifiant_;
	std::string type_;

};
#endif