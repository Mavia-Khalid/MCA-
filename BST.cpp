#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
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

    void insertRec(int data, Node *&root)
    {
        if (root == NULL)
        {
            Node *newNode = new Node(data);
            root = newNode;
        }
        else if (data < root->data)
        {
            insertRec(data, root->left);
        }
        else if (data > root->data)
        {
            insertRec(data, root->right);
        }
    }

    Node *serachItr(int x)
    {
        Node *r = root;
        bool flag = false;
        while (r != NULL)
        {
            if (r->data == x)
            {
                flag = true;
                break;
            }
            else if (x < r->data)
            {
                r = r->left;
            }
            else
            {
                r = r->right;
            }
        }
        if (flag)
        {
            cout << x << " Found at " << r << endl;
            return r;
        }
        else
        {
            cout << x << " Not Found" << endl;
            return NULL;
        }
    }

    void insertItr(int data)
    {
        Node *parent = NULL;
        Node *r = this->root;

        while (r != NULL)
        {
            if (data < r->data)
            {
                parent = r;
                r = r->left;
            }
            else if (data > r->data)
            {
                parent = r;
                r = r->right;
            }
            else
            {
                cout << "Key already exists" << endl;
                exit(0);
            }
        }
        Node *newNode = new Node(data);
        if (parent == NULL)
        {
            root = newNode;
        }
        else if (data < parent->data)
        {
            parent->left = newNode;
        }
        else if (data > parent->data)
        {
            parent->right = newNode;
        }
    }

    void delItr(int x)
    {
        Node *parent = NULL;
        Node *r = root;
        bool flag = false;
        while (r != NULL)
        {
            if (x == r->data)
            {
                flag = true;
                break;
            }
            else if (x < r->data)
            {
                parent = r;
                r = r->left;
            }
            else
            {
                parent = r;
                r = r->right;
            }
        }
        if (!flag)
        {
            cout << "Deletion Not possible. Key Does not exists" << endl;
        }
        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                if (parent->left == r)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
                delete r;
            }
            else if (r->left != NULL && r->right == NULL)
            {
                if (parent->left == r)
                {
                    parent->left = r->left;
                }
                else
                {
                    parent->right = r->left;
                }
                delete r;
            }
            else if (r->left == NULL && r->right != NULL)
            {
                if (parent->left == r)
                {
                    parent->left = r->right;
                }
                else
                {
                    parent->right = r->right;
                }
                delete r;
            }
            else if (r->left != NULL && r->right != NULL)
            {
                parent = r;
                Node *suc = r->right;
                while (suc->left != NULL)
                {
                    parent = suc;
                    suc = suc->left;
                }
                // int t = r->data;
                r->data = suc->data;
                // suc->data = r->data;
                if (suc == parent->right)
                {
                    parent->right = suc->right;
                }
                else
                {
                    parent->left = suc->right;
                }
                delete suc;
            }
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << "  ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << "  ";
    }
};
int main()
{
    BST t;
    // t.insertRec(5,t.root);
    // t.insertRec(2,t.root);
    // t.insertRec(8,t.root);
    // t.insertRec(6,t.root);
    t.insertItr(5);
    t.insertItr(2);
    t.insertItr(8);
    t.insertItr(6);
    t.insertItr(15);
    t.insertItr(11);
    t.insertItr(25);
    t.insertItr(10);
    t.insertItr(12);
    t.insertItr(20);
    t.insertItr(30);
    t.inorder(t.root);
    cout << endl;
    t.preorder(t.root);
    cout << endl;
    t.postorder(t.root);
    // t.delItr(15);
    // t.inorder(t.root);
    // t.serachItr(2);
    // t.serachItr(10);
}