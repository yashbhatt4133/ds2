#include <iostream>
using namespace std;
class Array
{
public:
    int *arr;
    int size;
    Array(int s = 0)
    {
        size = s;
        arr = new int[size];
    }
    void resize(int new_size)
    {
        if (size == new_size)
            return;
        if (new_size < 0)
            throw "Invalid Size";
        delete[] arr;
        size = new_size;
        arr = new int[size];
    }
    int &operator[](int i)
    {
        if (i >= 0 && i < size)
            return arr[i];
        throw "Array index out of bounds";
    }
    int getSize()
    {
        return size;
    }
    Array operator+(Array a)
    {
        if (size != a.size)
            throw "Arrays need to be equal";
        Array sum(size);
        for (int i = 0; i < size; i++)
        {
            sum[i] = (*this)[i] + a[i];
        }
        return sum;
    }
    friend ostream &operator<<(ostream &out, Array &a)
    {
        if (a.size == 0)
            cout << "{}";
        else
        {
            cout << "{";
            for (int i = 0; i < a.size; i++)
            {
                if (i != 0)
                    cout << ",";
                cout << a[i];
            }
            cout << "}";
        }
        return out;
    }
    friend istream &operator>>(istream &in, Array &a)
    {
        if (a.size == 0)
            cout << "Array is empty";
        else
        {
            for (int i = 0; i < a.size; i++)
            {
                cin >> a[i];
            }
        }
        return in;
    }
};