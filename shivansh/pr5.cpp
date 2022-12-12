#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int x=0)
    {
        data=x;
        next=NULL;
    }
};
class cll
{
    public:
    node* head;
    cll(){
        head=NULL;
    }
    bool isempty(){
        if(head==NULL)
        return true;
        else
        return false;
    }
    void addfront(int x)
    {
        node* p=new node(x);
        if(isempty())
        {
            head=p;
            head->next=head;
            return;
        }
        else{
            node* t=head;
            while(t->next!=head)
            {
                t=t->next;
            }
        p->next=head;
        head=p;
        t->next=head;
        }
    }
    void addafter(int x,int y)
    {
        if(isempty())
            throw "List is Empty";
        else{
            node* p=new node(x);
            node* t=head;
            while(t->data!=y&&t->next!=head)
            {
                t=t->next;
            }
            if(t->data==y&&t->next!=head){
                p->next=t->next;
                t->next=p;
            }
            if(t->data==y&&t->next==head)
            {
                t->next=p;
                p->next=head;
            }
            if(t->data!=y&&t->next==head)
            {
                throw "Not Found";
            }
        }
    }
    void addback(int x)
    {
        node* p=new node(x);
        if(isempty())
        addfront(x);
        else{
            node* t=head;
            while(t->next!=head)
            {
                t=t->next;
            }
            t->next=p;
            p->next=head;
        }
    }
    void removeback()
    {
        if(isempty())
        throw "List is Empty";
        else if(head->next==head)
        {
            head=NULL;
        }
        else{
            node* t=head;
            node* tr=NULL;
            while(t->next!=head)
            {
                tr=t;
                t=t->next;
            }
            tr->next=head;
            delete t;
        }
    }
    void removefront()
    {
        if(isempty())
        throw "List is Empty";
        else if(head->next==head)
        {
            head=NULL;
        }
        else{
            node* t=head;
            while(t->next!=head)
            {
                t=t->next;
            }
            t->next=head->next;
            head=t->next;
        }
    }
    void removedata(int x)
    {
        if(isempty())
        throw "List is Empty";
        else if(head->next==head&&head->data==x)
        {
            head=NULL;
        }
        else if(head->next!=head&&head->data!=x)
        {
            node* p=new node(x);
            node* t=head;
            node* tr=NULL;
            while(t->next!=head&&t->data!=x)
            {
                tr=t;
                t=t->next;
            }
            if(t->data==x&&t->next!=head)
            {
                tr->next=t->next;
                delete t;
            }
            if(t->data==x&&t->next==head)
            removeback();
        }
        else
        throw "Not Found";
    }
    node* search(int x)
    {
        node* p=new node(x);
        node* t=head;
        while(t->next!=head&&t->data!=x)
        {
            t=t->next;
        }
        if(t->data==x)
        return t;
        else
        return NULL;
    }
    void concat(cll l2)
    {
        node* t=this->head;
        while(t->next!=this->head)
        {
            t=t->next;
        }
        t->next=l2.head;
        t=l2.head;
        while(t->next!=l2.head)
        {
            t=t->next;
        }
        t->next=this->head;
    }
    void display(){
        if(head==NULL)
        throw "List is Empty";
        else{
        node* t=head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=head);
        cout<<endl;
        }
    }
};
int main(){
    try{
    cll l1,l2;
    l1.addfront(1);
    l1.addfront(2);
    l1.addfront(3);
    l1.addfront(4);
    l1.display();
    // l1.addafter(9,5); 
    // l1.display();
    // l1.addback(9);
    // l1.display();
    // l2.addfront(5);
    // l2.addfront(6);
    // l2.addfront(7);
    // l2.addfront(8);
    // l2.display();
    // l1.concat(l2);
    // l1.display();
    // l2.removeback();
    // l2.display();
    // l1.removefront();
    // l1.display();
    // l2.removedata(3);
    // l2.display();
    // if(l1.search(4)!=NULL)
    // cout<<"Found"<<endl;     
    // else
    // cout<<"Not Found"<<endl;
    }
    catch(char const *msg)
    {
        cout<<msg<<endl;
    }
}