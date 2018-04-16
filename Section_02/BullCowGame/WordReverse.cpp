#include "WordReverse.h"

WordReverse::WordReverse() {
	WordReverse::Reset();
}

WordReverse::~WordReverse() { 
	WordReverse::Reset();
}

bool WordReverse::ReplayProgram() const {

	std::string response = "";
	std::cout << "\n\nWould you like to try another example?\n";
	std::cout << "Y/N >> ";
	std::getline(std::cin, response);

	return ((response[0] == 'Y' || response[0] == 'y') ? true : false);
}

void WordReverse::Reset() {
	this->word = "";
	if (this->cWord != nullptr) {
		delete[] this->cWord;
		this->cWord = nullptr;
	}
}

void WordReverse::RunProgram() {
	this->GetWordFromUser();
	this->ReverseFString();
	this->ReverseCharPointer();
	this->DisplayResults();
}

void WordReverse::GetWordFromUser() {
	FString word = "";
	EWordStatus status = EWordStatus::INVALID_STATUS;

	do {
		std::cout << "Enter a string of words to reverse: ";
		std::getline(std::cin, word);

		status = this->CheckWordValidity(word);

		switch (status) {
			case EWordStatus::INCORRECT_LENGTH:
				std::cout << "Please enter a string of letters no longer than " << MAX_WORD_LENGTH << "\n\n";
				break;

			default:
				break;
		}
	} while (status != EWordStatus::OK);	

	this->word = word;
	this->GetWordAsCharPointer();

	return;
}

void WordReverse::GetWordAsCharPointer() {
	int32 length = this->word.length();
	this->cWord = new char[length + 1];

	for (int i = 0; i <= length; i++) {
		if (i == length) {
			this->cWord[i] = '\0';
		}
		else {
			this->cWord[i] = this->word[i];
		}
	}

	return;
}
bool WordReverse::IsCorrectLength(FString word) const {

	if (word.length() > MAX_WORD_LENGTH || word.length() == 0) return false;

	return true;
}

EWordStatus WordReverse::CheckWordValidity(FString word) const {

	if (!this->IsCorrectLength(word)) return EWordStatus::INCORRECT_LENGTH;

	return EWordStatus::OK;
}

void WordReverse::ReverseFString() {
	int32 length = this->word.length();

	for (int32 i = 0; i < length / 2; ++i) {
		std::swap(this->word[i], this->word[length - i - 1]);
	}
}

void WordReverse::ReverseCharPointer() const {
	int32 length = std::strlen(this->cWord);

	char *temp = new char;

	for (int32 start = 0, end = length - 1; start <= end; ++start, --end) {
		*temp = this->cWord[start];
		this->cWord[start] = this->cWord[end];
		this->cWord[end] = *temp;
	}
}

void WordReverse::DisplayResults() {
	std::cout << "Results of the string reversal: \n";
	std::cout << "FString reversal: " << this->word << "\n";
	std::cout << "char* reversal: " << this->cWord << "\n";
}
