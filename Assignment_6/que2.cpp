#include <iostream>
using namespace std;

class Employee
{

    int id;
    float sal;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0.0;
        cout << "INSIDE  DEFAULT EMPLOYEE CONSTRUCTOR " << endl;
    }

    Employee(int id, float sal)
    {
        cout << "INSIDE EMPLOYEE CONSTRUCTOR " << endl;
        this->id = id;
        this->sal = sal;
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

    void accept()
    {
        cout << "ENTER EMPLOYEE ID = ";
        cin >> id;
        cout << "ENTER EMPLOYEEE SALARY = ";
        cin >> sal;
    }

    void display()
    {
        cout << "EMPLOYEE ID = " << id << endl
             << "EMPLOYEE SALARY = " << sal << endl;
    }
};

class Manager : virtual public Employee
{
    float bonus;

public:
    Manager()
    {
        cout << "INSIDE  DEFAULT MANAGER CONSTRUCTOR " << endl;
    }

    Manager(int id, float sal, float bonus) : Employee(id, sal)
    {
        cout << "INSIDE MANAGER CONSTRUCTOR " << endl;
        this->bonus = bonus;
    }

    float get_bonus()
    {
        return bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        Employee::accept();
        cout << "ENTER EMPLOYEE BONUS = ";
        cin >> bonus;
    }

    void display()
    {
        Employee::display();
        cout << "BONUS = " << bonus << endl;
    }

protected:
    void display_manager()
    {

        cout << "BONUS = " << bonus << endl;
    }
    void accept_manger()
    {

        cout << "ENTER EMPLOYEE BONUS = ";
        cin >> bonus;
    }
};

class Salesman : virtual public Employee

{

    float comm;

public:
    Salesman()
    {
        cout << "INSIDE  DEFAULT SALESMAN CONSTRUCTOR " << endl;
    }

    Salesman(int id, float sal, float comm) : Employee(id, sal)
    {
        cout << "INSIDE SALESMAN CONSTRUCTOR " << endl;
        this->comm = comm;
    }

    float get_comm()
    {
        return comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void accept()
    {
        Employee::accept();
        cout << "ENTER EMPLOYEE COMMISSION = ";
        cin >> comm;
    }

    void display()
    {
        Employee::display();
        cout << "COMMISSION= " << comm << endl;
    }

protected:
    void display_salesman()
    {

        cout << "COMMISSION= " << comm << endl;
    }
    void accept_salesman()
    {

        cout << "ENTER EMPLOYEE COMMISSION = ";
        cin >> comm;
    }
};

class sales_manager : public Manager, public Salesman
{

public:
    sales_manager()
    {
        cout << "INSIDE  DEFAULT SALES MANAGER CONSTRUCTOR " << endl;
    }

    sales_manager(int id, float sal, float bonus, float comm) : Manager(id, sal, bonus), Salesman(id, sal, comm)
    {
        cout << "INSIDE SALES MANAGER CONSTRUCTOR " << endl;
    }

    void display_sales_manager()
    {
        Employee::display();
        display_manager();
        display_salesman();
    }
    void accept_sales_manager()
    {
        Employee::accept();
        accept_manger();
        accept_salesman();
    }
};

int main()
{
    sales_manager sm;
    sm.accept_sales_manager();
    sm.display_sales_manager();
}