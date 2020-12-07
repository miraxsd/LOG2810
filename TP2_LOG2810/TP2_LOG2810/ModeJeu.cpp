/////////////////////////////////////////////////////////////////////////
// ModeJeu.cpp                                                         //
// Ce fichier contient l'implémentation des méthodes du Lexique.h qui  //
// décrivent les deux modes du jeu.                                    //
// Auteurs : Karim Gargouri, Omar Sadat, Samia Safaa                   //
/////////////////////////////////////////////////////////////////////////

#include "Lexique.h"


// Cette methode retourne un booléen indiquant si la phrase mise en parametre contient que des caracteres alphabetiques 
bool verifierAlpha(std::string phrase1) {
	for (char caractere : phrase1) {
		if (!(isalpha(caractere)))
			return false;
	}
	return true;
}

// Cette methode décrit la dexième partie du jeu ou l'utilisateur doit devinner le mot secret mis en paramètre
void Lexique::partie2(std::string motSecret) {

	// Annoncer le début de la deuxieme partie en affichant ce qui suit
	std::cout << "Le mot secret a ete choisi" << std::endl;

	std::cout << "La taille du mot secret est : " << motSecret.size() << std::endl;


	// Utilisateur essaye de trouver le mot
	std::string choixUtilisateur = "";

	int nbEssais = 0;

	int nbErreurs = 0;

	while (nbEssais < NB_ESSAIS_MAX) {

		std::cout << std::endl << "ESSAI " << nbEssais + 1 << std::endl;

		std::cout << "votre choix ?" << std::endl;

		std::cin >> choixUtilisateur;

		std::cout << std::endl;

		bool enLettreAlpha = false;
		// Regarder s'ils ont la meme longueur
		if (choixUtilisateur.size() == motSecret.size()) {

			// Regarder s'il y a les memes lettres
			enLettreAlpha = verifierAlpha(choixUtilisateur);
			if (enLettreAlpha == true) {
				// Si c'est le meme mot
				if (choixUtilisateur == motSecret) {
					std::cout << "Bravo !, vous avez trouve le mot en " << nbEssais + 1 << " essais";
					break;
				}
				// On dit que c pas le bon et on incremente le nb d'Essais
				else {
					std::cout << "Ce n'est pas le bon mot" << std::endl;
					nbErreurs = creerVerif(motSecret, choixUtilisateur);
					std::cout << "Le nombre d'erreurs est : " << nbErreurs << std::endl;
				}

			}
			else {
				std::cout << "Le mot contient des caracteres non-alphabetiques" << std::endl;
			}

		}
		else {
			std::cout << "Les mots n'ont pas la meme longueur" << std::endl;
		}

		nbEssais++;
	}
	if (nbEssais >= 15)
		std::cout << "Le nombre d'essais maximum a ete atteint,";
	std::cout << " le mot secret etait : " << motSecret;
	std::cout << std::endl << std::endl;
}


// Cette méthode décrit le mode auto. Dans ce mode le joueur joue contre l'ordinateur.
void Lexique::modeAuto() {

	// L'ordinateur choisit au hasard un mot secret dans le lexique
	srand(time(NULL));

	int indexSecret = rand() % (listeMots_.size());

	// On recupere le mot secret
	std::string motSecret = listeMots_[indexSecret];

	// Début de la deuxieme partie du jeu.

	partie2(motSecret);


}

// Cette méthode affiche la listeSuggestions mis en paramètre qui contient les mots suggérés existant dans le lexique
void afficherSuggestions(std::set<std::string> listeSuggestions) {

	if (listeSuggestions.empty())
		std::cout << "Aucune..." << std::endl;
	else
		std::copy(listeSuggestions.begin(), listeSuggestions.end(),
			std::ostream_iterator<std::string>(std::cout, "\n"));
}

// Cette méthode décrit le mode versus.
void Lexique::modeVersus() {

	// Annoncer le début de la première partie
	std::cout << "Premiere partie : Vous devez choisir le mot secret !" << std::endl << std::endl;

	bool motChoisi = false;
	bool motExiste = false;
	std::string motJoueur1 = "undefined";
	std::set<std::string> listeSuggestions;

	// Tant qu'on a pas choisi le mot
	while (motChoisi != true) {

		std::cout << std::endl;
		std::cout << ">Quel code ?" << std::endl;

		std::cout << "Reponse: ";
		std::cin >> motJoueur1;
		//std::cout << std::endl;

		motExiste = contientMot(motJoueur1);

		if (!motExiste)
			std::cout << "Ce mot n'existe pas dans le lexique" << std::endl; //<< std::endl;

		std::cout << std::endl << "Suggestion(s) : " << std::endl;

		listeSuggestions = trouverSuggestions(motJoueur1);
		afficherSuggestions(listeSuggestions);

		if (motExiste) {
			std::cout << std::endl << "Voulez-vous selectionner ce choix (1:oui / 0:non)" << std::endl
				<< "Reponse: ";
			std::cin >> motChoisi;

		}

	}

	std::cout << std::endl << std::endl;

	std::cout << "Le code selectionne est: " << motJoueur1 << std::endl << std::endl;

	std::cout << "Debut de la seconde partie..." << std::endl << std::endl;
	// Début de la deuxième partie
	partie2(motJoueur1);

}