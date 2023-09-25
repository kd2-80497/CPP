#include <iostream>
using namespace std;

class Stack
{
    int size;
    int element;
    int *arr;
    int top;

public:
    Stack()
    {
        this->size = 5;
        top = -1;
        arr = new int[size]; 
    }
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push()
    {
        if (top == size-1)
        {
            cout << "STACK IS FULL" << endl;
        }
        else
        {
            cout << "ENTER THE ELEMENT = ";
            cin >> this->element;
            top = top + 1;
            arr[top] = element;
        }
    }

    void pop()
    {
        if (top > -1 && top < size)
        arr[top] = 0;
        top = top - 1;
    }
    void peek()
    {
        cout << "ELEMENT IS = " << arr[top] << endl;
    }

    void isEmpty()
    {
        if (top < size - 1)
            cout << "STILL SPACE IN STACK" << endl;
        else
            cout << "STACK IS FULL" << endl;
    }

    void isFull()
    {
        if (top == size-1)
            cout << "STACK IS FULL" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{

    Stack st(6);
    st.push();
    st.push();
    st.push();
    st.push();
    st.push();
    st.pop();
    st.peek();
    st.isFull();
    st.isEmpty();
    st.print();
}