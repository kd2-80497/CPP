#include <iostream>
using namespace std;

class insufficient_funds
{

    int accid;
    double cur_balance;
    double withdraw_amount;

public:
    insufficient_funds(int accid, double cur_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void dispaly()
    {
        cout << "ERROR : INSUFICIENT_FUNDS_EXCEPTION" << endl;
        cout << "INSUFFICIENT BANK BALANCE  " << cur_balance << "CAN NOT WITHDRAW" << withdraw_amount << endl;
    }
};

enum Account_type
{

    SAVING = 1,
    CURRENT,
    DMAT

};

// Account_type menu()
// {
//     int choice;
//     cout << "0.EXIT" << endl;
//     cout << "1.SAVING ACCOUNT" << endl;
//     cout << "2.CURRENT ACCOUNT" << endl;
//     cout << "3.DMAT ACCOUNT " << endl;
//     cout << "ENTER CHOICE = ";
//     cin >> choice;
//     return Account_type(choice);
// }
class Account
{

    int id;
    Account_type type;
    double balance;

public:
    Account()
    {
        this->id = 0;

        this->balance = 0.0;
    }
    Account(int id)
    {
        this->id = id;

        // this->balance = balance;
    }

    void accept()
    {
        int choice;
        cout << "ENTER ACCOUNT ID = " << endl;
        cin >> id;

        cout << "ENTER ACCOUNT  TYPE " << endl;
        cout << "1.SAVING ACCOUNT " << endl;
        cout << "2.CURRENT ACCOUNT " << endl;
        cout << "3. DMAT ACCOUNT  " << endl;
        cin >> choice;
        this->type = Account_type(choice);
        cout << "ENTER ACCOUNT BALANCE  = " << endl;
        cin >> this->balance;
    }

    void display()
    {
        cout << "ACCOUNT ID = " << id << endl;
        switch (type)
        {
        case SAVING:
            cout << "ACCOUNT TYPE IS  SAVING " << endl;
            break;
        case CURRENT:
            cout << "ACCOUNT TYPE CURRENT " << endl;
            break;
        case DMAT:
            cout << "ACCOUNT TYPE DMAT " << endl;
            break;
        default:
            cout << "WRONG  ACCOUNT TYPE CHOoSEn" << endl;
            break;
        }
        cout << "ACCOUNT BALANCE = " << balance << endl;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_type(Account_type type)
    {
        this->type = type;
    }
    int get_id()
    {
        return id;
    }
    Account_type get_type()
    {
        return type;
    }

    double get_balance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        this->balance = this->balance + amount;
        cout << "BALANCE = " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (amount > this->balance)
            throw insufficient_funds(this->id, this->balance, amount);

        this->balance = this->balance - amount;
        cout << "BALANCE = " << balance << endl;
    }
};
int menu2()
{
    int choice;
    cout << "1.DEPOSIT " << endl;
    cout << "2.WITHDRAWAL" << endl;
    cout << "3.DISPLAY  ACCOUNT DETAILS" << endl;
    cout << "enter choice " << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int accno;
    int amount;

    int choice;
    Account *arr[2];
    int index = 0;
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new Account;
        arr[i]->accept();
    }

    while ((choice = menu2()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "ENTER BANK ID = ";
            cin >> accno;
            cout << "ENTER AMOUNT TO DEPOSIT ";
            cin >> amount;
            for (int i = 0; i < 2; i++)
            {

                if (arr[i]->get_id() == accno)
                {
                    arr[i]->deposit(amount);
                    break;
                }
                else
                {
                    cout << "NO ACCOUNT NUMBER EXIST...." << endl;
                    break;
                }
            }
            break;

        case 2:
            cout << "ENTER BANK ID = ";
            cin >> accno;
            cout << "ENTER AMOUNT TO withdraw ";
            cin >> amount;
            for (int i = 0; i < 2; i++)
            {

                if (arr[i]->get_id() == accno)
                {
                    try
                    {
                        arr[i]->withdraw(amount);
                    }
                    catch (insufficient_funds i)
                    {
                        i.dispaly();
                    }
                    break;
                }
                else{
                cout << "NO ACCOUNT NUMBER EXIST...." << endl;
                break;
                }
            }
            break;

        case 3:
            cout << "ENTER BANK ID = ";
            cin >> accno;
            for (int i = 0; i < 2; i++)
            {

                if (arr[i]->get_id() == accno)
                {
                    arr[i]->display();
                }
                cout << "NO ACCOUNT NUMBER EXIST...." << endl;
                break;
            }
            break;
        }
    }
}
