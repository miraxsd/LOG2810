#include "Lexique.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

	bool exit = false;
	char choix;
	string nomNouveauFichier;
	string nomFichier;
	ifstream fichier;
	ifstream nouveauFichier;
	Lexique lexique;
	std::map<std::string, std::set<std::string>> mapAutomate;
	bool invalide = false;

	// bool qui permet de verifier si option 1 a été choisi avant
	bool option1choisie = false;

	while (exit == false) {
		std::cout << 
			"1. Initialisation du jeu \n"
			"2. Partie contre l'ordinateur \n"
			"3. Deux joueurs \n"
			"4. Quitter \n";

		std::cout << '\n';
		cin >> choix;
		invalide = false;
		switch (choix) {
		case '1':
		
			do {
				if (invalide)
					cout << "le fichier " << nomNouveauFichier << " est introuvable." << endl;
				cout << "Veuillez entrer le nom du fichier contenant le nouveau lexique : " << endl << endl;
				invalide = true;
				cin >> nomNouveauFichier;
				std::cout << endl;
				nouveauFichier.open(nomNouveauFichier + ".txt");
			} while (!nouveauFichier.is_open());
			//pour eviter que les lexiques s'accumulent entre eux
			lexique.effacerListeMots();
			lexique.effacerAutomate();
			mapAutomate = lexique.creerLexique(nomNouveauFichier);
			std::cout << "le jeu a ete initialise et le lexique a ete produit";
			option1choisie = true;
			std::cout << std::endl << endl;
			break;

		case '2':
			if (option1choisie == false) {
				std::cout << "Vous devez initialiser le jeu avant de lancer la partie \n \n";
				break;
			}
			else {
				std::cout << "La partie contre l'ordinateur se lance !" << std::endl << std::endl;
				lexique.modeAuto();
			}
			break;
		case '3':
			if (option1choisie == false) {
				std::cout << "Vous devez initialiser le jeu avant de lancer la partie \n \n";
				break;
			}
			else {
				std::cout << "La partie a deux joueurs se lance !" << std::endl << std::endl;
				lexique.modeVersus();
			}
			break;
		case '4':
		{
			exit = true;
			cout << endl;
			break;
		}

		default:
			std::cout << "choix invalide, veuillez entrer un choix parmi ceux disponibles: " << endl << endl;
		}
	}

}