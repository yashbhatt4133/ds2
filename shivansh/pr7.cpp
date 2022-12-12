#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int x=0)
    {
        data=x;
        next=NULL;
    }
};
class sll
{
    public:
    node* head;
    node* tail;
    sll(){
        head=NULL;
        tail=NULL;
    }
    void addback(int x)
    {
        node* p=new node(x);
        if(head==NULL)
        {
            head=p;
            tail=p;
            return;
        }
        tail->next=p;
        tail=p;
    }
    void display(){
        node* t=head;
        while(t!=NULL)
        {
            cout<<t->data<<endl;
            t=t->next;
        }
    }
    void removeback()
    {
        if(head->next==NULL)
        {
            head=NULL;
            tail=NULL;
            return;
        }
        node* t=head;
        while(t->next!=tail)
        {
            t=t->next;
        }
        t->next=NULL;
        tail=t;
    }
};
class stacklist
{
    public:
    int top;
    sll l;
    stacklist()
    {
        top=-1;
    }
    void push(int x)
    {
        l.addback(x);
        top++;
    }
    void pop()
    {
        if(top!=-1){
        l.removeback();
        top--;
        }
        else
        cout<<"Underflow"<<endl;
    }
    void disp()
    {
        l.display();
    }
};
int main()
{
    stacklist s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.disp();
    s1.pop();
    s1.disp();
}
