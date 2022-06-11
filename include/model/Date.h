#ifndef DATE_H
#define DATE_H
#include "Month.h"
#include <string>
#include <StringUtil.h>
#include <stdexcept>
using namespace std;

class Date
{
    public:
        Date();
        Date(int day, Month month, int year);
        Date(string);
        virtual ~Date();

        int Getdate() { return date; }
        void Setdate(int val) { date = val; }
        int Getyear() { return year; }
        void Setyear(int val) { year = val; }
        Month Getmonth() { return month; }
        void Setmonth(Month val) { month = val; }
        string tostring();

    protected:

    private:
        int date;
        int year;
        Month month;
};

#endif // DATE_H
