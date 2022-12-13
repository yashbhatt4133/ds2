#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    int height;
    node(int x=0)
    {
        data=x;
        left=right=NULL;
        height=0;
    }
};
class avl
{
    public:
    node* root;
    avl()
    {
        root=NULL;
    }
    int findh(node* node)
    {
        if(node==NULL)
        return 0;
        else
        return node->height;
    }
    int getbalance(node* node)
    {
        if(node==NULL)
        return 0;
        else
        return (findh(node->left)-findh(node->right));
    }
    node* rightrotate(node* a)
    {
        node* b=a->left;
        node* d=b->right;

        a->left=d;
        b->right=a;

        a->height=max(findh(a->left),findh(a->right))+1;
        b->height=max(findh(b->left),findh(b->right))+1;

        return b;
    }
    node* leftrotate(node* a)
    {
        node* b=a->right;
        node* d=b->left;

        a->right=d;
        b->left=a;

        a->height=max(findh(a->left),findh(a->right))+1;
        b->height=max(findh(b->left),findh(b->right))+1;

        return b;
    }
    void ins(int x)
    {
        if(root==NULL)
        root=new node(x);
        else
        insert(root,x);
    }
    node* insert(node* p,int x)
    {
        if(p==NULL)
        return (new node(x));
        else
        {
            if(x<p->data)
            p->left=insert(p->left,x);
            else if(x>p->data)
            p->right=insert(p->right,x);
            else
            return p;

            p->height=max(findh(p->right),findh(p->left))+1;

            int bal=getbalance(p);

            // case 1: ll

            if(bal>1&&x<p->left->data)
            return rightrotate(p);

            //case 2: rr

            if(bal<-1&&x>p->right->data)
            return leftrotate(p);

            //case 3:rl

            if(bal<-1&&x<p->right->data)
            {
                p->right=rightrotate(p->right);
                return leftrotate(p);
            }

            //case 4:

            if(bal>1 && x>p->left->data)
            {
                p->left=leftrotate(p->left);
                return rightrotate(p);
            }
        return p;
        }
    } 
    void display()
    {
        inorder(root);
        cout<<endl;
    }
    void inorder(node* node)
    {
        if(node==NULL)
        return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    node* findmin(node* n)
    {
        node *t=n;
        while(t->left!=NULL)
        {
        t=t->left;
        }
        return t;
    }
    void del(int x)
    {
        if(root==NULL)
        cout<<"Empty tree"<<endl;
        else
        remove(root,x);
    }
    node* remove(node* p,int x)
    {
        if(p==NULL)
        return p;
        else
        {
            if(x<p->data)
            return remove(p->left,x);
            else if(x>p->data)
            return remove(p->right,x);
            else{
                //reached the node to delete
                if(p->left==NULL||p->right==NULL)
                {
                    node* tmp;
                    if(p->left!=NULL)
                    tmp=p->left;
                    else
                    tmp=p->right;
                    if(tmp==NULL){
                        tmp=p;
                        p=NULL;
                    }
                    else{
                        *p=*tmp;
                    }
                    delete tmp;
                }
                else
                {
                    node* tmp=findmin(p->right);
                    p->data=tmp->data;

                    p->right=remove(p->right,tmp->data);
                }
            }
            if(p==NULL)
            return p;

            p->height=max(findh(p->left),findh(p->right));

            int bal = getbalance(p);

            //case 1:ll

            if(bal > 1 && getbalance(p->left)>=0)
            return rightrotate(p);

            //case: rr
            if(bal<-1 && getbalance(p->right)<=0)
            return leftrotate(p);

            //case:rl
            if(bal<-1 && getbalance(p->left)>0)
            {
                p->right=rightrotate(p->right);
                return leftrotate(p);
            }

            //case : lr
            if(bal>1 && getbalance(p->right)<0)
            {
                p->left=leftrotate(p->left);
                return rightrotate(p);
            }
        }
        return p;
    }
};
int main()
{
    avl obj;
    obj.ins(5);
    obj.ins(4);
    obj.ins(3);
    obj.ins(7);
    obj.display();
    obj.del(4);
    obj.display();
}