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
		std::cout << "Type de carburant (essence, elec ou hybrid) : ";
		cin >> caracteristique.carburant;
		carburantPossible = true;
		if (caracteristique.carburant != "essence" && caracteristique.carburant != "hybrid" && caracteristique.carburant != "elec") {
			std::cout << "Votre carburant n'est pas pris en charge par le systeme \n";
			carburantPossible = false;
		}
	} while (carburantPossible == false);

	std::cout << "Autonomie maximale (entier naturel positif) : ";
	cin >> caracteristique.autonomieMax;

	std::cout << "Coefficient de perte (entier naturel positif de 0 a 100) : ";
	cin >> caracteristique.coefficientPerte;

	std::cout << std::endl;

	//cin >> caracteristique.autonomieActu;
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
	Graph graph;
	Graph graphDoubleSens;
	Vehicule vehicule;
	bool invalide = false;
	bool choixAchoisi = false;
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
					graph.extractionGraph(graph.trouverSommet(indiceSommet), vehicule);
					break;
			
		}
			break;
		case'd':
		case 'D':
			//appeller determiner le chemin le plus court
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

				std::cout << "Le chemin le plus court qui evite de tomber en panne est : \n \n";
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

	menuPrincipal();

	/*Vehicule vehicule("hybrid",600,100, 10);
=======
	//menuPrincipal();
	Vehicule vehicule("hybrid",600, 10);
>>>>>>> 18b33e0f893befa71406108111681c2ab19be201
	string nomFichier = "graphe.txt";
	ifstream fichier;
	fichier.open(nomFichier);*/

	/*Graph graph;
	Graph graphDoubleSens;
	graphDoubleSens=graph.creerGraph(fichier);
	graphDoubleSens.lireGraph();
	graphDoubleSens.plusCourtChemin(Sommet("U", "essence"), Sommet("A", "essence"), vehicule);
	graph.lireGraph();
	cout << std::endl;
	graph.plusCourtChemin(Sommet("U", "essence"), Sommet("A", "essence"), vehicule);
	graphDoubleSens = graph.extractionGraph(Sommet("C", "rien"), vehicule);
	std::cout << std::endl;
	graphDoubleSens.lireGraph();*/
}