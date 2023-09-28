#include <iostream>
using namespace std;

class Matrix
{
    int length;
    int **arr;

 public:
    Matrix()
    {

        this->length = 3;

        arr = new int *[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = new int[length];
        }
    }
    Matrix(int length)
    {

        this->length = length;

        arr = new int *[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = new int[length];
        }
    }

    void accept()
    {
        cout << "ENTER ELEMENTS " << endl;

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {

                cout << "arr[" << i << "][" << j << "] = ";
                cin >> arr[i][j];
            }
        }
    }

    void print()
    {
        cout << " ELEMENTS  are = " << endl;

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {

                cout << "arr[" << i << "][" << j << "]=" << arr[i][j] << endl;
            }
        }
    }

    void add(Matrix m)
    {
        // int sum;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {

                cout << "SUM OF arr[" << i << "][" << j << "] = " << arr[i][j] + m.arr[i][j] << endl;
            }
        }
    }

    void sub(Matrix m)
    {

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int sub = 0;
                sub = this->arr[i][j] - m.arr[i][j];
                cout << " substraction OF arr[" << i << "][" << j << "] = " << sub << endl;
            }
        }
    }

    void multiply(Matrix m)
    {
        Matrix result;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int value = 0;
                for (int k = 0; k < length; k++)
                {
                    value = value + this->arr[i][k] * m.arr[k][j];
                }

                result.arr[i][j]=value;
                cout<< result.arr[i][j]<<"\t";
            }cout<<endl;
        }
    }


    ~Matrix(){
         for (int i = 0; i < length; i++)
        {
            delete arr[i];
        }
        delete[] arr;
    }
};

int main()
{

    Matrix m1(2);
    Matrix m2(2);
    m1.accept();
    m1.print();
    m2.accept();
    m2.print();
    m1.multiply(m2);
}