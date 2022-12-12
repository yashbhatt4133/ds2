#include <iostream>
#include "DList.cpp"
using namespace std;
class Number : public DList
{
public:
    void input()
    {
        string number;
        cin >> number;
        int len = number.length();
        string temp = number;
        while (temp.length() >= 8)
        {
            // DNode *p = new DNode(stol(temp.substr(temp.length() - 1, temp.length() - 8)));
            insert_at_head(stol(temp.substr(temp.length() - 8, temp.length() - 1)));
            temp = temp.substr(0, temp.length() - 8);
        }
        if (temp != "")
        {
            insert_at_head(stol(temp));
        }
    }
    void add(Number n1, Number n2)
    {
        long carry = 0, sum = 0;
        while (!n1.isempty() && !n2.isempty())
        {
            sum = n1.get_tail() + n2.get_tail() + carry;
            n1.delete_back();
            n2.delete_back();
            carry = sum / 100000000;
            sum = sum % 100000000;
            // cout << "sum=" << sum << " carry= " << carry;
            this->insert_at_head(sum);
        }
        while (!n1.isempty())
        {
            this->insert_at_head(n1.get_tail() + carry);
            carry = 0;
            n1.delete_back();
        }
        while (!n2.isempty())
        {
            this->insert_at_head(n2.get_tail() + carry);
            carry = 0;
            n2.delete_back();
        }
    }
    void display_number()
    {
        DNode *temp = header->next;
        while (temp->next != NULL)
        {
            cout << temp->d;
            temp = temp->next;
        }
    }
};
int main()
{
    Number n1;
    n1.input();
    // n1.display();

    Number n2;
    n2.input();
    // n2.display();

    Number ans;
    ans.add(n1, n2);
    ans.display_number();
}