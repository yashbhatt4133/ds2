#include <iostream>
#include "DNode.cpp"
using namespace std;
class CDLL
{
public:
    DNode *cursor;
    CDLL()
    {
        cursor = NULL;
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
            p->next = cursor->next;
            cursor->next = p;
            p->prev = cursor;
            p->next->prev = p;
        }
    }
    void display()
    {
        DNode *t = cursor->next;
        do
        {
            cout << t->d << "<->";
            t = t->next;
        } while (t != cursor->next);
        cout<<"\n";
    }
    void DeleteOddValued();
};
void CDLL::DeleteOddValued()
    {
        DNode *p = cursor->next;
        DNode * temp;
        while(p != cursor){
            if(p->d % 2){
                p->prev->next = p->next;
                p->next->prev=p->prev;
                temp = p;
                p = p->next;
                delete temp;
            }
            else{
                p = p->next;
            }
        }
        if (cursor->d % 2){
            
            cursor->prev->next = cursor->next;
            cursor->next->prev = cursor -> prev;
            temp = cursor;
            cursor = cursor->prev;
            delete temp;
        }
    }
int main()
{
    CDLL list;
    list.add(4);
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(6);
    list.add(2);
    list.add(21);
    list.add(10);
    list.display();
    list.DeleteOddValued();
    list.display();
    return 0;
}