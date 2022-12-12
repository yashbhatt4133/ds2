#include <iostream>
using namespace std;
// template <typename T>
class Node
{
public:
    int data;
    Node *next;
    Node(int x = 0)
    {
        data = x;
        next = NULL;
    }
};
// template <typename T>
class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
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
        }
        else
        {
            p->next = head;
            head = p;
        }
    }
    void insert_at(int i, int x)
    {
        Node *p = new Node(x);
        Node *temp = head;
        if (i == 0)
        {
            insert_at_head(x);
            return;
        }
        int c = 1;
        while (temp != NULL && c < i)
        {
            temp = temp->next;
            c++;
        }
        if (temp == NULL)
            throw "Invalid Index";
        else
        {
            p->next = temp->next;
            temp->next = p;
        }
    }
    void insert(int x)
    {
        int c = 0;
        Node *temp = head;
        while (temp != NULL && x < temp->data)
        {
            temp = temp->next;
            c++;
        }
        insert_at(c, x);
    }
    void deleteAt(int i)
    {
        if (is_empty())
            throw "List is empty";
        int c = 0;
        Node *t = head;
        if (i == 0)
        {
            head = t->next;
            delete t;
            return;
        }
        while (t->next != NULL && c < i - 1)
        {
            t = t->next;
            c++;
        }
        Node *to_delete = t->next;
        t->next = t->next->next;
        delete to_delete;
    }
    void remove(List l2)
    {
        if (l2.is_empty())
            return;
        Node *temp = l2.head;
        while (temp != NULL)
        {
            deleteAt(temp->data);
            temp = temp->next;
        }
    }
    void display()
    {

        if (is_empty())
            throw "Nothing to display";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    try
    {

        List list1;
        List list2;
        list1.insert_at_head(1);
        list1.insert_at_head(2);
        list1.insert_at_head(3);
        list1.insert_at_head(4);
        list1.display();

        list2.insert(0);
        list2.insert(1);
        list2.insert(2);
        list2.insert(3);

        list1.remove(list2);

        list2.display();
        list1.display();
    }
    catch (char const *msg)
    {
        cout << msg;
    }

    return 0;
}