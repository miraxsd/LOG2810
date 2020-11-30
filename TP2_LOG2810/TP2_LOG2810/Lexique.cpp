#include "Lexique.h"

std::vector<std::string> extraireLexique(std::string nomFichier) {
	std::ifstream fichier(nomFichier + ".txt", std::ifstream::in);
	std::string mot = "";
	std::vector<std::string> listeMots;
	while (!fichier.eof()) {
		getline(fichier, mot);
		listeMots.push_back(mot);
	}
	return listeMots;
}
std::map<std::string, std::set<std::string>> creerLexique(std::string nomFichier){
	return creerAutomate(extraireLexique(nomFichier));
}
std::map<std::string, std::set<std::string>> creerAutomate(std::vector<std::string> listeMots) {
	std::map<std::string, std::set<std::string>> automate;
	auto iterateur = automate.end();
	for (std::string mot : listeMots)
	{
		for (int i = 1; i < mot.length(); i++)
		{
			automate[mot.substr(0, i)].insert(mot);
		}
	}
	return automate;
}
bool contientMot(std::map<std::string, std::set<std::string>> automate, std::string motRecherche) {
	auto iterateur = automate.find(motRecherche);
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
std::set<std::string> trouverSuggestions(std::map<std::string, std::set<std::string>> automate, std::string motRecherche) {
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
int creerVerif(std::string motSecret, std::string proposition) {
	int erreurs = 0;
	for (int i = 0; i < proposition.length() ;i++)
		if (motSecret[i] != proposition[i])
			erreurs++;
	return erreurs;
}

