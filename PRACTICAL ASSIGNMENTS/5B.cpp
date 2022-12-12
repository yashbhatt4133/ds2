#include <iostream>
using namespace std;
typedef int Elem;
class Node
{
public:
    Elem elem;
    Node *next;
    friend class SLL;
    friend class SSLL;
    // friend SSLL merge(const SSLL &l1, const SSLL &l2);
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
    SLL(const SLL &l1)
    {
        Node *p = l1.head;
        while (p != NULL)
        {
            addtail(p->elem);
            p = p->next;
        }
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
        if (!head)
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

class SSLL : public SLL
{
public:
    SSLL(const SLL &l1)
    {
        Node *p = l1.head;
        while (p != NULL)
        {
            insert(p->elem);
            p = p->next;
        }
    }
    void insert(int x)
    {
        Node *p = head;
        Node *prev = NULL;
        while (p != NULL && p->elem < x)
        {
            prev = p;
            p = p->next;
        }
        if (prev == NULL)
            addFront(x);
        else if (p == NULL)
            addtail(x);
        else
        {
            Node *nn = new Node;
            nn->elem = x;
            prev->next = nn;
            nn->next = p;
        }
    }
    friend SSLL merge(const SSLL &l1, const SSLL &l2);
};

// SSLL merge(const SSLL &l1, const SSLL &l2)
// {
//     Node *p1 = l1.head;
//     Node *p2 = l2.head;
//     SSLL l3;
//     while (p1 != NULL &&p2 != NULL)
//     {
//         if (p1->elem < p2->elem)
//         {
//             l3.addtail(p1->elem);
//             p1 = p1->next;
//         }
//         else if (p1->elem > p2->elem)
//         {
//             l3.addtail(p2->elem);
//             p2 = p2->next;
//         }
//         else
//         {
//             l3.addtail(p1->elem);
//             l3.addtail(p2->elem);
//             p1 = p1->next;
//             p2 = p2->next;
//         }
//     }
//     while (p1 != NULL)
//     {
//         l3.addtail(p1->elem);
//         p1 = p1->next;
//     }
//     while (p2 != NULL)
//     {
//         l3.addtail(p2->elem);
//         p2 = p2->next;
//     }
//     return l3;
// }
int main()
{

    SLL l1;
    l1.addFront(2);
    l1.addtail(10);
    l1.addtail(50);
    l1.addtail(1);
    l1.addtail(2);
    l1.show();
    try
    {
        SSLL l2(l1);
        l2.show();
        SSLL l3 = l2;
        l3.show();
    }
    catch (const char *msg)
    {
        cout << msg;
    }

    return 0;
}
