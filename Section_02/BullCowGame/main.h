#pragma once

#include <iostream>
#include <string>
//#include "FMenu.h"
#include "FBullCowGame.h"
#include "WordReverse.h"

using int32 = int;

constexpr int32 WORD_LENGTH = 9;
constexpr int32 GUESS_COUNT = 5;
constexpr int menuSize = 3;		// The Total Number of Options in the Menu.

enum class EMenuStatus {
	INVALID_STATUS = 0,
	OK,
	NOT_NUMBER,
	NOT_IN_RANGE
};

// Game instance
FBullCowGame bcGame;
WordReverse wrProg;

void PlayBullCowGame();
void RunMenu();
int32 GetMenuOption();
EMenuStatus CheckOptionValidity(FString option);
void WordReverseExample();
bool IsNumeric(FString option);
bool IsInRange(FString option);
