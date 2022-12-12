#include <iostream>
#include "SList.cpp"
using namespace std;
class Sorted : public SList
{

public:
    Sorted()
    {
    }
    bool is_empty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    void insert(int x)
    {
        int c = 0;
        SNode *temp = head;
        while (temp != NULL && x > temp->d)
        {
            temp = temp->next;
            c++;
        }
        insert_at(c, x);
        // SNode *p = new SNode(x);
        // SNode *temp = head;
        // SNode *prev = NULL;
        // while (temp != NULL && x > temp->d)
        // {
        //     prev = temp;
        //     temp = temp->next;
        // }
        // p->next = temp;
        // prev->next = p;
        // if (temp == NULL)
        //     tail = p;
    }
    Sorted *merge(Sorted ob)
    {
        SNode *p1 = this->head;
        SNode *p2 = ob.head;

        SNode *dummy = new SNode(-1);
        Sorted *list = new Sorted();

        SNode *p3 = dummy;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->d < p2->d)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        while (p1 != NULL)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while (p2 != NULL)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        list->head = dummy->next;
        return list;
    }
};
int main()
{
    try
    {

        Sorted list;
        list.insert(2);
        list.insert(4);
        list.insert(2);
        list.insert(100);
        list.insert(22);
        list.insert(51);
        list.display();
        cout << endl;

        Sorted list1;
        list1.insert(5);
        list1.insert(14);
        list1.insert(12);
        list1.insert(1100);
        list1.insert(122);
        list1.insert(151);
        list1.display();

        cout << endl;

        list.merge(list1);
        list.display();
    }
    catch (char const *msg)
    {
        cout << msg;
    }
}