///////////////////////////////////////////////////////////
//	Lexique.h                                            //
// Ce fichier contient la définiton de la classe Lexique   //
//Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa		 //
///////////////////////////////////////////////////////////
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

	void extraireLexique(std::string nomFichier);

	//std::map<std::string, std::set<std::string>> creerLexique(std::string nomFichier);

	std::map<std::string, std::set<std::string>> creerLexique(std::string nomFichier);

	void partie2(std::string motSecret);

	void modeAuto();

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