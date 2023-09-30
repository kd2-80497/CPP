#include <iostream>
using namespace std;

class Product
{
    int id;
    string tittle;
    char type;
    float discount;
    float price;

public:
    Product()
    {
        id = 0;
        tittle = "";
        price = 0.0;
    }
    Product(int id, string tittle, float price)
    {
        this->id = id;
        this->tittle = tittle;
        this->price = price;
    }

    int getid()
    {
        return id;
    }
    void setid(int id)
    {
        this->id = id;
    }
    string gettittle()
    {
        return tittle;
    }
    void settittle(string tittle)
    {
        this->tittle = tittle;
    }
    float getprice()
    {
        return price;
    }
    void setprice(float price)
    {
        this->price = price;
    }
    char gettype()
    {
        return type;
    }
    void settype(char type)
    {
        this->type = type;
    }
    void accept()
    {
        cout << "ENTER ID = ";
        cin >> id;
        cout << "ENTER TITTLE = ";
        cin >> tittle;
        cout << "ENTER PRICE = ";
        cin >> price;
    }

    void display()
    {
        cout << "ID = " << id << endl;
        cout << "TITTLE = " << tittle << endl;
        cout << "PRICE = " << price << endl;
    }

    friend void calculate_bill(Product *arr[], int index);
};

class Book : public Product
{

    string author;

    char type;

public:
    Book()
    {
        author = "";
        settype('B');
    }

    Book(int id, string tittle, float price, string author) : Product(id, tittle, price)
    {
        this->author = author;
        settype('B');
    }
    void accept()
    {
        Product::accept();

        cout << "Enter author = ";
        cin >> author;
    }

    void display()
    {
        Product::display();
        cout << "AUTHOR = " << author;
    }
};

class Tape : public Product
{

    string artist;

    char type;
    float price;

public:
    Tape()
    {
        artist = "";
        settype('T');
    }

    Tape(int id, string tittle, float price, string artist) : Product(id, tittle, price)
    {
        this->artist = artist;
        settype('T');
    }
    void accept()
    {
        Product::accept();

        cout << "Enter ARTIST = ";
        cin >> artist;
    }

    void display()
    {
        Product::display();
        cout << "ARTIST = " << artist;
    }
};
int menu()
{
    int choice;
    cout << "***********************" << endl;
    cout << "0.EXIT" << endl;

    cout << "1.ADD BOOK" << endl;

    cout << "2.ADD TAPE" << endl;
    cout << "3.DISPLAY PRODUCTS" << endl;

    cout << "4.DISPLAY Bill" << endl;

    cout << "ENTER YOUR CHOICE";
    cin >> choice;
    cout << "**************************" << endl;
    return choice;
}
void calculate_bill(Product *arr[], int index)
{
    float total_price = 0;

    for (int i = 0; i < index; i++)
    {
        if (arr[i]->type == 'B')
        {

            float discount = arr[i]->price * 0.1;
            arr[i]->price = arr[i]->price - discount;
            total_price = arr[i]->price + total_price;
        }
        else
        {
            float discount = arr[i]->price * 0.05;
            arr[i]->price = arr[i]->price - discount;
            total_price = arr[i]->price + total_price;
        }
    }
    cout << "TOTAL PRICE = " << total_price << endl;
}

int main()
{
    int choice;
    Product *arr[3];
    int index = 0;

    while ((choice = menu()) != 0)
    {

        switch (choice)
        {

        case 1:
            if (index < 3)
            {
                arr[index] = new Book();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "PRODUCT IS FULL CAN NOT ADD PRODUCT" << endl;
            }
            break;

        case 2:
            if (index < 3)
            {
                arr[index] = new Tape();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "PRODUCT IS FULL CAN NOT ADD PRODUCT" << endl;
            }
            break;

        case 3:
            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }
            break;

        case 4:
            calculate_bill(arr, index);
            break;

        default:
            cout << "WRONG CHOICE" << endl;
            break;
        }
    }

    for (int i = 0; i < index; i++)
    {
        delete arr[i];
    }
    cout << "THANK YOU FOR SHOPPING........" << endl;
    return 0;
}