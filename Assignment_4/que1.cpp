#include <iostream>
using namespace std;

class Time
{

    int hour;
    int minute;
    int seconds;

public:
    Time()
    {
    }

    Time(int h, int m, int s)
    {
        this->hour = h;
        this->minute = m;
        this->seconds = s;
    }

    void getHour()
    {
        cout << "ENTER HOUR = " ;
        cin >> hour;
    }

    void getMin()
    {
        cout << "ENTER Minute = " ;
        cin >> minute;
    }

    void getSeconds()
    {
        cout << "ENTER Seconds = ";
        cin >> seconds;
    }

    void printTime()
    {
        cout  << hour << ":" << minute << ":" << seconds << endl;
    }

    int setHour(int hour)
    {
        this->hour = hour;
        return this->hour;
    }

    int setMinute(int minute)
    {
        this->minute = minute;
        return this->minute;
    }

    int setSeconds(int seconds)
    {
        this->seconds = seconds;
        return this->seconds;
    }
};

int main()
{

    Time **arr = new Time *[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = new Time();
    }

    for (int i = 0; i < 5; i++)
    { cout<<"ENTER THE VALUES FOR OBJECT "<<i<<endl;
        arr[i]->getHour();
        arr[i]->getMin();
        arr[i]->getSeconds();
    }

    for (int i = 0; i < 5; i++)
    {cout<<"TIME FOR OBJECT "<<i<<" is=";
        arr[i]->printTime();
    }

    for (int i = 0; i < 5; i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}