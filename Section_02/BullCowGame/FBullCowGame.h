/*
	Simple Guess the word game based on mastermind.
*/
#pragma once

#include <iostream>
#include <string>
#include <map>

// Unreal friendly syntax for #define and using
#define TMap std::map

using FString = std::string;
using int32 = int;

constexpr int FBC_GAME_MAX_TRIES = 8;
const FString HIDDEN_WORD = "ask";

// Allow us to hold the results in one data type.
struct FBullCowCount {
	int32 bullCount = 0;
	int32 cowCount = 0;
};

enum class EGuessStatus {
	INVALID_STATUS = 0,
	OK,
	NOT_ISOGRAM,
	INCORRECT_LENGTH,
	NOT_LOWER_CASE
};

class FBullCowGame {

	public:
		FBullCowGame();
		~FBullCowGame();

		int32 GetCurrentTry() const;
		int32 GetMaxTries() const;
		int32 GetHiddenWordLength() const;
		FString GetCurrentGuess()const;
		FString GetHiddenWord() const;
		void RepeatGuess() const;
		bool IsGameWon() const;
		EGuessStatus CheckGuessValidity(FString guess) const;
		FBullCowCount SubmitGuess(FString guess);

		void PlayGame();
		void Reset(); 
		void GameSummary();

	private:
		int32 myCurrentTry;
		FString myHiddenWord;
		FString myCurrentGuess;
		bool bGameIsWon;

		FString GetGuessFromUser();
		bool IsIsogram(FString word) const;
		bool IsLowercase(FString guess) const;
};

