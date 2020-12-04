#include "Lexique.h"

int main() {
	/*bool jeuInitialise = false;
	std::string nomFichier;
	int choix=0;
	while(choix!=4)
	{
		while(choix!=1)
		{
			std::cout << "Veuillez initialiser le jeu" << std::endl;

		}
	}*/

	/*Lexique lexique;
	std::vector<std::string> liste1 = lexique.extraireLexique("Lexique_1");
	//lexique.effacerListeMots();
	//std::vector<std::string> liste2 = lexique.extraireLexique("Lexique_2");
	std::map<std::string, std::set<std::string>> automate1;
	automate1=lexique.creerAutomate();
	lexique.printMap();

	lexique.effacerListeMots();
	lexique.effacerAutomate();

	std::cout << "-------------------------------------------------------------" << std::endl << std::endl;

	std::cout << "ON VIENT DE SUPPRIMER LA LISTE ET L'AUTOMATE" << std::endl << std::endl;

	std::vector<std::string> liste2 = lexique.extraireLexique("Lexique_2");
	std::map<std::string, std::set<std::string>> automate2;
	automate2 = lexique.creerAutomate();
	lexique.printMap();*/
 
	//lexique.creerLexique("Lexique_1");
	
	Lexique lexique;
	 std::map<std::string, std::set<std::string>> map = lexique.creerLexique("Lexique_3");
	//std::map<std::string, std::set<std::string>> automate = lexique.creerAutomate();
	//lexique.printMap();
	lexique.modeAuto();
	// lexique.modeVersus();


}