#include <iostream>
#include <math.h>

using namespace std;

double convertToMPH(int minutes, int seconds);
double kphToMPH(double kph);

int main()
{
    int minutes = 0;
    int seconds = 0;
    double kph = 0.0;

    cout << "Enter a mile running pace in minutes and seconds.\n";
    cout << "Minutes: " << endl;
    cin >> minutes;
    cout << "Seconds: " << endl;
    cin >> seconds;
    while (seconds > 60)
    {
        seconds = seconds - 60;
        minutes ++;
    }
    
    cout << "Enter running pace in kilometers per hour: " << endl;
    cin >> kph;

    cout << "The first running pace in miles per hour is: ";
    cout << convertToMPH(minutes, seconds) << endl;
    cout << "The second running pace in miles per hour is: ";
    cout << kphToMPH(kph) << endl;

    return 0;
}
double convertToMPH(int minutes, int seconds)
{
    return (3600.0 / ((minutes * 60) + seconds));
}
double kphToMPH(double kph)
{
    return (kph / 1.61);
}