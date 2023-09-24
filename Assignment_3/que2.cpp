#include <iostream>
using namespace std;

class Tollbooth
{
    unsigned int tot_cars;
    double tot_amount;
    int unpay_car;

public:
    Tollbooth()
    {
        tot_cars = 0;

        unpay_car = 0;

        tot_amount = 0;
    }

    void payingCar()
    {

        tot_amount = tot_amount + 0.50;
        tot_cars = tot_cars + 1;
    }

void nopayCar()
    {

        unpay_car = unpay_car + 1;
        
    }

    void printOnConsole()
    {
        cout << "TOTAL AMOUNT = " << tot_amount << endl;
        cout << "TOTAL NO OF CARS = " << tot_cars + unpay_car << endl;
        cout << "TOTAL NO OF UNPAID CARS = " << unpay_car << endl;
        cout<<"TOTAL NO OF PAYING CARS= "<<tot_cars<<endl;
    }
};

int menu()
{
    int choice;
    cout << "**********TOLLBOOTH*************\n";
    cout << "0.EXIT \n";
    cout << "1.PAYING CAR \n";
    cout << "2. NO  PAY CAR \n";
    cout << "3.PRINT DETAILS \n";
    cout << "ENTER YOUR CHOICE \n";
    cout << "*********************\n";
    cin >> choice;
    return choice;
}

int main()
{

    int choice;
    Tollbooth tb;

    while ((choice = menu()) != 0)
    {

        switch (choice)
        {

        case 1:
            tb.payingCar();
            break;

        case 2:
            tb.nopayCar();
            break;

        case 3:
            tb.printOnConsole();
            break;

        default:
            cout << "ENTER VALID CHOICE \n";
            break;
        }
    }

    return 0;
}
