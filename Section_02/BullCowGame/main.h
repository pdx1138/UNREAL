#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;

constexpr int32 WORD_LENGTH = 9;
constexpr int32 GUESS_COUNT = 5;

// Game instance
FBullCowGame bcGame;

void PrintIntro();
bool AskToPlayAgain();
