#include "./cylinder.h"
#include "./menu.h"


int main()
{

    int choice;
    Cylinder c;

    while ((choice = menu()) != 0)
    {

        switch (choice)
        {

        case 1:
            c.setRadius();
            break;

        case 2:
            c.getRadius();
            break;

        case 3:
            c.setHeight();
            break;

        case 4:
            c.getHeight();
            break;

        case 5:
            c.getVolume();
            break;

        case 6:
            c.printVolume();
            break;
        default:
            cout << "ENTER VALID CHOICE \n";
            break;
        }
    }

    return 0;
}
