#include <iostream>
#include "Poly_Term.cpp"
using namespace std;
class Polynomial
{
public:
    Term *header;
    Term *trailer;
    Polynomial()
    {
        header = new Term();
        trailer = new Term();
        header->next = trailer;
        trailer->prev = header;
    }
    void sum(Polynomial a, Polynomial b)
    {
        Term *p1 = a.header->next;
        Term *p2 = b.header->next;
        int cc = 0, pp = 0;
        Term *dummy = new Term();
        Term *p3 = dummy;
        // Polynomial *list = new Polynomial;
        // cout << "flag 2";
        while (p1 != a.trailer && p2 != b.trailer)
        {
            if (p1->power == p2->power)
            {
                cc = p1->coeff + p2->coeff;
                pp = p1->power;
                Term *temp = new Term(cc, pp);
                p3->next = temp;
                temp->prev = p3;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->power < p2->power)
            {
                cc = p2->coeff;
                pp = p2->power;
                Term *temp = new Term(cc, pp);
                p3->next = temp;
                temp->prev = p3;
                p2 = p2->next;
            }
            else
            {
                cc = p1->coeff;
                pp = p1->power;
                Term *temp = new Term(cc, pp);
                p3->next = temp;
                temp->prev = p3;
                p1 = p1->next;
            }
            p3 = p3->next;
        }
        while (p1 != a.trailer)
        {
            cc = p1->coeff;
            pp = p1->power;
            Term *temp = new Term(cc, pp);
            p3->next = temp;
            temp->prev = p3;
            p1 = p1->next;
            p3 = p3->next;
        }
        while (p2 != b.trailer)
        {
            cc = p2->coeff;
            pp = p2->power;
            Term *temp = new Term(cc, pp);
            p3->next = temp;
            temp->prev = p3;
            p2 = p2->next;
            p3 = p3->next;
        }
        // cout << "flag 3";
        this->header->next = dummy->next;
        dummy->next->prev = this->header;
        this->trailer->prev = p3;
        p3->next = this->trailer;
        // list->header->next = dummy->next;
        // dummy->next->prev = list->header;
        // list->trailer->prev = p3;
        // p3->next = list->trailer;
        // return list
    }
    void insert_at_head(int c, int p)
    {
        Term *temp = new Term(c, p);
        temp->next = header->next;
        temp->prev = header;
        header->next->prev = temp;
        header->next = temp;
    }
    void insert(int c, int p)
    {
        Term *to_store = new Term(c, p);
        Term *temp = header->next;
        // Term *previ = header;
        while (temp != trailer && p < temp->power)
        {
            // previ = temp;
            temp = temp->next;
        }
        // previ->next = to_store;
        temp->prev->next = to_store;
        to_store->next = temp;
        to_store->prev = temp->prev;
        temp->prev = to_store;
    }
    void input()
    {
        int n;
        cout << "Enter number of terms" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int power, coeff;
            cout << "Enter power: ";
            cin >> power;
            cout << "Enter coefficient: ";
            cin >> coeff;
            insert(coeff, power);
        }
    }
    void display()
    {
        Term *temp = header->next;
        while (temp->next != NULL)
        {
            cout << " + " << temp->coeff << "x^" << temp->power;
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    try
    {
        Polynomial ob;
        ob.input();
        ob.display();
        cout << endl;
        Polynomial ob1;
        ob1.input();
        ob1.display();
        // cout << "flag 4";
        Polynomial ans;
        ans.sum(ob, ob1);
        // cout << "flag 5";
        ans.display();
    }
    catch (char const *msg)
    {
        cout << msg;
    }
}