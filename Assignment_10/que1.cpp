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
        cout << "volume = " << volume;
        return 0;
    }
};

int menu()
{
    int choice;
    cout << "\n**************BOX VOLUME CALCULATION MENU******************\n";
    cout << "0.EXIT \n";
    cout << "1.ACCEPT DATA \n";
    cout << "2.DISPLAY DATA \n";
    cout << "3.VOLUME CALCULATION \n";
    cout << "ENTER CHOICE \n";
    cout << "********************\n";
    cin >> choice;
    cout << "*****************\n";
    return choice;
}

template <class t>
class Stack
{
    int size;
    int top;
    t *stack;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->stack = new t[size];
    }

    int get_size()
    {
        return this->size;
    }
     int get_top()
    {
        return this->top;
    }
    void push(t element)
    {

        if (top == size - 1)
        {
            cout << "STACK IS FULL" << endl;
        }
        else
        {
            // cout << "ENTER THE ELEMENT = ";
            // cin >> this->element;
            top = top + 1;
            stack[top] = element;
        }
    }

    void pop()
    {

        if (top > -1 && top < size)
        {
            cout << "POP ELEMMENT IS = " << stack[top] << endl;
            stack[top] = 0;
            top = top--;
        }
        else
        {
            cout << "STACK IS EMPTY....." << endl;
        }
    }

    void peek()
    {
        cout << stack[top] << endl;
    }

    void display_stack()
    {
        cout << "ELEMENTS ARE - " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << stack[i] << endl;
        }
    }
    ~Stack()
    {

        delete[] stack;
    }
};
int main()
{

    // Stack<int> s1(5);
    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // s1.push(4);
    // s1.peek();
    // s1.display_stack();
    // s1.pop();
    // s1.display_stack();

    // Stack <char> s1(5);

    // s1.push('a');
    // s1.push('b');
    // s1.push('c');
    // s1.peek();
    // s1.display_stack();
    // s1.pop();
    // s1.display_stack();

    // Stack<double> s1(5);

    // s1.push(1.2);
    // s1.push(3.4);
    // s1.push(4.2);
    // s1.peek();
    // s1.display_stack();
    // s1.pop();
    // s1.display_stack();

    Stack<Box *> b(5);
    b.push(new Box());
    b.push(new Box());
    b.push(new Box());
    b.push(new Box());
    b.push(new Box());

    for (int i = 0; i < b.get_size(); i++)
{
        b.get_top(i)->;
}

    b.peek();
    b.pop();
    b.display_stack();
}
