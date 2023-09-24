#include "./menu.h"
#include<iostream>
using namespace std;


Emenu menu()
{
    int choice;
    cout << "\n**************CYLINDER VOLUME CALCULATION MENU******************\n";
    cout << "0.EXIT \n";
    cout << "1.ACCEPT radius \n";
    cout << "2.DISPLAY raius \n";
    cout << "3.accept height \n";
    cout << "4.DISPLAY HEIGHT \n";
    cout << "5.CALCULATE VOLUME \n";
    cout << "6.DISPLAY  VOLUME \n";
    cout << "ENTER CHOICE \n";
    cout << "********************\n";
    cin >> choice;
    cout << "*****************\n";
    return Emenu(choice);
}