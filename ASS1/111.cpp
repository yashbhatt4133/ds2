#include <iostream>
using namespace std;
class NODE
{
public:
    int elem;
    NODE *next;
    NODE *prev;
    NODE(int x = 0)
    {
        elem = x;
        next = NULL;
        prev = NULL;
    }
};
class circularLL
{
public:
    NODE *cursor;
    circularLL()
    {
        cursor = NULL;
    }
    
    void add(int x)
    {
        NODE *p = new NODE(x);
        if (cursor == NULL)
        {
            p->next = p;
            p->prev = p;
            cursor = p;
        }
        else
        {
            p->next = cursor->next;
            cursor->next = p;
            p->prev = cursor;
            p->next->prev = p;
        }
    }
    void display()
    {
        NODE *t = cursor->next;
        do
        {
            cout << t->elem << "<->";
            t = t->next;
        } while (t != cursor->next);
        cout<<"\n";
    }
    void DeleteOddValued();
};

void circularLL::DeleteOddValued()
    {
        NODE *p = cursor->next;
        NODE * oddnode;
        while(p != cursor){
            if((p->elem % 2) == 1){
                oddnode = p;
                p->prev->next = p->next;
                p->next->prev=p->prev;
                p = p->next;
                delete oddnode;
            }
            else{
                p = p->next;
            }
        }
        if ((cursor->elem % 2) == 1){
                oddnode = cursor;
                cursor->prev->next = cursor->next;
                cursor->next->prev=cursor->prev;
                cursor = cursor->next;
                delete oddnode;
        }
    }

int main()
{
    circularLL list;
    list.add(1);
    list.add(12);
    list.add(6);
    list.add(2);
    list.add(21);
    list.add(1);
    list.display();
    list.DeleteOddValued();
    list.display();
    return 0;
}