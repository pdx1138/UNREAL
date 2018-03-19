#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	FBullCowGame::Reset();
}


FBullCowGame::~FBullCowGame() {

}

int32 FBullCowGame::GetCurrentTry() const { return FBullCowGame::myCurrentTry; }

int32 FBullCowGame::GetMaxTries() const { return FBullCowGame::myMaxTries; }

FString FBullCowGame::GetCurrentGuess() const { return FBullCowGame::myCurrentGuess; }

FString FBullCowGame::GetHiddenWord() const { return FBullCowGame::myHiddenWord; }

bool FBullCowGame::IsGameWon() const {

	return false;
}

bool FBullCowGame::CheckGuessValidity(FString guess) const {
	//TODO: Do validation loop here
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	FBullCowCount bcCount;

	int32 length = this->myHiddenWord.length();
	for (int32 i = 0; i < length; ++i) {
		for (int32 j = 0; j < length; ++j) {
			if (guess[j] == this->myHiddenWord[i]) {
				if (i == j) {
					++bcCount.bullCount;
				}
				else {
					++bcCount.cowCount;
				}
			}
		}		
	}

	this->myCurrentGuess = guess;

	return bcCount;
}

// Repeat the user's guess
void FBullCowGame::RepeatGuess() const {
	std::cout << "You guessed: " << this->myCurrentGuess << std::endl;
}

void FBullCowGame::PlayGame() {
	FString guess = "";

	for (; this->myCurrentTry <= this->myMaxTries; ++this->myCurrentTry) {
		guess = FBullCowGame::GetGuessFromUser();
		// TODO: Check for valid guess

		FBullCowCount bcCount = FBullCowGame::SubmitGuess(guess);
		std::cout << "Bulls = " << bcCount.bullCount << std::endl;
		std::cout << "Couts = " << bcCount.cowCount << std::endl;
		FBullCowGame::RepeatGuess();

		std::cout << std::endl;
	}

	std::cout << std::endl;

	// TODO: Summarize Game

	return;
}

void FBullCowGame::ExitGame() {

	return;
}

void FBullCowGame::Reset() {

	this->myCurrentTry = 1;
	this->myMaxTries = FBC_GAME_MAX_TRIES;
	this->myCurrentGuess = "";
	this->myHiddenWord = HIDDEN_WORD;

	return;
}

// Get the guess using GETLINE()
FString FBullCowGame::GetGuessFromUser() {
	FString guess = "";
	std::cout << "Try " << this->myCurrentTry << ". Enter your guess: ";
	//cin.getline(guess, guessSize);
	std::getline(std::cin, guess);

	return guess;
}

void FBullCowGame::GetIsogram()
{
	return;
}

