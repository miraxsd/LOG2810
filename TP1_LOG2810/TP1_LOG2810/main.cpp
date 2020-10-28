#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vehicule.h"

using namespace std;


Vehicule demanderCaracteristiques() {

	Caracteristiques caracteristique;
	bool carburantPossible = true;
	do {
		std::cout << "Type de carburant : ";
		cin >> caracteristique.carburant;
		carburantPossible = true;
		if (caracteristique.carburant != "essence" && caracteristique.carburant != "hybride" && caracteristique.carburant != "electricite") {
			std::cout << "Votre carburant n'est pas pris en charge par le systeme \n";
			carburantPossible = false;
		}
	} while (carburantPossible == false);

	std::cout << "Autonomie maximale : ";
	cin >> caracteristique.autonomieMax;

	std::cout << "Autonomie actuelle : ";
	cin >> caracteristique.autonomieActu;
	Vehicule vehicule(caracteristique);
	return vehicule;
}

void lireCaracteristique (Caracteristiques caracteristique){
	
	//Voir cmt utiliser les caracteristiques qu'on donne

}

void menuPrincipal() {

	bool exit = false;
	char choix;
	string nomNouveauFichier;
	string nomFichier;
	ifstream fichier;
	ifstream nouveauFichier;
	bool invalide = false;
	bool choixAchoisi = true;

	while (exit==false) {
		std::cout << "(a) Demander les caracteristiques du vehicule \n"
			"(b) Mettre a jour la carte \n"
			"(c) Adapter la carte aux caracteristiques\n"
			"(d) Determiner le plus court chemin \n"
			"(e) Quitter \n";

		std::cout << '\n';
		cin >> choix;
		invalide = false;
		Graph graph;
		Vehicule vehicule;
		switch (choix) {
		case 'a':
		case'A':
			choixAchoisi = true;
			vehicule= demanderCaracteristiques();
			//fct qui lit une carac...
			//lireCaracteristique(caracFournie);
			break;
		case 'b':
		case'B':
			do {
				if (invalide)
					cout << "le fichier " << nomNouveauFichier << " est introuvable." << endl;
				cout << "Veuillez entrer le nom du fichier contenant la nouvelle carte: " << endl << endl;
				invalide = true;
				cin >> nomNouveauFichier;
				nouveauFichier.open(nomNouveauFichier);
			} while (!nouveauFichier.is_open());
			graph.creerGraph(nouveauFichier);
			break;

		case 'c':
		case'C': {
			if (choixAchoisi == false) {

				int pointDepart = 0, pointArrivee = 0;
				//-----------------//

			}
			else {
				std::cout << "Vous devez choisir les caracteristiques du vehicule avant d'adapter la carte \n \n";
				break;
			}
			
		}

		case'd':
		case 'D':{
			//appeller determiner le chemin le plus court
		}

		case'e':
		case'E': {
			exit = true;
			cout << endl;
			break;
		}
		

		default:
			std::cout << "choix invalide, veuillez entrer un choix parmi ceux disponibles: " << endl << endl;
		}
	}
}

int main() {

	//menuPrincipal();
	Vehicule vehicule("hybrid",600,100, 10);
	string nomFichier = "graphe.txt";
	ifstream fichier;
	fichier.open(nomFichier);

	Graph graph;
	Graph graphDoubleSens;
	graphDoubleSens=graph.creerGraph(fichier);
	/*graphDoubleSens.lireGraph();
	graphDoubleSens.plusCourtChemin(Sommet("U", "essence"), Sommet("A", "essence"), vehicule);*/
	graph.lireGraph();
	cout << std::endl;
	/*graph.plusCourtChemin(Sommet("U", "essence"), Sommet("A", "essence"), vehicule);*/
	graphDoubleSens = graph.extractionGraph(Sommet("C", "rien"), vehicule);
	std::cout << std::endl;
	graphDoubleSens.lireGraph();
}