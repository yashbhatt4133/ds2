// level order incomplete
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int k = 0)
    {
        key = k;
        left = right = NULL;
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void insert(int n)
    {
        Node *t = new Node(n);
        if (root == NULL)
            root = t;
        else
        {
            Node *temp = root;
            Node *tr = NULL;
            while (temp != NULL)
            {
                tr = temp;
                if (temp->key > n)
                    temp = temp->left;
                else if (temp->key == n)
                    throw "Value already exist";
                else
                    temp = temp->right;
            }
            if (tr->key > n)
                tr->left = t;
            else
                tr->right = t;
        }
    }
    int count()
    {
        return count_nodes(root);
    }
    int count_nodes(Node *p)
    {
        if (p == NULL)
            return 0;
        if (p->left == NULL && p->right == NULL)
            return 1;
        return (1 + count_nodes(p->left) + count_nodes(p->right));
    }
    int min()
    {
        Node *t = root;
        while (t->left != NULL)
            t = t->left;
        return t->key;
    }
    int max()
    {
        Node *t = root;
        while (t->right != NULL)
            t = t->right;
        return t->key;
    }
    void del(int n)
    {
        Node *tr = NULL;
        Node *t = root;
        while (t->key != n)
        {
            tr = t;
            if (t->key > n)
                t = t->left;
            else
                t = t->right;
        }
        if (t->left == NULL)
        {
            if (t->right == NULL)
            {
                if (tr->right == t)
                    tr->right = NULL;
                else
                    tr->left = NULL;
            }
            else
                tr->right = t->right;
        }
        else
        {
            if (t->right == NULL)
                tr->right = t->left;
            else
            {
                Node *tt = t->left;
                Node *ttr = t;
                while (tt->right != NULL)
                {
                    ttr = tt;
                    tt = tt->right;
                }
                t->key = tt->key;
                ttr->right = NULL;
            }
        }
    }
    void replace(int x, int y)
    {
        del(x);
        insert(y);
    }
    void display_inorder()
    {
        disp_inorder(root);
        cout << endl;
    }
    void disp_inorder(Node *node)
    {
        if (node == NULL)
            return;
        disp_inorder(node->left);
        cout << node->key << " ";
        disp_inorder(node->right);
    }

    void display_preorder()
    {
        disp_preorder(root);
        cout << endl;
    }
    void disp_preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->key << " ";
        disp_inorder(node->left);
        disp_inorder(node->right);
    }
    void display_postorder()
    {
        disp_preorder(root);
        cout << endl;
    }
    void disp_postorder(Node *node)
    {
        if (node == NULL)
            return;
        disp_postorder(node->left);
        disp_postorder(node->right);
        cout << node->key << " ";
    }
    void level_traversal()
    {
        queue<Node *> q;
        Node *t = root;
        if (t != NULL)
        {
            q.push(t);
            while (!q.empty())
            {
                t = q.front();
                cout << t->key << " ";
                q.pop();
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
        }
        cout << endl;
    }
    int height()
    {
        return h(root);
    }
    int h(Node *t)
    {
        if (t == NULL)
            return 0;
        int r = h(t->right);
        int l = h(t->left);
        return 1 + ((r > l) ? r : l);
    }
};
int main()
{
    BST t;
    t.insert(56);
    t.insert(24);
    t.insert(27);
    t.insert(200);
    t.insert(18);
    t.insert(12);
    // t.display_inorder();
    t.level_traversal();
    // t.replace(9, 100);
    // cout << t.max();
    // t.display_inorder();
    // t.del(6);
    // t.display();
    // cout << t.count();
    return 0;
}