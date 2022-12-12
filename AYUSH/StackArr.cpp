#include <iostream>
using namespace std;
class StackArr
{
public:
    int *arr;
    int size, top;
    StackArr(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    bool is_empty()
    {
        return top == -1;
    }
    bool is_full()
    {
        return top == size - 1;
    }
    void push(int x)
    {
        if (is_full())
            throw "Stack Overflow";
        arr[++top] = x;
    }
    int pop()
    {
        if (is_empty())
            throw "Stack Underflow";
        return arr[top--];
    }
    int top_ele()
    {
        if (is_empty())
            throw "Stack Empty";
        return arr[top];
    }
    void display()
    {
        while (!is_empty())
            cout << pop();
        cout << endl;
    }
};
int main()
{
    try
    {
        StackArr s;
        s.push(5);
        s.push(7);
        s.push(6);
        cout << s.top_ele();
        s.display();
    }
    catch (char const *msg)
    {
        cout << msg;
    }
    return 0;
}