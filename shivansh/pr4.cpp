#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int x=0)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
class dll
{
    public:
    node* header;
    node* trailer;
    dll()
    {
        header=new node();
        trailer=new node();
        header->next=trailer;
        trailer->prev=header;
    }
    bool isempty(){
        if(header->next==trailer)
        return true;
        else
        return false;
    }
    void addfront(int x)
    {
        node* p=new node(x);
        if(isempty())
        {
            header->next=p;
            p->prev=header;
            trailer->prev=p;
            p->next=trailer;
            return;
        }
        p->next=header->next;
        p->prev=header;
        p->next->prev=p;
        header->next=p;
    }
    void addback(int x)
    {
        node* p=new node(x);
        trailer->prev->next=p;
        p->prev=trailer->prev;
        trailer->prev=p;
        p->next=trailer;
    }
    void addpos(int i,int x)
    {
        node* p=new node(x);
        node* t=header->next;
        int pos=1;
        while((t->next!=trailer)&&(pos<i))
        {
            t=t->next;
            pos++;
        }
        if(t->next==trailer&&(pos+1)!=i){
        throw "Invalid Index";
        }
        else if(t->next==trailer&&(pos+1)==i)
        {
            t->next=p;
            p->next=trailer;
            p->prev=t;
            trailer->prev=p;
        }
        else{
        t->prev->next=p;
        p->prev=t->prev;
        t->prev=p;
        p->next=t;
        }
    }
    void removeback(){
        if(isempty())
        {
            throw "List is Empty";
        }
        node* t=trailer->prev;
        trailer->prev=t->prev;
        t->prev->next=trailer;
        delete t;
    }
    void removefront()
    {
        if(isempty())
        {
            throw "List is Empty";
        }
        node* t=header->next;
        header->next=t->next;
        t->next->prev=header;
        delete t;
    }
    void removepos(int i)
    {
        if(isempty())
        throw "List is Empty";
        node* t=header->next;
        int pos=1;
        while(t->next!=trailer&&pos!=i)
        {
            t=t->next;
            pos++;
        }
        if(pos==i)
        {
            t->prev->next=t->next;
            t->next->prev=t->prev;
            delete t;
        }
        else
        throw "Invalid Index Specified";
    }
    void display()
    {
        node* t=header->next;
        while(t!=trailer)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    node* search(int x){
        node* t=header->next;
        while(t!=trailer&&t->data!=x)
        {
            t=t->next;
        }
        if(t==trailer)
        return NULL;
        else
        return t;
    }
    void concat(dll l2)
    {
        this->trailer->prev->next=l2.header->next;
        this->trailer=l2.trailer;
    }
};
int main()
{
    try{
    dll l1,l2;
    l1.addfront(1);
    l1.addfront(2);
    l1.addfront(3);
    l1.addfront(4);
    l1.display();
    // l1.addpos(5,7);
    // l1.display();
    // l1.addback(9);
    // l1.display();
    // l1.removeback();
    // l1.display();
    // l1.removefront();
    // l1.display();
    // l1.removepos(5);
    // l1.display();
    // if(l1.search(1)!=NULL)
    // cout<<"Found"<<endl;
    // else
    // cout<<"Not Found"<<endl;
    l2.addfront(5);
    l2.addfront(6);
    l2.addfront(7);
    l2.addfront(8);
    l2.display();
    l1.concat(l2);
    l1.display();
    }
    catch(char const *msg){
        cout<<msg<<endl;
    }
}