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
