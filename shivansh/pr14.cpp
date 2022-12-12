#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *right;
    Node *left;
    int height;
    Node(int n)
    {
        key = n;
        right = NULL;
        left = NULL;
        height = 1;
    }
};
class AVL
{
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }
    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }
    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return (height(node->left) - height(node->right));
    }
    Node *left_rotate(Node *x)
    {
        Node *y = x->right;
        Node *t = y->left;

        y->left = x;
        x->right = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
    Node *right_rotate(Node *y)
    {
        Node *x = y->left;
        Node *t = x->right;

        x->right = y;
        y->left = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return x;
    }

    void insert(int x)
    {
        if (root == NULL)
        {
            Node *t = new Node(x);
            root = t;
        }
        else
        {
            iinsert(root, x);
        }
    }
    Node *iinsert(Node *node, int n)
    {
        if (node == NULL)
        {
            return (new Node(n));
        }
        else
        {
            // insert as normal BST
            if (n < node->key)
                node->left = iinsert(node->left, n);
            else if (n > node->key)
                node->right = iinsert(node->right, n);
            else
                return node;

            // updating heights of ancestors
            node->height = 1 + max(height(node->left), height(node->right));

            // getting balance factor of current node(insertion is recursive so it will set balance of all ancestors)
            int balance = getBalance(node);

            // if unbalanced, then 4 cases

            // LL case
            if (balance > 1 && n < node->left->key)
                return right_rotate(node);

            // RR case
            if (balance < -1 && n > node->right->key)
                return left_rotate(node);

            // LR case
            if (balance > 1 && n > node->left->key)
            {
                node->left = left_rotate(node->left);
                return right_rotate(node);
            }
            if (balance < -1 && n < node->right->key)
            {
                node->right = right_rotate(node->right);
                return left_rotate(node);
            }
            return node;
        }
    }
    void disp_inorder()
    {
        inorder(root);
        cout << endl;
    }
    void inorder(Node *n)
    {
        if (n == NULL)
            return;
        inorder(n->left);
        cout << n->key << " ";
        inorder(n->right);
    }
    Node *minNode(Node *n)
    {
        Node *temp = n;

        while (temp->left != NULL)
            temp = temp->left;

        return temp;
    }
    void delete_Node(int n)
    {
        if (root == NULL)
            throw "Empty Tree";
        deleteNode(root, n);
    }
    Node *deleteNode(Node *root, int n)
    {
        if (root == NULL)
            return root;

        if (n < root->key)
            root->left = deleteNode(root->left, n);
        else if (n > root->key)
            root->right = deleteNode(root->right, n);
        else
        { // reached the node to delete

            if (root->left == NULL || root->right == NULL)
            { // 1 or no child

                Node *temp = root->left ? root->left : root->right;

                // no child condition
                if (temp == NULL)
                {
                    temp = root; // to delete temp
                    root = NULL;
                }

                // 1 child condition
                else
                {
                    *root = *temp;
                }
                free(temp);
            }
            else
            {
                // 2 child exists
                Node *temp = minNode(root->right);
                root->key = temp->key;

                // recursive call to delete the node
                root->right = deleteNode(root->right, temp->key);
            }
        }
        // if only 1 node existed, which is now deleted
        // then tree is empty, so no balancing required
        if (root == NULL)
            return root;

        // updating heights
        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // usual 4 cases
        // LL
        if (balance > 1 && getBalance(root->left) >= 0)
            return right_rotate(root);

        // RR
        if (balance < -11 && getBalance(root->right) <= 0)
            return left_rotate(root);

        // LR
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }

        // RL
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
        return root;
    }
};
int main()
{
    AVL t;
    t.insert(33);
    t.insert(13);
    t.insert(53);
    t.insert(11);
    t.insert(21);
    t.insert(61);
    t.insert(9);
    t.insert(8);
    t.delete_Node(53);
    t.disp_inorder();
}