#pragma once
#ifndef LEXIQUE_H
#define LEXIQUE_H 
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

const int NB_ESSAIS_MAX = 15;

class Lexique {

public :

	std::vector<std::string> extraireLexique(std::string nomFichier);

	//std::map<std::string, std::set<std::string>> creerLexique(std::string nomFichier);

	std::map<std::string, std::set<std::string>> creerAutomate(/*std::vector<std::string> listeMots*/);

	void modeAuto(std::vector<std::string> listeMots);

	void modeVersus();

	bool contientMot(/*std::map<std::string, std::set<std::string>> automate,*/ std::string motRecherche);

	std::set<std::string> trouverSuggestions(/*std::map<std::string, std::set<std::string>> automate,*/ std::string motRecherche);

	int creerVerif(std::string motSecret, std::string proposition);

	void printMap(/*std::map<std::string, std::set<std::string>> automate*/);

	void effacerListeMots();

	void effacerAutomate();

private:

	std::vector<std::string> listeMots_;

	std::map<std::string, std::set<std::string>> automate_;

};


#endif