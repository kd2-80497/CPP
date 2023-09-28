#include <iostream>
using namespace std;

class Student
{

    string name;
    string gender;
    int roll_no;
    float m1, m2, m3;
    static int length;

public:
    Student()
    {
        length++;
    }

    Student(string name, string gender, int roll_no)
    {
        length++;
        this->name = name;
        this->gender = gender;
        this->roll_no = roll_no;
    }

    void accept()
    {
        cout << "ENTER NAME = ";
        cin >> name;
        cout << "ENTER ROLL NO = ";
        cin >> roll_no;
        cout << "ENTER GENDER = ";
        cin >> gender;
        cout << "ENTER MARKS  FOR SUBJECT 1 = ";
        cin >> m1;
        cout << "ENTER MARKS  FOR SUBJECT 2 = ";
        cin >> m2;
        cout << "ENTER MARKS  FOR SUBJECT 3 = ";
        cin >> m3;
    }

    void display()
    {
        cout << "*************STUDENT DETAILS*******" << endl;
        cout << "NAME = " << name << endl;
        cout << "ROLL NO = " << roll_no << endl;
        cout << "GENDER = " << gender << endl;
        cout << "MARKS SUBJECT 1 = " << m1 << endl;
        cout << "MARKS SUBJECT 2 = " << m2 << endl;
        cout << "MARKS SUBJECT 3 = " << m3 << endl;
        cout << "PERCENTAGE = " << percentage() << endl;
    }

    int percentage()
    {
        int percentage = ((m1 + m2 + m3) / 300) * 100;
        return percentage;
    }

    static int get_length()
    {
        return length;
    }
    int getroll_no()
    {
        return roll_no;
    }
};

int Student::length = 0;
void sortRecords(Student arr[], int n)
{
    Student temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].getroll_no() > arr[j].getroll_no())
            {
                Student small = arr[j];
                Student large = arr[i];
                temp = large;
                large = small;
                small = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {

        arr[i].display();
    }
}

int searchRecords(Student arr[], int n)
{
    int key;

    cout << "ENTER ROLL NO TO SEARCH ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].getroll_no() == key)
            return i;
    }

    return -1;
}

int menu()
{
    int choice;
    cout << "***************MENU******************" << endl;
    cout << "1.ACCEPT STUDENT DATA" << endl;
    cout << "2.DISPLAY STUDENT DATA" << endl;
    cout << "3.SEARCH ROLL NO IN  STUDENT DATA" << endl;
    cout << "1.SORT STUDENT DATA" << endl;
    cout << "ENTER YOUR CHOICE " << endl;
    cin >> choice;
    return choice;
}
int main()
{
    Student st1;
    Student st2;

    // Student st("ANSHI", "FEMALE", 112);
    int len = st1.get_length();
    Student arr[len];
    // st.accept();
    int i = 0;
    // st.display();
    // st1.accept();
    //  st1.display();

    // searchRecords(arr, len);

    int choice;
    while ((choice = menu()) != 0)
    {

        switch (choice)
        {

        case 1:
            if (i < len)
            {
                arr[i].accept();
                i++;
            }
            else
            {
                cout << "CLASS IS FULL" << endl;
            }
            break;
        case 2:
            for (int i = 0; i < len; i++)
            {

                arr[i].display();
            }

            break;
        case 3:
            int index;
            index = searchRecords(arr, len);
            if (index == -1)
            {
                cout << "ROLL NO NOT FOUND " << endl;
            }
            else
            {
                cout << "INDEX IS = " << index << endl;
            }
            break;

        case 4:
            sortRecords(arr, len);

            break;
        }
    }
}