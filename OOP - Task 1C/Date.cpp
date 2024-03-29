#include "Date.h"
#include <ctime>
#include <sstream>
#include <vector>

int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}


Date::Date()
{
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{

}

Date Date::CurrentDate()
{
	const std::time_t time(time(0));
	struct tm currentDate;
	localtime_s(&currentDate, &time);
	int day = currentDate.tm_mday;
	int month = currentDate.tm_mon + 1;
	int year = currentDate.tm_year + 1900;
	return Date(day, month, year);
}

std::ostream& operator<<(std::ostream& os, Date const& date)
{
	os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
	return os;
}
std::istream& operator>>(std::istream& is, Date& date)
{
	std::vector<std::string> tokens;
	std::string s;
	is >> s;
	std::stringstream dateString(s);
	std::string temp;
	while (getline(dateString, temp, '-')) 
		tokens.push_back(temp);
	date =  Date(stoi(tokens[0]), std::stoi(tokens[1]), std::stoi(tokens[2]));
	return is;

}
bool operator<(Date const& d1, Date const& d2) {
	if (d1.getYear() < d2.getYear())
		return true;
	else if (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth())
		return true;
	else if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay())
		return true;
	else
		return false;
}
