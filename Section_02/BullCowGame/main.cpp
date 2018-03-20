#include "main.h"

using Ftext = std::string;
using int32 = int;

int main() {

	do {
		bcGame.Reset();
		PrintIntro();
		bcGame.PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

// Print the intro to the game
void PrintIntro() {
	system("cls");

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you think of the " << bcGame.GetHiddenWord().length() << " letter isogram I'm thinking of?\n";

	return;
}

bool AskToPlayAgain() {
	std::string response = "";
	std::cout << "Would you like to play again?\n";
	std::cout << "Y/N >> ";
	std::getline(std::cin, response);

	return ((response[0] == 'Y' || response[0] == 'y') ? true : false);
}

