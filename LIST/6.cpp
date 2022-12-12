#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int size, top;
    Stack(int size = 20)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    bool empty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == size - 1;
    }
    void push(int x)
    {
        if (full())
            throw "Stack Overflow";
        arr[++top] = x;
    }
    int pop()
    {
        if (empty())
            throw "Stack Underflow";
        return arr[top--];
    }
    int topp()
    {
        if (empty())
            throw "Stack Empty";
        return arr[top];
    }
    void display()
    {
        while (!empty())
            cout << pop()<<" ";
        cout << endl;
    }
};
int main()
{
        Stack s;
        s.push(5);
        s.push(7);
        s.push(6);
        cout << s.topp();
        s.display();
    return 0;
}