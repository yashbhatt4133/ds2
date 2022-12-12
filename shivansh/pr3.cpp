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
    void addfront(int x)
    {                                  //part (i)
        node* p=new node(x);
        if(head==NULL){
            head=p;
            tail=p;
            return;
        }
        p->next=head;
        head=p;
    }
    void addpos(int i,int x)
    {
        if(head==NULL)
        addfront(x);
        else{
            node* t=head;
            node* p=new node(x);
            int pos=0;
            while(t!=NULL&&pos<i-2)
            {
                t=t->next;
                pos++;
            }
            p->next=t->next;
            t->next=p;
        }
    }
    void display(){
        node* t=head;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    void removefront(){
        if(head->next==NULL)
        {
            head=NULL;
            tail=NULL;
            return;
        }
        node* t=head;
        t=head->next;
        head=t;
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
    void removepos(int i)
    {
        node* t=head;
        node* tr=NULL;
        int pos=1;
        while(t!=tail&&pos!=i)
        {
            tr=t;
            t=t->next;
            pos++;
        }
        if(pos==i)
        tr->next=t->next;
        else
        cout<<"Invalid Index Specified"<<endl;
    }
    node* search(int x){
        node* t=head;
        while(t!=NULL&&t->data!=x)
        {
            t=t->next;
        }
        return t;
    }
    void concat(sll l2)
    {
        this->tail->next=l2.head;
    }
};
int main(){
    sll obj,obj1;
    obj.addfront(5);
    obj.addfront(6);
    obj.addfront(7);
    obj.addfront(8);
    obj.addback(4);
    obj.display();
    obj1.addfront(1);
    obj1.addfront(2);
    obj1.addfront(3);
    obj1.addfront(4);
    obj1.display();
    // obj.addpos(3,9);
    // obj.display();
    // obj.removefront();
    // obj.display();
    // obj.removepos(3);
    // obj.display();
    // obj.removeback();
    // obj.display();
    // if(obj.search(9)==NULL)
    // cout<<"9 not found"<<endl;
    // else
    // cout<<"9 found"<<endl;
    obj.concat(obj1);
    obj.display();
}
