#include "Utils.h"

std::string Utils::GetLineFromUser()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char Utils::GetCharFromUser()
{
	return toupper(GetLineFromUser()[0]);
}

bool Utils::startsWith(const std::string& input, const std::string& fullText) {
	for (int i = 0; i < input.length(); ++i) {
		if (tolower(input[i]) != tolower(fullText[i]))
			return false;
	}
	return true;
}

bool Utils::inPriceRange(std::string& inputtedRange, const int& priceOfGame) { //¬??????
	std::vector<int>prices = splitPriceRange(inputtedRange);
	if (prices[0] > prices[1]) {
		int temp = prices[0];
		prices[0] = prices[1];
		prices[1] = temp;
	}
	if ((priceOfGame / 100) > prices[0] && (priceOfGame / 100) < prices[1])
		return true;
	else
		return false;
}


std::vector<int> Utils::splitPriceRange(std::string& inputtedRange) {

	std::vector<int> prices;
 	std::stringstream string(inputtedRange);
	std::string tempString;
	int tempInt;
	while (std::getline(string, tempString, '-')) {
		prices.push_back(std::stoi(tempString));
	}
	return prices;
}