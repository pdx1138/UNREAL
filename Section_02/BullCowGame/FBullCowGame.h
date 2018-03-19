#pragma once

#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

constexpr int FBC_GAME_MAX_TRIES = 8;
const FString HIDDEN_WORD = "planet";

struct FBullCowCount {
	int32 bullCount = 0;
	int32 cowCount = 0;
};

class FBullCowGame {

	public:
		FBullCowGame();
		~FBullCowGame();

		int32 GetCurrentTry() const;
		int32 GetMaxTries() const;
		FString GetCurrentGuess()const;
		FString GetHiddenWord() const;
		void RepeatGuess() const;
		bool IsGameWon() const;
		bool CheckGuessValidity(FString guess) const;
		FBullCowCount SubmitGuess(FString guess);

		void PlayGame();
		void ExitGame();
		void Reset();  // TODO make a more rich return value

	private:
		int32 myCurrentTry;
		int32 myMaxTries;
		FString myHiddenWord;
		FString myCurrentGuess;

		FString GetGuessFromUser();
		void GetIsogram();
};

