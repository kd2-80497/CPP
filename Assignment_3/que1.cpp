#include <iostream>
using namespace std;

class Box
{

    float length;
    float width;
    float height;

public:
    Box()
    {
    }

    Box(float length, float width, float height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    void accept()
    {

        cout << "ENTER THE LENGTH OF BOX = ";
        cin >> length;
        cout << "ENTER THE WIDTH OF BOX = ";
        cin >> width;
        cout << "ENTER THE HEIGHT OF BOX = ";
        cin >> height;
    }

    void display()
    {
        cout << "**********VOLUME**************\n";
        cout << "LENGTH = " << length << endl;
        cout << "WIDTH = " << width << endl;
        cout << "HEIGHT = " << height << endl;
        cout << "****************************" << endl;
    }

    int cal_vol()
    {
        float volume = this->height * this->length * this->width;
        cout<<"volume = "<<volume;
        return 0;
    }
};




int menu(){
    int choice;
    cout<<"\n**************BOX VOLUME CALCULATION MENU******************\n";
    cout<<"0.EXIT \n";
    cout<<"1.ACCEPT DATA \n";
    cout<<"2.DISPLAY DATA \n";
    cout<<"3.VOLUME CALCULATION \n";
    cout<<"ENTER CHOICE \n";
    cout<<"********************\n";
    cin>>choice;
    cout<<"*****************\n";
    return choice;
     }





int main()
{
Box b;
int choice;
    while((choice=menu())!=0){
        switch(choice){
          case 1: b.accept();
          break;
          case 2: b.display();
          break;
          case 3: b.cal_vol();
          break;

          default : cout<<"INVALID CHOICE RE-ENTER CHOICE AGAIN \n";
          break; 
        }
    }
    return 0;
}