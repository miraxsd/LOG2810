#include "Lexique.h"

std::vector<std::string> Lexique::extraireLexique(std::string nomFichier) {
	std::ifstream fichier(nomFichier + ".txt", std::ifstream::in);
	std::string mot = "";
	std::vector<std::string> listeMots;
	while (!fichier.eof()) {
		getline(fichier, mot);
		listeMots.push_back(mot);
	}
	return listeMots;
}
std::map<std::string, std::set<std::string>> Lexique::creerLexique(std::string nomFichier){
	return creerAutomate(extraireLexique(nomFichier));
}


std::map<std::string, std::set<std::string>> Lexique::creerAutomate(std::vector<std::string> listeMots) {
	std::map<std::string, std::set<std::string>> automate;
	auto iterateur = automate.end();

	//pour chaque mot de la liste 
	for (std::string mot : listeMots)
	{
		//on parcourt 
		for (int i = 1; i <= mot.length(); i++)
		{   
			//on part du debut du mot et on prend la chaine de longueur i à partir de ce début
			//on insert cette chaîne 
			automate[mot.substr(0, i)].insert(mot);
		}
	}
	return automate;
}


bool Lexique::contientMot(std::map<std::string, std::set<std::string>> automate, std::string motRecherche) {
	//retourne iterateur qui se trouve a la position du mot recherché
	auto iterateur = automate.find(motRecherche);
	//si la valeur du mot qu'on cherche est présente dans l'automate, on retourne vrai 
	if(iterateur->second.count(motRecherche)!= 0)
			return true;
	return false;
}

/*bool contientmot(std::vector<std::string> listeMots,std::string motRecherche) {
	for (std::string mot : listeMots)
		if (mot == motRecherche)
			return true;
	return false;
}*/


std::set<std::string> Lexique::trouverSuggestions(std::map<std::string, std::set<std::string>> automate, std::string motRecherche) {
	return automate.find(motRecherche)->second;
}
/*std::vector<std::string> trouverSuggestions(std::vector<std::string> listeMots, std::string motRecherche) {
	std::vector<std::string> listeSuggestions;
	for (std::string mot : listeMots)
		if (motRecherche.length() < mot.length())
			if (mot.substr(0, mot.length()) == motRecherche)
				listeSuggestions.push_back(mot);
	return listeSuggestions;
}*/

//on compte les erreurs
int Lexique::creerVerif(std::string motSecret, std::string proposition) {
	int erreurs = 0;
	for (int i = 0; i < proposition.length() ;i++)
		if (motSecret[i] != proposition[i])
			erreurs++;
	return erreurs;
}


//------------AFFICHAGE -----------------------

void Lexique::printMap(std::map<std::string, std::set<std::string>> automate)
{
	for (auto const& pair : automate) {
		std::cout << "key : " << pair.first << std::endl;

		std::cout << "valeurs que la key contient : ";
		
		for (auto itr = pair.second.begin(); itr != pair.second.end(); itr++ ) {
			std::cout << *itr << " "; 
		}
		std::cout << std::endl;
	}
}

