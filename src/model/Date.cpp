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

Date::Date(string str) {
    char **seperatedStr;
    int count = splitstr(str.c_str(), '-', seperatedStr);
    if (count != 3)
    {
        throw invalid_argument("invalid argument");
    }
    this->date = atoi(seperatedStr[1]);
    this->month = static_cast<Month>(atoi(seperatedStr[0])-1);
    this->year = atoi(seperatedStr[2]);
}

string Date::tostring()
{
    return to_string(month+1) + "-" + to_string(date) + "-" + to_string(year);
}
