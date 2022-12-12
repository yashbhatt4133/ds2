#include <iostream>
using namespace std;

void fib(int n, int a = 1, int b = 1)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }
    if (a > n)
        return;
    cout << a << " ";
    int c = a + b;
    a = b;
    b = c;
    fib(n, a, b);
}

int main()
{
    fib(6);
    return 0;
}