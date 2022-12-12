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
    bool is_empty()
    {
        return cursor == NULL;
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

    void add_head(int x)
    {
        DNode *p = new DNode(x);
        if (is_empty())
        {
            p->next = p;
            p->prev = p;
            cursor = p;
        }
        else
        {
            cursor->next->prev = p;
            p->next = cursor->next;
            cursor->next = p;
            p->prev = cursor;
        }
    }
    void add_tail(int x)
    {
        add_head(x);
        cursor = cursor->next;
    }
    int get_head()
    {
        if (is_empty())
            throw "Empty List";
        return cursor->next->d;
    }
    void del_head()
    {
        if (is_empty())
            throw "Empty list";
        else if (cursor->next == cursor)
        {
            delete cursor;
            cursor = NULL;
        }
        else
        {
            DNode *to_delete = cursor->next;
            cursor->next->next->prev = cursor;
            cursor->next = cursor->next->next;
            delete to_delete;
        }
    }

    void del_tail()
    {
        cursor = cursor->prev;
        del_head();
    }

    void concat(CList l)
    {
        DNode *temp = this->cursor->next;

        this->cursor->next = l.cursor->next;
        this->cursor->next->prev = this->cursor;
        temp->prev = l.cursor;
        l.cursor->next = temp;
        l.cursor = NULL;
    }
    DNode *search(int x)
    {
        if (is_empty())
            throw "Not Found";
        DNode *t = cursor->next;
        do
        {
            if (t->d == x)
                return t;
            t = t->next;
        } while (t != cursor->next);
        throw "Not Found";
    }
    void display()
    {
        if (is_empty())
            throw "Empty List";
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
    try
    {
        CList list;
        CList list2;
        list.add_head(5);
        list.add_head(1);
        list.add_head(6);
        list.add_head(2);
        list.add_tail(10);
        list.display();
        // cout << list.search(11)->d;
        // list2.add_head(5);
        // list2.add_head(1);
        // list2.add_head(6);
        // list2.add_head(2);
        // list2.add_tail(10);
        // list.concat(list2);
        // list.del_tail();
        // list.del_tail();
        // list.del_tail();
        // list.del_tail();
        // list.del_tail();
        // list.del_head();
        // list.del_head();
        // list.del_head();
        // list.del_head();

        // list.DeleteOddValued();
        // list.display();
    }
    catch (char const *msg)
    {
        cout << msg;
    }
    return 0;
}
