#include <iostream>
#include <stack>
using namespace std;
int main()
{
    cout << "Enter k: ";
    int k;
    cin >> k;
    // filling random values in stacks of random length
    stack<int> s1;
    cout << "1st stack:" << endl;
    for (int i = 0; i < (rand() % 10) + 1; i++)
    {
        int t = (rand() % 20) + 1;
        cout << t << " ";
        s1.push(t);
    }
    cout << endl;
    stack<int> s2;
    cout << "1st stack:" << endl;
    for (int i = 0; i < (rand() % 10) + 1; i++)
    {
        int t = (rand() % 20) + 1;
        cout << t << " ";
        s2.push(t);
    }
    cout << endl;

    // start of main logic
    int count = 0, sum = 0;
    while (sum < k)
    {
        if (s1.size() != 0 && s2.size() != 0)
        {

            if (s1.top() < s2.top())
            {
                sum += s1.top();
                s1.pop();
            }
            else
            {
                sum += s2.top();
                s2.pop();
            }
            if (sum >= k)
                break;
            count++;
        }
        else
        {
            if (s1.size() != 0)
            {
                sum += s1.top();
                s1.pop();
            }
            if (s2.size() != 0)
            {
                sum += s2.top();
                s2.pop();
            }
            if (sum >= k)
                break;
            count++;
            if (s1.size() == 0 && s2.size() == 0)
                break;
        }
    }
    cout << "count = " << count << endl;
}
// k=22
// s1=1 1 1 9 9 1
// s2=8 8 8 8 8 8