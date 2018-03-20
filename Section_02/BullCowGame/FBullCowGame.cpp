#include "FBullCowGame.h"

//using FString = std::string;
//using int32 = int;

FBullCowGame::FBullCowGame() {
	FBullCowGame::Reset();
}

FBullCowGame::~FBullCowGame() { }

int32 FBullCowGame::GetCurrentTry() const { return this->myCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return this->myHiddenWord.length(); }

FString FBullCowGame::GetCurrentGuess() const { return this->myCurrentGuess; }

FString FBullCowGame::GetHiddenWord() const { return this->myHiddenWord; }

bool FBullCowGame::IsGameWon() const { return this->bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthMaxTries{ { 3, 4 },{ 4, 7 },{ 5, 10 },{ 6, 16 },{ 7, 20 } };
	return WordLengthMaxTries[this->GetHiddenWordLength()]; 
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const {

	if (!this->IsIsogram(guess)) {
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (!this->IsLowercase(guess)) {
		return EGuessStatus::NOT_LOWER_CASE;
	}
	else if (guess.length() != this->GetHiddenWordLength()) {
		return EGuessStatus::INCORRECT_LENGTH;
	}
	else {
		return EGuessStatus::OK;
	}
}

// Receives a valid guess to be compared to the hidden word
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	FBullCowCount bcCount;
	++this->myCurrentTry;

	int32 wordLength = this->GetHiddenWordLength();
	for (int32 i = 0; i < wordLength; ++i) {
		for (int32 j = 0; j < wordLength; ++j) {
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

	if (bcCount.bullCount == this->GetHiddenWordLength()) {
		this->bGameIsWon = true;
	}
	else {
		this->bGameIsWon = false;
	}

	return bcCount;
}

// Repeat the user's guess
void FBullCowGame::RepeatGuess() const {
	std::cout << "You guessed: " << this->myCurrentGuess << std::endl;
}

void FBullCowGame::PlayGame() {
	FString guess = "";
	FBullCowCount bcCount;

	do {
		guess = FBullCowGame::GetGuessFromUser();

		bcCount = FBullCowGame::SubmitGuess(guess);
		std::cout << "Bulls = " << bcCount.bullCount << std::endl;
		std::cout << "Couts = " << bcCount.cowCount << std::endl;
		FBullCowGame::RepeatGuess();

		std::cout << std::endl;
	} while ((this->myCurrentTry <= this->GetMaxTries()) && (!IsGameWon()));

	std::cout << std::endl;

	this->GameSummary();

	return;
}

void FBullCowGame::Reset() {
	
	this->myCurrentTry = 1;
	this->myCurrentGuess = "";
	this->myHiddenWord = HIDDEN_WORD;
	this->bGameIsWon = false;

	return;
}

// Get a valid guess using GETLINE()
FString FBullCowGame::GetGuessFromUser() {
	FString guess = "";
	EGuessStatus status = EGuessStatus::INVALID_STATUS;
	do {	
		std::cout << "Try " << this->GetCurrentTry() << " of " << this->GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, guess);

		status = this->CheckGuessValidity(guess);

		switch (status) {
			case EGuessStatus::INCORRECT_LENGTH:
				std::cout << "Please enter a " << this->GetHiddenWordLength() << " leter word\n\n";
				break;

			case EGuessStatus::NOT_ISOGRAM:
				std::cout << "Please enter a valid isogram\n\n";
				break;

			case EGuessStatus::NOT_LOWER_CASE:
				std::cout << "Please enter a lowercase word\n\n";
				break;

			default:
				// Assume the guess is valid since no errors are thrown.
				break;
		}

	} while (status != EGuessStatus::OK);

	return guess;
}

bool FBullCowGame::IsLowercase(FString guess) const {
	for(auto letter : guess) {
		if (!islower(letter)) {
			return false;
		}
	}
	return true;
}

void FBullCowGame::GameSummary() {

	if (IsGameWon()) {
		std::cout << "Congratulations!  You have guessed correctly!\n\n";
	}
	else {
		std::cout << "Better luck next time Chump!!\n\n";
	}

	return;
}

bool FBullCowGame::IsIsogram(FString word) const {
	
	if (word.length() <= 1) { return true; }

	TMap<char, bool> letterSeen;
	for (auto letter : word) {
		letter = tolower(letter);

		if (letterSeen[letter]) { return false; }
		else { letterSeen[letter] = true; }
	}

	return true;
}