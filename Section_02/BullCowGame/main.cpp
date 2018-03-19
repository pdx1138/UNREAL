#include "main.h"

using Ftext = std::string;
using int32 = int;

int main() {

	PrintIntro();

	do {
		game.PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

// Start playing the game
//void PlayGame() {
//	Ftext guess = "";
//
//	for (int32 i = 0; i < GUESS_COUNT; ++i) {
//		guess = GetGuess_GetLine();
//		RepeatGuess(guess);
//		std::cout << std::endl;
//	}
//
//	std::cout << std::endl;
//}


// Print the intro to the game
void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a word game\n";
	std::cout << "Can you think of the " << game.GetHiddenWord().length() << " letter isogram I'm thinking of?\n";

	return;
}
//
//// Get the guess using simple CIN
//Ftext GetGuess_CIN() {
//	Ftext guess = "";
//
//	// Get guess input from user
//	std::cout << "Enter your guess: ";
//	std::cin >> guess;
//
//	return guess;
//}
//
//// Get the guess using GETLINE()
//Ftext GetGuess_GetLine() {
//	Ftext guess = "";
//	std::cout << "Enter your guess: ";
//	//cin.getline(guess, guessSize);
//	std::getline(std::cin, guess);
//
//	return guess;
//}
//
//// Repeat the user's guess
//void RepeatGuess(Ftext guess) {
//	std::cout << "You guessed: " << guess << std::endl;
//}

bool AskToPlayAgain() {
	std::string response = "";
	std::cout << "Would you like to play again?\n";
	std::cout << "Y/N >> ";
	std::getline(std::cin, response);

	return ((response[0] == 'Y' || response[0] == 'y') ? true : false);
}

