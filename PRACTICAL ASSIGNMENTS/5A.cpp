#include <iostream>
using namespace std;
typedef int Elem;
class Node
{
    Elem elem;
    Node *next;
    friend class SLL;
};
class SLL
{
protected:
    Node *head, *tail;

public:
    SLL()
    {
        head = 0;
        tail = 0;
    }
    bool empty()
    {
        return (!tail);
    }
    void addFront(Elem x)
    {
        Node *p = new Node;
        p->elem = x;
        p->next = head;
        head = p;
        if (!tail)
            tail = p;
    }
    void addtail(Elem x)
    {
        Node *p = new Node;
        p->elem = x;
        p->next = NULL;
        tail->next = p;
        tail = p;
        if (empty())
            head = p;
    }
    void add(Elem x, int pos)
    {
        Node *p = new Node;
        p->elem = x;
        Node *temp = head;
        if (pos == 1)
        {
            p->next = head;
            head = p;
            if (!tail)
                tail = p;
            return;
        }
        int count = 1;
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
            throw "INVALID POSITION";
        p->next = temp->next;
        temp->next = p;
        if (temp->next == NULL)
            tail = temp;
    }
    void removeFront()
    {
        if (head == 0)
            throw "Already Empty";
        if (head == tail)
        {

            delete[] head;
            head = 0;
            tail = 0;
        }
        else
        {
            Node *oldhead = head;
            head = head->next;
            delete oldhead;
        }
    }
    void pop(int pos)
    {
        Node *ptr = head;
        if (head == 0)
            throw "EMPTY LIST";
        if (pos == 1)
        {
            Node *oldhead = head;
            head = oldhead->next;
            delete oldhead;
            return;
        }
        int count = 1;
        while (ptr != NULL && count < pos - 1)
        {
            ptr = ptr->next;
            count++;
        }
        if (ptr == NULL)
            throw "INVALID POSITION";
        Node *old = ptr->next;
        ptr->next = old->next;
        delete old;
    }
    Node *search(Elem x)
    {
        Node *p = head;
        while (p)
        {
            if (p->elem == x)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
    void show()
    {
        if (empty())
        {
            cout << "BLANK\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->elem << "->";
            temp = temp->next;
        }
        cout << "NULL \n";
    }
    void concat(SLL &l2)
    {
        while (!l2.empty())
        {
            int x = l2.head->elem;
            l2.removeFront();
            this->addtail(x);
        }
    }
};