#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Utils
{
  public:
	static std::string GetLineFromUser();
	static char GetCharFromUser();
	static bool startsWith(std::string& input, std::string& fullText);
	static bool inPriceRange(std::string& inputtedRange, const int& priceOfGame);
  private:
	static std::vector<int> splitPriceRange(std::string& inputtedRange);
};