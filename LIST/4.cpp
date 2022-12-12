#include <iostream>
using namespace std;
class Node
{
public:
    int d;
    Node *next;
    Node *prev;
    Node(int x = 0)
    {
        d = x;
        next = NULL;
        prev = NULL;
    }
};
class DLL
{
public:
    Node *header;
    Node *trailer;
    DLL()
    {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }
    void addhead(int x)
    {
        Node *p = new Node(x);
        p->next = header->next;
        p->prev = header;
        header->next->prev = p;
        header->next = p;
    }
    void addtail(int x)
    {
        Node *p = new Node(x);
        p->next = trailer;
        p->prev = trailer->prev;
        trailer->prev->next = p;
        trailer->prev = p;
    }
    float average()
    {
        Node *temp = header->next;
        float sum = 0;
        int c = 0;
        while (temp->next != NULL)
        {
            sum += temp->d;
            temp = temp->next;
            c++;
        }
        return sum / c;
    }
    bool isempty()
    {
        if (header->next == trailer)
            return true;
        return false;
    }
    long get_tail()
    {
        if (isempty())
            throw "Empty List";
        return (long)(trailer->prev->d);
    }
    long get_head()
    {
        if (isempty())
            throw "Empty List";
        return (long)(header->next->d);
    }
    void display()
    {
        // cout << "displaying:\n";
        Node *temp = header->next;
        while (temp->next != NULL)
        {
            cout << temp->d << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void removetail()
    {
        if (isempty())
            throw "List is empty";
        Node *to_delete = trailer->prev;
        trailer->prev->prev->next = trailer;
        trailer->prev = trailer->prev->prev;
        delete to_delete;
    }
    void removehead()
    {
        if (isempty())
            throw "List is empty";
        Node *to_delete = header->next;
        header->next->next->prev = header;
        header->next = header->next->next;

        delete to_delete;
    }
    void concat(DLL ob)
    {
        Node *temp = this->trailer;
        temp->prev->next = ob.header->next;
        ob.header->next->prev = temp->prev;
        this->trailer = ob.trailer;
        delete temp;
    }
    void swap(Node *x, Node *y)
    {

        Node *x_next;
        Node *x_prev;

        x_prev = x->prev;
        x_next = x->next;

        x->next->prev = y;
        x->prev->next = y;
        x->next = y->next;
        x->prev = y->prev;
        y->prev->next = x;
        y->next->prev = x;
        y->prev = x_prev;
        y->next = x_next;
    }
};
int main()
{
    DLL l1;
    l1.addtail(200);
    l1.addtail(100);
    l1.addtail(300);
    l1.addtail(250);
    l1.addtail(30);
    l1.addtail(3);
    l1.display();

    l1.swap(l1.header->next->next, l1.header->next->next->next->next);
    l1.display();
    return 0;
}
