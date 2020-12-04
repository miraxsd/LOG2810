#include "Lexique.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cctype>		/*isalpha*/


bool verifierAlpha(std::string phrase1) {
	for (char caractere : phrase1) {
		if (!(isalpha(caractere)))
			return false;
	}
	return true;
}

void Lexique::modeAuto(std::vector<std::string> listeMots) {

	srand(time(NULL));

	int indexSecret = rand() % (listeMots.size()) ;

	std::cout << "index :" << indexSecret << std::endl;

	//on recupere le mot secret
	std::string motSecret = listeMots[indexSecret];

	std::cout << "Le mot secret a ete choisi" << std::endl;

	std::cout << "La taille du mot secret est : " << motSecret.size() << std::endl;

	std::cout << "mot secret : " << motSecret << std::endl;

	//Utilisateur essaye de trouver le mot

	std::string choixUtilisateur = "";

	int nbEssais = 0;

	int nbErreurs = 0;

	while (nbEssais < NB_ESSAIS_MAX) {


		std::cout << std::endl << "ESSAI " << nbEssais + 1 << std::endl;

		std::cout << "votre choix ?" << std::endl;

		std::cin >> choixUtilisateur;

		std::cout << std::endl;

		bool enLettreAlpha = false;
		//regarder s'ils ont la meme longueur
		if (choixUtilisateur.size() == motSecret.size()) {

			//regarder s'il y a les memes lettres
			enLettreAlpha = verifierAlpha(choixUtilisateur);
			if (enLettreAlpha == true) {
				//si c le meme mot
				if (choixUtilisateur == motSecret) {
					std::cout << "Bravo !, vous avez trouve le mot en " << nbEssais + 1 << " essais";
					break;
				}
				//on dit que c pas le bon et on incremente le nb d'Essais
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


void Lexique::modeVersus() {

	std::cout << "Premiere partie : Vous devez choisir le mot secret !" << std::endl << std::endl;

	bool motChoisi = false;
	std::string motJoueur1 = "undefined";
	//tant qu'on a pas choisi le mot
	while (motChoisi != true) {

		std::cout << "Quel code ?" << std::endl << std::endl;

		std::cin >> motJoueur1;
		std::cout << std::endl << std::endl;

		std::cout << "Suggestion(s) : " << std::endl << std::endl;

		//if(contientMot)


	}

}