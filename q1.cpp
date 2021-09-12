#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue (int year);
int getMonthValue(int month, int year);

int main()
{
    int month = 0, day = 0, year = 0, sum = 0, day_of_week = 0;
    string day_string = "";

    cout << "Enter the month" << endl;

    cin >> month;

    while (month < 1 || month > 12)
    {
        cout << "Please give a valid month." << endl;
        cin >> month;
    }
    
    cout << "Enter a day" << endl;
    cin >> day;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        while (day < 1 || day > 30)
        {
            cout << "Please enter a valid day." << endl;
            cin >> day;
        }
    }
    if (month == 2)
    {
        while (day < 1 || day > 29)
        {
            cout << "Please enter a valid day." << endl;
            cin >> day;
        }
    }
    else
    {
        while (day < 1 || day > 31)
        {
            cout << "Please enter a valid day." << endl;
            cin >> day;
        }
    }

    cout << "Enter a year" << endl;
    cin >> year;

    while (year < 0 || year > 2021)
    {
        cout << "Please enter a valid year." << endl;
        cin >> year;
    }
    day_of_week = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;
    switch(day_of_week)
    {
        case 0:
            day_string = "Sunday";
            break;
        case 1:
            day_string = "Monday";
            break;
        case 2:
            day_string = "Tuesday";
            break;
        case 3:
            day_string = "Wednesday";
            break;
        case 4:
            day_string = "Thursday";
            break;
        case 5:
            day_string = "Friday";
            break;
        case 6:
            day_string = "Saturday";
            break;
    }
    cout << day_string;
}
bool isLeapYear(int year)
{
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
int getCenturyValue(int year)
{
    int firstPart = year/100.0;
    int remainder = firstPart % 4;
    return (3 - remainder)*2;
}
int getYearValue(int year)
{
    int firstPart = year/100.0;
    int lastPart = year - firstPart*100;
    int quotient = lastPart/4.0;
    return quotient + lastPart;
}
int getMonthValue(int month, int year)
{
    switch(month)
    {
        case 1:
            if (isLeapYear(year))
            {
                return 6;
            }
            else
            {
                return 0;
            }
        case 2:
            if (isLeapYear(year))
            {
                return 2;
            }
            else
            {
                return 3;
            }
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
    }
}