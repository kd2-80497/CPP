#include <iostream>
using namespace std;

class Fact
{

    int num;
    int fact;

public:
    Fact()
    {
        this->num = 10;
    }
    Fact(int num)
    {
        this->num = num;
    }

    void factorial()
    {
        cout << "ENTER NUMBER TO CALCULATE FACTORIAL = " << endl;
        cin >> num;
        fact = 1;
        if (num < 0)
            throw 1;

        for (int i = 1; i <= num; i++)
        {
            fact = fact * i;
        }

        cout << "FACTORIAL = " << fact << endl;
    }
};

int main()
{
    Fact f;

    try
    {
        f.factorial();
    }
    catch (int error)
    {
        cout << "FACTORIAL OF NEGATIVE NUMBER IS NOT POSSIBLE " << endl;
    }
    cout << "SUCEESSSFULL EXECUTION " << endl;
}