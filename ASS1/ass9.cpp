#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int s1, s2, temp, k, count, sum;
    cout << "Enter size of stack A : ";
    cin >> s1;
    cout << "Enter size of stack B : ";
    cin >> s2;
    stack<int> a;
    stack<int> b;
    cout << "Enter Elements of stack A : ";
    for (int i = 0; i < s1; i++)
    {
        cin >> temp;
        a.push(temp);
    }
    cout << "Enter Elements of stack B : ";
    for (int i = 0; i < s2; i++)
    {
        cin >> temp;
        b.push(temp);
    }
    cout << "Enter K (max sum) : ";
    cin >> k;
    sum = 0;
    count=0;
    while (sum <= k)
    {
        if (!a.empty() && !b.empty())
        {
            if (a.top() < b.top())
            {
                sum += a.top();
                a.pop();
                count++;
            }
            else
            {
                sum += b.top();
                b.pop();
                count++;
            }
        }
        else if (a.empty() && b.empty())
        {
            break;
        }
        else if (a.empty() && !b.empty())
        {
            sum += b.top();
            b.pop();
            count++;
        }
        else
        {
            sum += a.top();
            a.pop();
            count++;
        }
    }
    cout<<"TOTAL ELEMENTS REMOVED : "<<count<<"\n";
    return 0;
}
