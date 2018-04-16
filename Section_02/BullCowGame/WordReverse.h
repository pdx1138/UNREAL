#pragma once
#include <iostream>
#include <string>
#include "UnrealDefinitions.h"

constexpr int32 MAX_WORD_LENGTH = 255;

enum class EWordStatus {
	INVALID_STATUS = 0,
	OK,
	INCORRECT_LENGTH,
};

class WordReverse {
	public:
		WordReverse();
		~WordReverse();

		bool ReplayProgram() const;
		EWordStatus CheckWordValidity(FString word) const;
		void ReverseFString();
		void ReverseCharPointer() const;
		void DisplayResults();

		void Reset();
		void RunProgram();		

	private:
		FString word;
		char *cWord;

		void GetWordFromUser();
		void GetWordAsCharPointer();
		bool IsCorrectLength(FString word) const;
};

