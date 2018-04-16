#include "main.h"

using Ftext = std::string;
using int32 = int;

int main() {

	/*do {
		bcGame.Reset();
		PrintIntro();
		bcGame.PlayGame();
	} while (AskToPlayAgain());*/
	//PlayBullCowGame();
	RunMenu();
	
	return 0;
}

void RunMenu() {
	system("cls");
	int32 option = 0;
	
	do {
		option = GetMenuOption();

		switch (option)
		{
			case 1:
				PlayBullCowGame();
				break;
			case 2:
				WordReverseExample();
				break;
			default:
				// Nothing to do with this option Number
				break;
		}
	} while (option != menuSize);

	return;
}

int32 GetMenuOption() {
	FString option = "";
	EMenuStatus status = EMenuStatus::INVALID_STATUS;

	do {

		std::cout << "Please select the program you would like to run:.\n";
		std::cout << "1. Bull Cow Game\n";
		std::cout << "2. Word Reverse Program\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice >> ";
		std::cin >> option;

		status = CheckOptionValidity(option);

		switch (status) {
			case EMenuStatus::NOT_NUMBER:
				std::cout << "Please enter a valid number\n\n";
				break;

			case EMenuStatus::NOT_IN_RANGE:
				std::cout << "Please enter a valid menu option\n\n";
				break;

			case EMenuStatus::OK:
				// Fall Through because the option is valid.
			default:
				// Assume the option is valid since no errors are thrown.
				break;
		}

	} while (status != EMenuStatus::OK);

	return (int32)std::stoi(option);
}

void WordReverseExample() {
	do {
		wrProg.Reset();
		wrProg.RunProgram();
	} while (wrProg.ReplayProgram());

	return;
}

void PlayBullCowGame() {
	do {
		bcGame.Reset();
		bcGame.PrintGameIntro();
		bcGame.PlayGame();
	} while (bcGame.ReplayGame());

	return;
}

EMenuStatus CheckOptionValidity(FString option) {

	if (!IsNumeric(option)) return EMenuStatus::NOT_NUMBER;
	else if (!IsInRange(option)) return EMenuStatus::NOT_IN_RANGE;
	
	return EMenuStatus::OK;
}

bool IsNumeric(FString option) {
	int32 size = option.length();

	for (auto letter : option) {
		if (!isdigit(letter)) {
			return false;
		}
	}

	return true;
}

bool IsInRange(FString option) {
	int32 choice = (int32)std::stoi(option);

	if (choice <= 0 || choice > menuSize) return false;
	return true;
}
