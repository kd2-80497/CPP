#include <iostream>
using namespace std;

class Date
{

    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int get_day()
    {
        return day;
    }
    int get_month()
    {
        return month;
    }

    int get_year()
    {
        return year;
    }
    void set_day(int day)
    {
        this->day = day;
    }
    void set_month(int month)
    {
        this->month = month;
    }

    void set_year(int year)
    {
        this->year = year;
    }

    void accept()
    {
        cout << "ENTER DAY = ";
        cin >> day;
        cout << "ENTER MONTH = ";
        cin >> month;
        cout << "ENTER YEAR = ";
        cin >> year;
    }
    void display()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
    bool is_leap()
    {
        if (year % 4 == 0 || year % 400 == 0 && year % 100 != 0)
        {
            return 1;
        }
        else
            return 0;
    }
};

class Person
{

    string name;
    string addr;
    Date dob;

public:
    Person()
    {
        name = "";
        addr = "";
    }

    Person(string name, string addr, Date date)
    {
        this->name = name;
        this->addr = addr;
    }

    string get_name()
    {
        return this->name;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    string get_addr()
    {
        return addr;
    }
    void set_addr(string addr)
    {
        this->addr = addr;
    }
    Date get_dob()
    {
        return dob;
    }

    void set_dob(Date dob)
    {
        this->dob = dob;
    }

    void display()
    {
        cout << " PERSON NAME = " << name << endl;
        cout << "PERSON ADDRESS = " << addr << endl;
        cout << "EMPLOYEE DATE OF BIRTH= ";
        dob.display();
    }

    void accept()
    {
        cout << "ENTER PERSON NAME = ";
        cin >> name;
        cout << "ENTER PERSON ADDRESS= ";
        cin >> addr;
        cout << "ENTER DATE OF BIRTH " << endl;
        dob.accept();
    }
};

class Employee : public Person
{
    int id;
    float sal;
    string dept;
    Date doj;

public:
    Employee()
    {
        id = 0;
        sal = 300;
        dept = "";
    }
    Employee(string name, string addr, Date dob, int id, float sal, string dept, Date doj) : Person(name, addr, dob)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
        this->doj = doj;
    }
    int get_id()
    {
        return id;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    float get_sal()
    {
        return sal;
    }
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    string get_dept()
    {
        return dept;
    }
    void set_dept(string dept)
    {
        this->dept = dept;
    }
    Date get_doj()
    {
        return doj;
    }

    void set_doj(Date doj)
    {
        this->doj = doj;
    }

    void display()
    {
        Person::display();
        cout << "EMPLOYEE ID = " << id << endl;
        cout << "EMPLOYEE SALARY = " << sal << endl;
        cout << "EMPLOYEE DEPARTMENT = " << dept << endl;
        cout << "EMPLOYEE DATE OF JOINING = ";
        doj.display();
    }

    void accept()
    {
        Person::accept();
        cout << "ENTER EMPLOYEE ID = ";
        cin >> id;
        cout << "ENTER EMPLOYEE SALARY= ";
        cin >> sal;
        cout << "ENTER EMPLOYEE DEPARTMENT = ";
        cin >> dept;
        cout << "ENTER DATE OF JOINING  " << endl;
        doj.accept();
    }
};

int main()
{
    Date d1(23, 5, 2001);
    Date d2(12, 3, 2023);

    Employee e("ANSHU", "SAUSAR", d1, 23, 2345, "marketing", d2);
    e.accept();
    e.display();
}