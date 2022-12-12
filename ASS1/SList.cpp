#include <iostream>
using namespace std;
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
class SLL
{
public:
    Node *head;
    Node *tail;
    int c;
    SLL()
    {
        head = NULL;
        tail = NULL;
    }
    int count(Node *p)
    {
        if (p == NULL)
            return 0;
        return (1 + count(p->next));
    }
    int count()
    {
        return count(head);
    }
    bool empty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    //1
    void add_head(int x)
    {
        Node *p = new Node(x);
        if (empty())
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
    void add_tail(int x)
    {
        Node *p = new Node(x);
        if (empty())
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    //2
    void insert(int i, int x)
    {
        Node *p = new Node(x);
        Node *temp = head;
        if (i == 0)
        {
            add_head(x);
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
            if (temp->next == NULL)
                tail = p;
            p->next = temp->next;
            temp->next = p;
        }
    }
    //3
    void remove_head()
    {
        if (empty())
            throw "List is empty";
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    void remove_tail()
    {
        if (empty())
            throw "List is empty";
        Node *prev = NULL;
        Node *temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        tail = prev;
        delete temp;
    }
    //4
    void remove(int i)
    {
        if (empty())
            throw "List is empty";
        if (i == 0)
        {
            remove_head();
            return;
        }
        Node *temp = head;
        int count = 0;
        while (count < i - 1 && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL)
            throw "Invalid Index";
        if (temp->next->next == NULL)
            tail = temp;
        Node *to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
    }
    void delete_x(int value)
    {
        if (empty())
            throw "List is empty";
        Node *ptr = head;
        Node *prev = NULL;
        while (ptr != NULL && ptr->data != value)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            throw "Invalid value";
        if (ptr->next == NULL)
            tail = prev;
        if (prev == NULL)
            head = head->next;
        else
            prev->next = ptr->next;
        delete ptr;
    }
    //5
    Node *search(int x)
    {
        if (empty())
            throw "List is empty";
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int get_head()
    {
        if (!empty())
            return head->data;
        throw "Empty List";
    }
    //6
    void concat(SLL l2)
    {
        this->tail->next = l2.head;
        this->tail = l2.tail;
        l2.head = NULL;
        l2.tail = NULL;
    }
};