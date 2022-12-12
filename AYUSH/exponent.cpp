#include <iostream>
using namespace std;
int pow(int b, int e)
{
    if (e != 0)
        return (b * pow(b, e - 1));
    else
        return 1;
}
int main()
{
    cout << pow(2, 4);
}