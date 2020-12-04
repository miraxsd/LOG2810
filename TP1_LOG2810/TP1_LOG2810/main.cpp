/////////////////////////////////////////////////////////////////////////////////////////////////
// main.cpp
// Ce fichier contient le code qui sera exécuté lorsque l'utilisateur utilisera le programme
//Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa
////////////////////////////////////////////////////////////////////////////////////////////////

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vehicule.h"

using namespace std;


// Fonction qui permet de demander les caractéristiques du véhicule 
// de l'utilisateur et qui retourne celui-ci. 
Vehicule demanderCaracteristiques() {

	Caracteristiques caracteristique;
	bool carburantPossible = true;
	do {
		//On demande le type de carburant
		std::cout << "Type de carburant (essence, elec ou hybrid) : ";
		cin >> caracteristique.carburant;
		carburantPossible = true;
		if (caracteristique.carburant != "essence" && caracteristique.carburant != "hybrid" && caracteristique.carburant != "elec") {
			std::cout << "Votre carburant n'est pas pris en charge par le systeme \n";
			carburantPossible = false;
		}
	} while (carburantPossible == false);

	// On demande l'autonomie max
	std::cout << "Autonomie maximale (entier naturel positif) : ";
	cin >> caracteristique.autonomieMax;

	// On demande le coefficient de perte
	std::cout << "Coefficient de perte (entier naturel positif de 0 a 100) : ";
	cin >> caracteristique.coefficientPerte;

	std::cout << std::endl;

	Vehicule vehicule(caracteristique);
	return vehicule;
}

void menuPrincipal() {

	bool exit = false;
	char choix;
	string nomNouveauFichier;
	string nomFichier;
	ifstream fichier;
	ifstream nouveauFichier;
	Graph graph;
	Graph graphDoubleSens;
	Vehicule vehicule;
	bool invalide = false;

	// bool qui permet de verifier si A a été choisi avant
	bool choixAchoisi = false;

	// bool qui permet de verifier si la carte a été générée
	bool carteExiste = false;

	while (exit==false) {
		std::cout << "(a) Demander les caracteristiques du vehicule \n"
			"(b) Mettre a jour la carte \n"
			"(c) Extraire un sous-graphe \n"
			"(d) Determiner le plus court chemin \n"
			"(e) Quitter \n";

		std::cout << '\n';
		cin >> choix;
		invalide = false;
		switch (choix) {
		case 'a':
		case'A':
			choixAchoisi = true;
			vehicule = demanderCaracteristiques();
			break;

		case 'b':
		case'B':
			do {
				if (invalide)
					cout << "le fichier " << nomNouveauFichier << " est introuvable." << endl;
				cout << "Veuillez entrer le nom du fichier contenant la nouvelle carte: " << endl << endl;
				invalide = true;
				cin >> nomNouveauFichier;
				std::cout << endl;
				nouveauFichier.open(nomNouveauFichier);
			} while (!nouveauFichier.is_open());
			graphDoubleSens=graph.creerGraph(nouveauFichier);
			graph.lireGraph();
			carteExiste = true;
			std::cout << std::endl << endl;
			break;

		case 'c':
		case'C': 
			if (choixAchoisi == false) {
				std::cout << "Vous devez choisir les caracteristiques du vehicule avant d'extraire le sous-graphe \n \n";
				break;
			}
			if (carteExiste == false) {
				std::cout << "Vous devez generer la carte \n \n";
				break;
			}
			else {

				std::string indiceSommet = "";
				std::cout << "Veuillez indiquer l'indice du sommet afin d'extraire le sous-graphe qui contient le chemin le plus long \n \n";
				cin >> indiceSommet;
				while (graph.trouverSommet(indiceSommet).getId() == "inexistant")
				{
					std::cout << "Il faut un indice valide \n \n";
					cin >> indiceSommet;
				}
					Graph sousGraphe = graph.extractionGraph(graph.trouverSommet(indiceSommet), vehicule);
					break;
			
		}
			break;
		case'd':
		case 'D':
			
			if (choixAchoisi == false) {
				std::cout << "Vous devez choisir les caracteristiques du vehicule avant de trouver le plus court chemin \n \n";
				break;
			}
			if (carteExiste == false) {
				std::cout << "Vous devez generer la carte \n \n";
				break;
			}
			else {
				std::cout << "Voici le graphe oriente dans les deux sens : \n \n";

				//Cela permet d'afficher le graph orienté dans les deux sens
				graphDoubleSens.lireGraph();

				std::cout << endl << endl;

				std::string indiceDepart = "";
				std::cout << "Veuillez entrer l'indice (lettre) du sommet de depart \n";
				cin >> indiceDepart;
				while (graph.trouverSommet(indiceDepart).getId() == "inexistant")
				{
						std::cout << "Il faut un indice valide \n \n";
						cin >> indiceDepart;
					}

					std::string indiceArrive = "";
					std::cout << "Veuillez entrer l'indice (lettre) du sommet d'arrive \n";
					cin >> indiceArrive;
					while (graph.trouverSommet(indiceArrive).getId() == "inexistant")
					{
						std::cout << "Il faut un indice valide \n \n";
						cin >> indiceArrive;
				}

				std::cout << endl << endl;

				//On appelle la méthode du plus court chemin sur le graph orienté dans les deux sens
				graphDoubleSens.plusCourtChemin(graphDoubleSens.trouverSommet(indiceDepart), graphDoubleSens.trouverSommet(indiceArrive), vehicule);
				break;
			}

		break;
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


	//On appelle la fonction principale qui est celle du menu principal
	menuPrincipal();

}