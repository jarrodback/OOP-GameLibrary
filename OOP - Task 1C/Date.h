#pragma once
#include <ostream>
class Date
{
private:
	int day;
	int month;
	int year;
public: 
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	Date();
	Date(int day, int month, int year);
	static Date CurrentDate();

};
std::ostream& operator<<(std::ostream& os, Date const& date);
std::istream& operator>>(std::istream& is, Date& date);
bool operator<(Date const& d1, Date const& d2);