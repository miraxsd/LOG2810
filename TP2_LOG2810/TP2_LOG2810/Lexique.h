////////////////////////////////////////////////////////////
//	Lexique.h                                             //
// Ce fichier contient la définiton de la classe Lexique  //
// Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa	  //
////////////////////////////////////////////////////////////
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
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cctype>		/* isalpha */
#include <iterator>


const int NB_ESSAIS_MAX = 15;

class Lexique {

public:

	void extraireLexique(std::string nomFichier);

	std::map<std::string, std::set<std::string>> creerLexique(std::string nomFichier);

	void partie2(std::string motSecret);

	void modeAuto();

	void modeVersus();

	bool contientMot(std::string motRecherche);

	std::set<std::string> trouverSuggestions(std::string motRecherche);

	int creerVerif(std::string motSecret, std::string proposition);

	void printMap();

	void effacerListeMots();

	void effacerAutomate();

private:

	// Un vecteur qui contient tous les mots du lexique
	std::vector<std::string> listeMots_;

	// Une map dont chaque élément a comme clef la première partie d'un mot en String.
	// Pour chaque clef (première partie d'un mot) correspond une liste des mots qui commencent par la partie du mot dans la clef.
	std::map<std::string, std::set<std::string>> automate_;

};
#endif