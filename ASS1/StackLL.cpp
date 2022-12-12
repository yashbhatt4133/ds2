#include <iostream>
#include "SList.cpp"
using namespace std;
class StackLL
{
public:
    SList stack;
    StackLL()
    {
    }
    bool is_empty()
    {
        return stack.is_empty();
    }
    int pop()
    {
        if (is_empty())
            throw "Stack Underflow";
        int x = stack.get_head();
        stack.delete_front();
        return x;
    }
    void push(int x)
    {
        stack.insert_at_head(x);
    }
    int top()
    {
        if (is_empty())
            throw "Stack Underflow";
        return stack.get_head();
    }
    void display()
    {
        while (!is_empty())
        {
            cout << pop() << " ";
        }
        cout << endl;
    }
};

// int main()
// {
//     try
//     {
//         StackLL s;
//         s.push(5);
//         s.push(7);
//         s.push(8);
//         s.pop();
//         s.pop();
//         s.pop();
//         s.pop();
//         s.display();
//     }
//     catch (char const *msg)
//     {
//         cout << msg;
//     }
//     return 0;
// }