/////////////////////////////////////////////////////////////////////////
// Lexique.cpp                                                         //
// Ce fichier contient l'implémentation des méthodes du Lexique.h      //
// Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa                   //
/////////////////////////////////////////////////////////////////////////
#include "Lexique.h"


// Cette méthode extrait tous les mots dans le fichier txt dont le nom est 
// mis en paramètre et les ajoute dans la liste de mots listeMots_.
void Lexique::extraireLexique(std::string nomFichier) {
	std::ifstream fichier(nomFichier + ".txt", std::ifstream::in);
	std::string mot = "";
	while (!fichier.eof()) {
		getline(fichier, mot);
		listeMots_.push_back(mot);
	}
}

// Cette méthode vide la listeMots
void Lexique::effacerListeMots() {
	listeMots_.clear();
}

// Cette méthode vide automate_.
void Lexique::effacerAutomate() {
	automate_.clear();
}

// Cette méthode se charge de créer le lexique en faisant appelle à la méthode extraireLexique(std::string nomFichier) 
// Ensuite, elle prend chaque mot du lexique et l’insère dans les éléments(listes des mots) de la Map(automate_) 
// dont les clefs sont des sous chaîne(première partie) du mot à insérer.
std::map<std::string, std::set<std::string>> Lexique::creerLexique(std::string nomFichier) {

	extraireLexique(nomFichier);
	auto iterateur = automate_.end();

	// Pour chaque mot de la liste 
	for (std::string mot : listeMots_)
	{
		// On parcourt 
		for (int i = 1; i <= mot.length(); i++)
		{
			// On part du debut du mot et on prend la chaine de longueur i à partir de ce début
			// On insère cette chaîne 
			automate_[mot.substr(0, i)].insert(mot);
		}
	}
	return automate_;
}

// Cette méthode retourne un booléen indiquant si un mot est contenu dans un lexique.
bool Lexique::contientMot(std::string motRecherche) {

	// Retourne iterateur qui se trouve a la position du mot recherché
	auto iterateur = automate_.find(motRecherche);

	if (iterateur != automate_.end()) {
		// Si la valeur du mot qu'on cherche est présente dans l'automate, on retourne vrai 
		if (iterateur->second.count(motRecherche) != 0)
			return true;
	}
	return false;
}



// Cette méthode retourne un set  composé des mots suggérés par le lexique. Ces mots commencent par la partie du mot précisé par 
// la clé et sont contenus dans sa liste des mots.
std::set<std::string> Lexique::trouverSuggestions(std::string motRecherche) {
	auto iter = automate_.find(motRecherche);
	if (iter != automate_.end())
		return automate_.find(motRecherche)->second;
	else
		return std::set<std::string>();
}


// Cette méthode retourne le nombre d'erreurs contenus dans la proposition
int Lexique::creerVerif(std::string motSecret, std::string proposition) {
	int erreurs = 0;
	for (int i = 0; i < proposition.length(); i++)
		if (motSecret[i] != proposition[i])
			erreurs++;
	return erreurs;
}


//------------AFFICHAGE -----------------------
// Cette méthode affiche les éléments de la map ( de l’automate) ainsi que les listes 
// des mots qui leurs correspondent. Elle nous a servi pour vérifier le bon fonctionnement du code

void Lexique::printMap()
{
	for (auto const& pair : automate_) {
		std::cout << "key : " << pair.first << std::endl;

		std::cout << "valeurs que la key contient : ";

		for (auto itr = pair.second.begin(); itr != pair.second.end(); itr++) {
			std::cout << *itr << " ";
		}
		std::cout << std::endl;
	}
}

