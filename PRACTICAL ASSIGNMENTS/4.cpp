#include <iostream>
using namespace std;
class Array1D
{
    int size;
    int *arr;

public:
    // constructor
    Array1D(int size = 0)
    {
        if (size < 0)
            throw "Bad Initialisation";
        this->size = size;
        arr = new int[size];
    }
    void setall(int x=0){
        for(int i =0;i<size;i++)
            arr[i] = x;
    }
    int getSize() const { return size; }
    // resize and copy initial elements
    void reSize(int s)
    {
        if (s < 0)
            throw "Bad thing";
        if (size != s)
        {
            int n = (s > size) ? size : s;
            int *tarr = new int[s];
            for (int i = 0; i < n; i++)
            {
                tarr[i] = arr[i];
            }
            delete[] arr;
            arr = tarr; // reassign pointer
            size = s;
        }
    }
    // copy-constructor
    Array1D(const Array1D &a)
    {
        size = a.getSize();
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a.arr[i];
        }
    }
    // destructor
    ~Array1D()
    {
        delete[] arr;
    }
    // safe-array-accessor
    int &operator[](int i) const
    {
        if (i < 0 || i >= size)
        {
            throw "Invalid Index";
        }
        return arr[i];
    }

    // input->>
    friend istream &operator>>(istream &in, Array1D &a)
    {
        cout << "Enter " << a.getSize() << " elements : ";
        for (int i = 0; i < a.getSize(); i++)
        {
            in >> a[i];
        }
        return in;
    }
    // output-<<
    friend ostream &operator<<(ostream &out, Array1D &a)
    {
        out << "{ ";
        for (int i = 0; i < a.getSize(); i++)
        {
            out << a[i] << " ";
        }
        out << "}\n";
        return out;
    }
    // arithmetic-operations
    Array1D operator+(const Array1D &obj);
    Array1D operator-(const Array1D &obj);
    Array1D operator*(const Array1D &obj);
    Array1D operator/(const Array1D &obj);
    Array1D operator*(int n)
    {
        Array1D temp(this->getSize());
        for (int i = 0; i < this->getSize(); i++)
        {
            temp[i] = ((*this)[i] * n);
        }
        return temp;
    }
    // void operator=(const Array1D& a){
    //     size = a.getSize();
    //     delete [] arr;
    //     arr = new int[size];
    //     for(int i =0;i<size;i++){
    //         arr[i] = a.arr[i];
    //     }
    // }
    Array1D operator=(const Array1D &a)
    {
        size = a.getSize();
        delete[] arr;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a.arr[i];
        }
        return (*this);
    }
};
Array1D Array1D::operator+(const Array1D &obj)
{
    if (this->getSize() != obj.getSize())
    {
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = ((*this)[i] + obj.arr[i]);
    }
    return temp;
}
Array1D Array1D::operator-(const Array1D &obj)
{
    if (this->getSize() != obj.getSize())
    {
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = ((*this)[i] - obj.arr[i]);
    }
    return temp;
}
Array1D Array1D::operator*(const Array1D &obj)
{
    if (this->getSize() != obj.getSize())
    {
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = ((*this)[i] * obj.arr[i]);
    }
    return temp;
}
Array1D Array1D::operator/(const Array1D &obj)
{
    if (this->getSize() != obj.getSize())
    {
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = ((*this)[i] / obj.arr[i]);
    }
    return temp;
}
class DiagonalMatrix
{
private:
    int n;
    Array1D elements;

public:
    // constructor
    DiagonalMatrix(int n = 0)
    {
        this->n = n;
        elements = Array1D(n);
        elements.setall(0);
    }
    // copy-constructor
    DiagonalMatrix(const DiagonalMatrix &d)
    {
        n = d.n;
        elements = Array1D(d.elements);
    }
    // destructor not needed
    // safe-accessor 1-indexed
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (i != j)
            return 0;
        else
            return elements[i - 1];
    }
    // store
    DiagonalMatrix &Store(const int &x, int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (i != j && x != 0)
            throw "Non-Diagonal Element Must Be Zero";
        if (i == j)
            elements[i - 1] = x;
        return (*this);
    }
    // retrieve
    int Retrieve(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (i != j)
            return 0;
        else
            return elements[i - 1];
    }
    // printing matrix
    friend ostream &operator<<(ostream &out, DiagonalMatrix &d)
    {
        for (int i = 1; i <= d.n; i++)
        {
            for (int j = 1; j <= d.n; j++)
            {
                out << d(i, j) << "\t";
            }
            cout << "\n";
        }
        return out;
    }
};
class LTMatrix
{
private:
    int n;
    Array1D elements;

public:
    // constructor
    LTMatrix(int n = 0)
    {
        this->n = n;
        elements = Array1D((n * (n + 1)) / 2);
        elements.setall(0);
    }
    // copy-constructor
    LTMatrix(const LTMatrix &lt)
    {
        n = lt.n;
        elements = Array1D(lt.elements);
    }
    // destructor not needed
    //  safe-accessor 1-indexed ,storing row wise k = (i*(i-1))/2 +j-1 , i>=j
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j > i)
            return 0;
        return elements[(i * (i - 1)) / 2 + j - 1];
    }
    // store
    LTMatrix &Store(const int &x, int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j > i && x != 0)
            throw "Non-LT Element Must Be Zero";
        else if (i >= j)
            elements[(i * (i - 1)) / 2 + j - 1] = x;
        return (*this);
    }
    // retrieve
    int Retrieve(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j > i)
            return 0;
        return elements[(i * (i - 1)) / 2 + j - 1];
    }
    // printing matrix
    friend ostream &operator<<(ostream &out, LTMatrix &d)
    {
        for (int i = 1; i <= d.n; i++)
        {
            for (int j = 1; j <= d.n; j++)
            {
                out << d(i, j) << "\t";
            }
            cout << "\n";
        }
        return out;
    }
};
class UTMatrix
{

private:
    int n;
    Array1D elements;

public:
    // constructor
    UTMatrix(int n = 0)
    {
        this->n = n;
        elements = Array1D((n * (n + 1)) / 2);
        elements.setall(0);
    }
    // copy-constructor
    UTMatrix(const UTMatrix &ut)
    {
        n = ut.n;
        elements = Array1D(ut.elements);
    }
    // destructor not needed
    //  safe-accessor 1-indexed ,storing column wise k = (j*(j-1))/2 +i-1 , j>=i
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j < i)
            return 0;
        return elements[(j * (j - 1)) / 2 + i - 1];
    }
    // store
    UTMatrix &Store(const int &x, int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (i > j && x != 0)
            throw "Non-UT Element Must Be Zero";
        else if (j >= i)
            elements[(j * (j - 1)) / 2 + i - 1] = x;
        return (*this);
    }
    // retrieve
    int Retrieve(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j < i)
            return 0;
        return elements[(j * (j - 1)) / 2 + i - 1];
    }
    // printing matrix
    friend ostream &operator<<(ostream &out, UTMatrix &ut)
    {
        for (int i = 1; i <= ut.n; i++)
        {
            for (int j = 1; j <= ut.n; j++)
            {
                out << ut(i, j) << "\t";
            }
            cout << "\n";
        }
        return out;
    }
};
class SymmetricMatrix
{
    // stored as lower triangle
private:
    int n;
    Array1D elements;

public:
    // constructor
    SymmetricMatrix(int n = 0)
    {
        this->n = n;
        elements = Array1D((n * (n + 1)) / 2);
        elements.setall(0);
    }
    // copy-constructor
    SymmetricMatrix(const SymmetricMatrix &lt)
    {
        n = lt.n;
        elements = Array1D(lt.elements);
    }
    // destructor not needed
    //  safe-accessor 1-indexed ,storing row wise k = (i*(i-1))/2 + j -1,i>=j
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j > i)
            return elements[(j * (j - 1)) / 2 + i - 1];
        return elements[(i * (i - 1)) / 2 + j - 1];
    }
    // store-updates lower triangle always
    SymmetricMatrix &Store(const int &x, int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        if (j > i)
            elements[(j * (j - 1)) / 2 + i - 1] = x;
        else
            elements[(i * (i - 1)) / 2 + j - 1] = x;
        return (*this);
    }
    // retrieves from lower triangle always
    int Retrieve(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (j > i)
            return elements[(j * (j - 1)) / 2 + i - 1];
        return elements[(i * (i - 1)) / 2 + j - 1];
    }
    // printing matrix
    friend ostream &operator<<(ostream &out, SymmetricMatrix &d)
    {
        for (int i = 1; i <= d.n; i++)
        {
            for (int j = 1; j <= d.n; j++)
            {
                out << d(i, j) << "\t";
            }
            cout << "\n";
        }
        return out;
    }
};
class TDMatrix
{
private:
    int n;
    Array1D elements;

public:
    // constructor
    TDMatrix(int n = 0)
    {
        this->n = n;
        elements = Array1D(3 * n - 2);
        elements.setall(0);
    }
    // copy-constructor
    TDMatrix(const TDMatrix &td)
    {
        n = td.n;
        elements = Array1D(td.elements);
    }
    // destructor not needed
    // safe-accessor 1-indexed ,storing row wise k = 2i+j-3
    int operator()(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (abs(i - j) > 1)
            return 0;
        return elements[2 * i + j - 3];
    }
    // store
    TDMatrix &Store(const int &x, int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (abs(i - j) > 1 && x != 0)
            throw "Non-Tri-Diagonal Element Must Be Zero";
        elements[2 * i + j - 3] = x;
        return (*this);
    }
    // retrieve
    int Retrieve(int i, int j)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw "IndexOutOfBounds";
        else if (abs(i - j) > 1)
            return 0;
        return elements[2 * i + j - 3];
    }
    // printing matrix
    friend ostream &operator<<(ostream &out, TDMatrix &td)
    {
        for (int i = 1; i <= td.n; i++)
        {
            for (int j = 1; j <= td.n; j++)
            {
                out << td(i, j) << "\t";
            }
            cout << "\n";
        }
        return out;
    }
};
int main()
{
    cout << "Which Matrix Do you want to store ?\n";
    cout << "1.Diagonal Matrix\n";
    cout << "2.Tri-Diagonal Matrix\n";
    cout << "3.Upper Triangle Matrix\n";
    cout << "4.Lower Triangle Matrix\n";
    cout << "5.Symmetric Matrix\n";
    int x, N, r, c, v;
    cout << "Enter your choice(1-5) >>";
    cin >> x;
    if (x == 1)
    {
        cout<<"DIAGONAL MATRIX\n";
        cout << "Enter Size of matrix (square)>>";
        cin >> N;
        DiagonalMatrix d1(N);
        cout << "How many Elements do you want to insert ? >>";
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            cout << "For element " << i << " Enter value >>";
            cin >> v;
            cout << "Enter row and column (space Separated) >>";
            cin >> r >> c;
            d1.Store(v, r, c);
        }
        cout << "Your Matrix =\n"
             << d1;
    }
    else if (x == 2)
    {
        cout<<"TRI-DIAGONAL MATRIX\n";
        cout << "Enter Size of matrix (square)>>";
        cin >> N;
        TDMatrix d2(N);
        cout << "How many Elements do you want to insert ? >>";
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            cout << "For element " << i << " Enter value >>";
            cin >> v;
            cout << "Enter row and column (space Separated) >>";
            cin >> r >> c;
            d2.Store(v, r, c);
        }
        cout << "Your Matrix =\n"
             << d2;
    }
    else if (x == 3)
    {
        cout<<"UT MATRIX\n";
        cout << "Enter Size of matrix (square)>>";
        cin >> N;
        UTMatrix d3(N);
        cout << "How many Elements do you want to insert ? >>";
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            cout << "For element " << i << " Enter value >>";
            cin >> v;
            cout << "Enter row and column (space Separated) >>";
            cin >> r >> c;
            d3.Store(v, r, c);
        }
        cout << "Your Matrix =\n"
             << d3;
    }
    else if (x == 4)
    {
        cout<<"LT MATRIX\n";
        cout << "Enter Size of matrix (square)>>";
        cin >> N;
        LTMatrix d4(N);
        cout << "How many Elements do you want to insert ? >>";
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            cout << "For element " << i << " Enter value >>";
            cin >> v;
            cout << "Enter row and column (space Separated) >>";
            cin >> r >> c;
            d4.Store(v, r, c);
        }
        cout << "Your Matrix =\n"
             << d4;
    }
    else if (x == 5)
    {
        cout<<"SYMMETRIC MATRIX\n";
        cout << "Enter Size of matrix (square)>>";
        cin >> N;
        SymmetricMatrix d5(N);
        cout << "How many Elements do you want to insert ? >>";
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            cout << "For element " << i << " Enter value >>";
            cin >> v;
            cout << "Enter row and column (space Separated) >>";
            cin >> r >> c;
            d5.Store(v, r, c);
        }
        cout << "Your Matrix =\n"
             << d5;
    }
    else
    {
        cout << "WRONG INPUT , quitting Program\n";
    }
    return 0;
}
