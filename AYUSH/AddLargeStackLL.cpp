#include <iostream>
#include "StackLL.cpp"
using namespace std;

string sum(string num1, string num2)
{
    StackLL s1;
    StackLL s2;
    StackLL s3;
    int carry = 0;
    for (int i = 0; i < num1.length(); i++)
        s1.push(num1[i] - '0');
    for (int i = 0; i < num2.length(); i++)
        s2.push(num2[i] - '0');
    while (!s1.is_empty() && !s2.is_empty())
    {
        s3.push((s1.top() + s2.top() + carry) % 10);
        carry = (s1.top() + s2.top() + carry) / 10;
        s1.pop();
        s2.pop();
    }
    while (!s1.is_empty())
    {
        s3.push((s1.top() + carry) % 10);
        carry = (s1.top() + carry) / 10;
        s1.pop();
    }
    while (!s2.is_empty())
    {
        s3.push((s2.top() + carry) % 10);
        carry = (s2.top() + carry) / 10;
        s2.pop();
    }
    if (carry != 0)
        s3.push(carry);
    string ans = "";
    while (!s3.is_empty())
        ans = ans + (char)(s3.pop() + '0');
    return ans;
}
int main()
{
    string num1, num2;
    cout << "Enter first number";
    cin >> num1;
    cout << "Enter second number";
    cin >> num2;
    cout << sum(num1, num2) << endl;

    return 0;
}