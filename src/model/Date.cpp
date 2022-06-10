#include "Date.h"

Date::Date()
{
    //ctor
}

Date::~Date()
{
    //dtor
}

Date::Date(int day, Month month, int year) {
    this->date = day;
    this->month = month;
    this->year = year;
}

string Date::tostring()
{
    return to_string(month+1) + "-" + to_string(date) + "-" + to_string(year);
}
