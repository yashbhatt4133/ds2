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
 class dqlist
 {
    public:
    node* front;
    node* rear;
    dqlist()
    {
        front=NULL;
        rear=NULL;
    }
    void enqfront(int x)
    {
        node* p=new node(x);
        if(front==NULL)
        {
            front=p;
            rear=p;
            rear->next=front;
            front->prev=rear;
        }
        else
        {
            p->next=front;
            p->prev=rear;
            front=p;
            rear->next=front;
            front->prev=rear;
        }
    }
    void enqrear(int x)
    {
        node* p=new node(x);
        if(front==NULL)
        {
            front=p;
            rear=p;
            rear->next=front;
            front->prev=rear;
        }
        else
        {
           rear->next=p;
           p->next=front;
           p->prev=rear;
           rear=p;
           rear->next=front;
           front->prev=rear;
        }
    }
    void deqrear()
    {
        if(front==NULL)
        throw "Queue is Empty";
        else if(front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        else
        {
            node* t=rear;
            rear=t->prev;
            rear->next=front;
            front->prev=rear;
            delete t;
        }
    }
    void deqfront()
    {
        if(front==NULL)
        throw "Queue is Empty";
        else if(front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        node* t=front;
        front=t->next;
        front->prev=rear;
        rear->next=front;
        delete t;
    }
    void display()
    {
        if(rear==NULL)
        throw "Empty Queue";
        else{
        node* t=front;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=front);
        cout<<endl;
        }
    }
 };
 int main()
 {
    dqlist l1;
    l1.enqfront(1);
    l1.enqfront(2);
    l1.enqfront(3);
    l1.display();
    l1.enqrear(4);
    l1.enqrear(5);
    l1.enqrear(6);
    l1.enqrear(7);
    l1.display();
    l1.deqrear();
    l1.display();
    l1.deqfront();
    l1.display();
 }