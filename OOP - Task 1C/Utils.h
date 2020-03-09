#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <ctime>

class Utils
{
  public:
	static std::string GetLineFromUser();
	static char GetCharFromUser();
	static bool startsWith(const std::string& input, const std::string& fullText);
	static bool inPriceRange(std::string& inputtedRange, const int& priceOfGame);
	static std::string formatGametime(int mins);
	static std::string toUppercaseR(std::string s);
	static void toUppercase(std::string& s);

	static int generateGametime();
  private:
	static std::vector<int> splitPriceRange(std::string& inputtedRange);
	
};