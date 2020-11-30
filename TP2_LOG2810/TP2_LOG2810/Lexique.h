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

std::vector<std::string> extraireLexique(std::string nomFichier);

std::map<std::string, std::set<std::string>> creerLexique(std::string nomFichier);

std::map<std::string, std::set<std::string>> creerAutomate(std::vector<std::string> listeMots);

bool contientMot(std::map<std::string, std::set<std::string>> automate, std::string motRecherche);

std::set<std::string> trouverSuggestions(std::map<std::string, std::set<std::string>> automate, std::string motRecherche);

int creerVerif(std::string motSecret, std::string proposition);

#endif