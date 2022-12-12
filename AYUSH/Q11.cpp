#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    bool is_empty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    void insert_at_head(int x)
    {
        Node *p = new Node(x);
        if (is_empty())
        {
            head = p;
            tail = p;
        }
        else
        {
            p->next = head;
            head = p;
        }
    }
    void delete_head()
    {
        if (is_empty())
            throw "List is empty";
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    int get_head()
    {
        if (is_empty())
            throw "Empty List";
        return head->data;
    }
    List reverse()
    {
        // cout << "A";
        // cout << "A";
        List making;
        if (is_empty())
            throw "List is empty";
        // cout << "B";
        Node *t = head;
        int c = 0;
        while (t != NULL)
        {
            // cout << c++ << endl;
            making.insert_at_head(get_head());
            t = t->next;
            delete_head();
        }
        return making;
    }
    void display()
    {
        if (is_empty())
            throw "Nothing to display";
        Node *t = head;
        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};
int main()
{
    List list;
    list.insert_at_head(2);
    list.insert_at_head(5);
    list.insert_at_head(6);
    list.insert_at_head(1);
    list.insert_at_head(4);
    list.insert_at_head(21);
    list.insert_at_head(12);
    list.display();

    List newlist = list.reverse();
    newlist.display();
}