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
        if (i < 0 || i > size - 1)
            throw "Array index out of bounds .. ";
        return arr[i];
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
class Diagonal
{
public:
    Array arr;
    int size;
    Diagonal(int s = 0)
    {
        size = s;
        arr = Array(size);
    }
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (i != j)
            return 0;
        return arr[i - 1];
    }
    void set(int i, int j, int x)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (i != j && x != 0)
            throw "Non diagonal elements should not be non-zero\n";

        arr[i - 1] = x;
    }
};
class Tridiagonal
{
public:
    Array arr;
    int size;
    Tridiagonal(int s = 0)
    {
        size = 3 * s - 2;
        arr = Array(size);
    }
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (abs(i - j) > 1)
            return 0;
        return arr[2 + 3 * (i - 2) + j - i + 1];
    }
    void set(int i, int j, int x)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (abs(i - j) > 1 && x != 0)
            throw "Non tridiagonal elements should not be non-zero\n";
        arr[2 + 3 * (i - 2) + j - i + 1] = x;
    }
};
class Lower
{
public:
    Array arr;
    int size;
    Lower(int s = 0)
    {
        size = (s * (s + 1)) / 2;
        arr = Array(size);
    }
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (i < j)
            return 0;
        return arr[(i * (i - 1)) / 2 + j - 1];
    }
    void set(int i, int j, int x)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (i < j && x != 0)
            throw "Non lower triangle elements should not be non-zero\n";
        arr[(i * (i - 1)) / 2 + j - 1] = x;
    }
};
class Upper
{
public:
    Array arr;
    int size;
    Upper(int s = 0)
    {
        size = (s * (s + 1)) / 2;
        arr = Array(size);
    }
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (i > j)
            return 0;
        return arr[(j * (j - 1)) / 2 + i - 1];
    }
    void set(int i, int j, int x)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds\n";
        if (i > j && x != 0)
            throw "Non upper triangle elements should not be non-zero\n";
        arr[(j * (j - 1)) / 2 + i - 1] = x;
    }
};
class Symmetric
{
public:
    Array arr;
    int size;
    Symmetric(int s = 0)
    {
        size = (s * (s + 1)) / 2;
        arr = Array(size);
    }
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds";
        if (i < j)
            return arr[(j * (j - 1)) / 2 + i - 1];
        return arr[(i * (i - 1)) / 2 + j - 1];
    }
    void set(int i, int j, int x)
    {
        if (i < 1 || j < 1 || i > size || j > size)
            throw "Array index out of bounds";
        if (i < j)
            arr[(j * (j - 1)) / 2 + i - 1] = x;
        arr[(i * (i - 1)) / 2 + j - 1] = x;
    }
};
int main()
{
    int x;
    try
    {
        int s;
        cout << "1.Diagonal \n2.Tridiagonal \n3.Lower Triangle \n4.Upper Triangle \n5.Symmetric \n";
        cin >> s;
        int c = 1, i, j, x, d = 0;
        switch (s)
        {
        case 1:
        {
            cout << "Enter dimension: ";
            cin >> d;
            Diagonal arr1(d);
            while (c != 0)
            {
                cout << "Enter i,j,x (space seperated) to set values : ";
                cin >> i >> j >> x;
                arr1.set(i, j, x);
                cout << "any choice to continue, 0 to display matrix\n";
                cin >> c;
            }
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                    cout << arr1(i, j) << " ";
                cout << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Enter dimension: ";
            cin >> d;
            Tridiagonal arr2(d);
            while (c != 0)
            {
                cout << "Enter i,j,x (space seperated) to set values : ";
                cin >> i >> j >> x;
                arr2.set(i, j, x);
                cout << "any choice to continue, 0 to display matrix\n";
                cin >> c;
            }
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                    cout << arr2(i, j) << " ";
                cout << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter dimension: ";
            cin >> d;
            Lower arr3(d);
            while (c != 0)
            {
                cout << "Enter i,j,x (space seperated) to set values : ";
                cin >> i >> j >> x;
                arr3.set(i, j, x);
                cout << "any choice to continue, 0 to display matrix\n";
                cin >> c;
            }
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                    cout << arr3(i, j) << " ";
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter dimension: ";
            cin >> d;
            Upper arr4(d);
            while (c != 0)
            {
                cout << "Enter i,j,x (space seperated) to set values : ";
                cin >> i >> j >> x;
                arr4.set(i, j, x);
                cout << "any choice to continue, 0 to display matrix\n";
                cin >> c;
            }
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                    cout << arr4(i, j) << " ";
                cout << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Enter dimension: ";
            cin >> d;
            Symmetric arr5(d);
            while (c != 0)
            {
                cout << "Enter i,j,x (space seperated) to set values : ";
                cin >> i >> j >> x;
                arr5.set(i, j, x);
                cout << "any choice to continue, 0 to display matrix\n";
                cin >> c;
            }
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                    cout << arr5(i, j) << " ";
                cout << endl;
            }
            break;
        }
        }
    }
    catch (char const *msg)
    {
        cout << msg;
    }
}
