#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;

constexpr int32 WORD_LENGTH = 9;
constexpr int32 GUESS_COUNT = 5;

FBullCowGame game;

void PrintIntro();
//void PlayGame();
//std::string GetGuess_CIN();
//std::string GetGuess_GetLine();
//void RepeatGuess(std::string guess);
bool AskToPlayAgain();
