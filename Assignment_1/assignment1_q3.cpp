#include<iostream>
using namespace std;

class Student{

int rollno;
string name;
int marks;

 public:

void initStudent(){
    rollno=20;
    name="anshu";
    int marks=40;


}

void printStudentOnConsole(){
    cout<<"NAME - "<<name<<endl;
    cout<<"ROLLNO - "<<rollno<<endl;
      cout<<"MARKS - "<<marks<<endl;
}

void acceptStudentFromConsole(){
    cout<<"ENTER STUDENT NAME - \n";
    cin>>name;
    cout<<" ENTER ROLL NO - ";
    cin>>rollno;
    cout<<"\nENTER MARKS - ";
    cin>>marks;

}
};

int main(){
    Student st;
    int ch;

    do{

         cout<<"*************STUDENT DETAILS******************\n";
         cout<<"1.INITIALISE  STUDENT"<<endl;
        cout<<"2. DISPLAY STUDENT "<<endl;
        cout<<"3. ACCEPT STUDENT DATA"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<" ENTER YOUR CHOICE"<<endl;
        cin>>ch;

        switch(ch)
{
        case 1: st.initStudent();
        break;

        case 2: st.printStudentOnConsole();
        break;

        case 3: st.acceptStudentFromConsole();
        break;

        case 0: cout<<"**********EXIT**********\n"<<endl;
        break;
}



    }while(ch);
}