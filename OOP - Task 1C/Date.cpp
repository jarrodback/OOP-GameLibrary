#include "Date.h"
#include <ctime>

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
