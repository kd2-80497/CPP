#include <iostream>
using namespace std;

class Employee
{

    int id;
    float sal;

protected:
    string designation;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0.0;
        // cout << "INSIDE  DEFAULT EMPLOYEE CONSTRUCTOR " << endl;
    }

    Employee(int id, float sal)
    {
        // cout << "INSIDE EMPLOYEE CONSTRUCTOR " << endl;
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

    string get_designation()
    {
        return designation;
    }
    virtual void accept()
    {
        cout << "ENTER EMPLOYEE ID = ";
        cin >> id;
        cout << "ENTER EMPLOYEEE SALARY = ";
        cin >> sal;
    }

   virtual  void display()
    {
        cout << "EMPLOYEE ID = " << id << endl;
        cout << "EMPLOYEE SALARY = " << sal << endl;
    }
};

class Manager : virtual public Employee
{
    float bonus;
    int mcount;

public:
    Manager()
    {
        // cout << "INSIDE  DEFAULT MANAGER CONSTRUCTOR " << endl;
        designation = "manager";
        this->mcount++;
    }

    Manager(int id, float sal, float bonus) : Employee(id, sal)
    {
        // cout << "INSIDE MANAGER CONSTRUCTOR " << endl;
        designation = "manager";
        this->bonus = bonus;
        this->mcount++;
    }
    int get_mcount()
    {
        return mcount;
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
    int scount;

public:
    Salesman()
    {
        // cout << "INSIDE  DEFAULT SALESMAN CONSTRUCTOR " << endl;
        designation = "salesman";
        scount++;
    }

    Salesman(int id, float sal, float comm) : Employee(id, sal)
    {
        // cout << "INSIDE SALESMAN CONSTRUCTOR " << endl;
        designation = "salesman";
        this->comm = comm;
        scount++;
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
    int smcount;

public:
    sales_manager()
    {
        // cout << "INSIDE  DEFAULT SALES MANAGER CONSTRUCTOR " << endl;
        designation = "salesmanager";
        smcount++;
    }

    sales_manager(int id, float sal, float bonus, float comm) : Manager(id, sal, bonus), Salesman(id, sal, comm)
    {
        // cout << "INSIDE SALES MANAGER CONSTRUCTOR " << endl;
        designation = "salesmanager";
        smcount++;
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

int menu()
{
    int choice;
    cout << "********************************************" << endl;
    cout << "1.ACCEPT EMPLOYEEE " << endl;
    cout << "2.COUNT OF EMPLOYEE IN EVERY DESIGNATAION" << endl;
    cout << "3.DESIGNATION OF EMPLOYEE" << endl;
    cout << "ENTER YOUR CHOICE ";
    cin >> choice;
    cout << "********************************************" << endl;
    return choice;
}
int submenu()
{
    int choice;
    cout << "********************************************" << endl;
    cout << "1.ACCEPT EMPLOYEEE for MANAGER " << endl;
    cout << "2.ACCEPT EMPLOYEEE for SALESMAN " << endl;
    cout << "3.ACCEPT EMPLOYEEE for SALES MANAGER " << endl;
    cout << "ENTER YOUR CHOICE ";
    cin >> choice;
    cout << "********************************************" << endl;
    return choice;
}
int submenu2()
{
    int choice;

    cout << "1.DISPLAY EMPLOYEEE for MANAGER ";
    cout << "2.DISPLAY EMPLOYEEE for SALESMAN ";
    cout << "1.DISPLAY EMPLOYEEE for SALES MANAGER ";
    cout << "ENTER YOUR CHOICE ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Employee *arr[10];
    int index = 0;
    int mcount = 0;
    int scount = 0;
    int smcount = 0;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            switch (submenu())
            {
            case 1:
                if (index < 10)
                {
                    arr[index] = new Manager();
                    arr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "ARRAY IS FULL CANNNOT INSERT" << endl;
                }
                break;

            case 2:
                if (index < 10)
                {
                    arr[index] = new Salesman();
                    arr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "ARRAY IS FULL CANNNOT INSERT" << endl;
                }
                break;
            case 3:
                if (index < 10)
                {
                    arr[index] = new sales_manager();
                    arr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "ARRAY IS FULL CANNNOT INSERT" << endl;
                }
                break;

            default:
                cout << "WRONG CHOICE............" << endl;
            }

            // case 2:
            //     switch (submenu2())
            //     {
            //     case 1:
            //         if (index < 10)
            //         {

            //             arr[index]->display();
            //         }
            //         else
            //         {

            //        }
            break;

        case 2:
            for (int i = 0; i < index; i++)
            {
                if (arr[i]->get_designation() == "manager")
                {
                    mcount++;
                }
                else if (arr[i]->get_designation() == "salesman")
                {
                    scount++;
                }
                else if (arr[i]->get_designation() == "salesmanager")
                {
                    smcount++;
                }
            }
            cout << "MANAGER COUNT = " << mcount << endl;
            cout << "SALESMAN COUNT = " << scount << endl;
            cout << "SALESMANAGER COUNT = " << smcount << endl;
            break;
        }
    }
    return 0;
}
