#include <iostream>
using namespace std;
class Array1D
{
public:
    int *arr;
    int s;
    Array1D(int s = 0)
    {
        if (s < 0)
        {
            throw "Invalid Size";
        }
        this->s = s;
        arr = new int[s];
    }

    int &operator[](int i)
    {
        if (i < 0 || i >= s)
        {
            throw "Invalid Index";
        }
        return arr[i];
    }
    int getSize() const
    {
        return s;
    }
    void reSize(int size)
    {
        if (s == size)
            return;
        delete[] arr;
        s = size;
        arr = new int[s];
    }
    Array1D operator+(Array1D a)
    {
        if ((a.s) != (*this).s)
        {
            throw "Length of arrays should be same for addition";
        }
        Array1D ans(s);
        for (int i = 0; i < s; i++)
        {
            ans[i] = (*this)[i] + a[i];
        }
        return ans;
    }
    Array1D operator-(Array1D a)
    {
        if ((a.s) != (*this).s)
        {
            throw "Length of arrays should be same for addition";
        }
        Array1D ans(s);
        for (int i = 0; i < s; i++)
        {
            ans[i] = (*this)[i] - a[i];
        }
        return ans;
    }
    Array1D operator=(Array1D a)
    {
        s = a.getSize();
        delete[] arr;
        arr = new int[s];
        for (int i = 0; i < s; i++)
        {
            arr[i] = a[i];
        }
        return (*this);
    }
    friend istream &operator>>(istream &in, Array1D &a)
    {
        if (a.s == 0)
        {
            cout << "Array size is 0";
        }
        else
        {
            cout << "Enter the elements" << endl;
            for (int i = 0; i < a.s; i++)
            {
                cin >> a[i];
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Array1D &a)
    {
        if (a.s == 0)
        {
            cout << "Array is empty";
        }
        else
        {
            cout << "Enter the elements" << endl;
            for (int i = 0; i < a.s; i++)
            {
                cout << a[i] << endl;
            }
        }
        return out;
    }
};
// int main()
// {
//     Array1D a(2);
//     a[1]=2;
//     cout<<a[1];
// }