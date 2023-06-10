#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST
{
    node *root;

public:
    BST()
    {
        root = NULL;
    }
    node* Insert(node *r, int data)
    {
        if (r == NULL)
        {
            r = new node(data);
            return r;
        }
        if (r->data > data)
        {
            r->left = Insert(r->left, data);
        }
        else
        {
            r->right = Insert(r->right, data);
        }
        return r;
    }
    void insert()
    {
        int data;
        cout << "\n\t Enter Data : ";
        cin >> data;
        while (data != -1)
        {
            root = Insert(root,data);
            cin >> data;
        }
    }
    void PreOrderTraversal(node* r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << " " << r->data;
        PreOrderTraversal(r->left);
        PreOrderTraversal(r->right);
    }
    void PrintPreOrder()
    {
        cout << "\n\t Pre Order Traversal : ";
        PreOrderTraversal(root);
    }
    void InOrderTraversal(node* r)
    {
        if (r == NULL)
        {
            return;
        }
        InOrderTraversal(r->left);
        cout << " " << r->data;
        InOrderTraversal(r->right);
    }
    void PrintInOrder()
    {
        cout << "\n\t In Order Traversal : ";
        InOrderTraversal(root);
    }
    void PostOrderTraversal(node* r)
    {
        if (r == NULL)
        {
            return;
        }
        PostOrderTraversal(r->left);
        PostOrderTraversal(r->right);
        cout << " " << r->data;
    }
    void PrintPostOrder()
    {
        cout << "\n\t Post Order Traversal : ";
        PostOrderTraversal(root);
    }
    void LevelOrderTraversal()
    {
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << " " << temp->data;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            
        }
    }
};
int main()
{
    BST tree;
    tree.insert();
    tree.PrintPreOrder();
    tree.PrintInOrder();
    tree.PrintPostOrder();
    cout << endl;
    tree.LevelOrderTraversal();
    cout << endl;
    return 0;
}