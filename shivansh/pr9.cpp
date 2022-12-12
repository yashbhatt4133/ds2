#include <bits/stdc++.h>
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
class qlist
{
    public:
    node* front;
    node* rear;
    qlist()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int x)
    {
        node* p=new node(x);
        if(rear==NULL)
        {
            front=p;
            rear=p;
            rear->next=front;
        }
        else{
            rear->next=p;
            rear=p;
            rear->next=front;
        }
    }
    void dequeue()
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
            node* t=front;
            t=front->next;
            front=t;
            rear->next=front; //if not written then it will rotate the queue
        }
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
    qlist q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.display();
    q1.dequeue();
    q1.display();
}