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

	Lexique lexique;
	std::vector<std::string> liste = lexique.extraireLexique("Lexique_1");
	lexique.modeAuto(liste); 

	//lexique.creerLexique("Lexique_1");
	//lexique.printMap(lexique.creerLexique("Lexique_1"));

}