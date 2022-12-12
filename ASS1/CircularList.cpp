#include <iostream>
#include "DNode.cpp"
using namespace std;
class CList
{
public:
    DNode *cursor;
    CList()
    {
        cursor = NULL;
    }
    void DeleteOddValued()
    {
        DNode *t = cursor->next;
        do
        {
            // cout << t->d << " ";
            if ((t->d) % 2 != 0)
            {
                DNode *to_delete = t;
                if (t == cursor)
                {
                    cursor = cursor->prev;
                }
                t->next->prev = t->prev;
                t->prev->next = t->next;
                t = t->next;
                delete to_delete;
            }
            else
            {
                t = t->next;
            }
        } while (t != cursor->next);
    }

    void add(int x)
    {
        DNode *p = new DNode(x);
        if (cursor == NULL)
        {
            p->next = p;
            p->prev = p;
            cursor = p;
        }
        else
        {
            cursor->next->next->prev = p;
            p->next = cursor->next;
            cursor->next = p;
            p->prev = cursor;
        }
    }
    void display()
    {
        DNode *t = cursor->next;
        do
        {
            cout << t->d << " ";
            t = t->next;
        } while (t != cursor->next);
        cout << endl;
    }
};
int main()
{
    CList list;
    list.add(5);
    // list.add(1);
    // list.add(6);
    // list.add(2);
    // list.add(10);

    list.DeleteOddValued();
    list.display();
    return 0;
}