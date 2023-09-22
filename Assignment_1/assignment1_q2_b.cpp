#include <iostream>
using namespace std;

 class Date{

  int day;
  int month;
  int year;

public:
     void initdate(){
        cout<<"INSIDE INITIAL DATE "<<endl;
        day=0;
        month=0;
        year=0;
     }
         void printDateOnConsole(){
        cout<<"INSIDE  PRINT ON CONSOLE DATE "<<endl;
        cout<<"DATE IS:-"<<day<<"-"<<month<<"-"<<year<<endl;
         }

void acceptDateFromConsole(){
        cout<<"INSIDE ACCEPT DATE"<<endl;
        cout<<"ENTER DAY MONTH YEAR"<<endl;
        cin>>day>>month>>year;

}
 bool isLeapYear(){
        if(year%100==0 || year%400==0 && year%100 != 0){
            return 1;

        }
        else{
            return 0;
        }
 }

 };



int main(){
   
    int ch;

    struct Date dt;

    do
    {


        cout<<"************DATE**************\n"<<endl;
          cout<<"0.EXIT"<<endl;
          cout<<"1.Initial Date"<<endl;
           cout<<"2.Print Date On Console"<<endl;
            cout<<"3.Accept Date On console"<<endl;
            cout<<"4.check LEAP YEAR"<<endl;
             cout<<"Enter your choice"<<endl;
             cin>>ch;

             
        switch (ch)
        {
        case 0:
            cout<<"************EXIT**************\n";
                break;
        case 1:
            dt.initdate();
            break;

        case 2:
            dt.printDateOnConsole();
            break;

        case 3:
           dt.acceptDateFromConsole();
            break;
        case 4:
        if(dt.isLeapYear()){
            cout<<"IT IS LEAP YEAR"<<endl;
        }
        else{
            cout<<"it is not leap year"<<endl;
        }


        default:
           printf("ENTER VALID CHOICE\n");

            break;
        }
             } while (ch);


 return 0;

}