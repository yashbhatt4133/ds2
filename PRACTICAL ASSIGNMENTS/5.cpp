#include <bits/stdc++.h>
using namespace std;

typedef int Elem;
class Node
{
    Elem elem;
    Node *next;
    friend class SLL;
};
class SLL
{
private:
    Node *head, *tail;

public:
    SLL(){head = 0;tail = 0;}

    void addFront(Elem x){
        Node*p = new Node;
        p->elem = x;
        p->next = head;
        head = p;
        if (!tail) tail = p;
    }
    void add(Elem x,int pos){
        Node*p = new Node;
        p->elem = x;
        Node* temp = head;
        if (pos ==1){
            p->next = head;
            head = p;
            if (!tail) tail = p;
            return;
        }
        int count = 1;
        while(temp != NULL && count<pos-1){
            temp = temp->next;
            count++;
        }
        if(temp == NULL) throw "INVALID POSITION";
        p->next = temp->next;
        temp->next = p;
        if (temp->next == NULL) tail = temp;
    }
    void removeFront(){
        if (head == 0)
        if (head==tail){
            delete []head;
            head =0;
            tail = 0;
        }
    }
    void remove(int pos){
        Node* ptr = head;
        if (head ==0) throw "EMPTY LIST";
        if (pos ==1){
            Node* oldhead = head;
            head = oldhead->next;
            delete oldhead;
            return;
        }
        int count = 1;
        while(ptr != NULL && count<pos-1){
            ptr = ptr->next;
            count++;
        }
        if(ptr == NULL) throw "INVALID POSITION";
        Node* old = ptr->next;
        ptr->next = old->next;
        delete old;
    }
    Node* search(Elem x);
    void concat(const SLL& l2);
    void show(){
        Node*temp = head;
        while(temp !=NULL){
            cout<<temp->elem<<"->";
            temp = temp->next;
        }
        cout<<"NULL \n";
    }
};

int main()
{
    SLL l1;
    l1.add(1,1);
    l1.show();
    l1.add(22,2);
    l1.show();
    l1.add(333,1);
    l1.addFront(56);
    l1.remove(2);
    l1.show();
    return 0;
}