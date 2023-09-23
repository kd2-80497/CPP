#include<iostream>
using namespace std;

class Address{

string building;
string street;
string city;
int pin;

public:


Address(){
    this->building;
    this->city;
    this->street;
    this->pin;
    
}

Address( char* building,char* street,char* city,int pin){
    this->building = building;
    this->city=street;
    this->street=street;

    this->pin=pin;
    
}

void accept(){
    cout<<"ENTER BUILDING = ";
    cin>>building;
    cout<<"ENTER STREET = ";
    cin>>street;
     cout<<"ENTER city = ";
    cin>>city;
     cout<<"ENTER PIN = ";
    cin>>pin;

}

void display(){
    cout<<"***********ADRESSS**************\n";
    cout<<"BUILDING = "<<building ;
    cout<<"\nSTREET = "<<street ;
    cout<<"\nCITY = "<<city;
    cout<<"\nPIN CODE= " <<pin<<endl ;

}



string get_building(){

return this->building;
}

string get_street(){

return this->street;
}

string get_city(){

return this->city;
}
int get_pin(){

return this->pin;
}

void set_building(string building)
{
  this->building=building;
}


void set_street(string street)
{
  this->street=street;
}


void set_city(string city)
{
  this->city=city;
}




void set_pin(int pin)
{
  this->pin=pin;
}










};

int main(){
    Address a;
    a.accept();
    a.display();
    a.get_building();
    a.get_city();
    a.get_street();
    a.set_building("SHREGANESH");
    a.set_city("RAMAKONA");
    a.set_street("HANUMAN MANDIR");
    a.set_pin(456890);
    a.display();


}