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
class CLL
{
public:
    Node *cursor;
    CLL()
    {
        cursor = NULL;
    }
    bool EMPTY()
    {
        return cursor == NULL;
    }
    void DeleteOddValued()
    {
        Node *t = cursor->next;
        do
        {
            // cout << t->d << " ";
            if ((t->d) % 2 != 0)
            {
                Node *to_delete = t;
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
        Node *p = new Node(x);
        if (EMPTY())
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
        if (EMPTY())
            throw "Empty List";
        return cursor->next->d;
    }
    void del_head()
    {
        if (EMPTY())
            throw "Empty LL";
        else if (cursor->next == cursor)
        {
            delete cursor;
            cursor = NULL;
        }
        else
        {
            Node *to_delete = cursor->next;
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

    void concat(CLL l)
    {
        Node *temp = this->cursor->next;

        this->cursor->next = l.cursor->next;
        this->cursor->next->prev = this->cursor;
        temp->prev = l.cursor;
        l.cursor->next = temp;
        l.cursor = NULL;
    }
    Node *search(int x)
    {
        if (EMPTY())
            throw "Not Found";
        Node *t = cursor->next;
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
        if (EMPTY())
            throw "Empty List";
        Node *t = cursor->next;
        do
        {
            cout << t->d << " ";
            t = t->next;
        } while (t != cursor->next);
        cout << endl;
    }
};