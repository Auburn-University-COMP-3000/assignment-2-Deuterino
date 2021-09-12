#include <iostream>
#include <math.h>

using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);
void printOutput(int coinValue, int& number);

int main()
{
    int coinValue; 
    int number;
    int amountLeft;
    char response;

    do
    {  
        cout << "Enter the amount of change: ";
        cin >> amountLeft;
        while (amountLeft < 1 || amountLeft > 100)
        {
            cout << "Enter an amount between 1 and 100: ";
            cin >> amountLeft;
        }
        
        cout << "Change cane be given as:" << endl;
        computeCoin(25, number, amountLeft);
        printOutput(25, number);
        computeCoin(10, number, amountLeft);
        printOutput(10, number);
        computeCoin(1, number, amountLeft);
        printOutput(1, number);

        cout << "\nDo you want to calculate more change?";
        cout << "\nPress Y to continue or any other key to exit: ";
        cin >> response; 

    } while (response == 'Y' || response == 'y');
    return 0;
}

void computeCoin(int coinValue, int& number, int& amountLeft)
{
    switch(coinValue)
    {
        case 25:
            number = amountLeft / coinValue;
            amountLeft = amountLeft - coinValue * number;
            break;
        case 10:
            number = amountLeft / coinValue;
            amountLeft = amountLeft - coinValue * number;
            break;
        case 1:
            number = amountLeft;
            break;
    }
}
void printOutput(int coinValue, int& number)
{
    switch(coinValue)
    {
        case 25:
            cout << number << " quarters" << endl;
            break;
        case 10:
            cout << number << " dimes" << endl;
            break;
        case 1:
            cout << number << " pennies" << endl;
            break;
    }
}