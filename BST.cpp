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

public:
    node *root;
    BST()
    {
        root = NULL;
    }
    node *Insert(node *r, int data)
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
            root = Insert(root, data);
            cin >> data;
        }
    }
    void PreOrderTraversal(node *r)
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
    void InOrderTraversal(node *r)
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
    void PostOrderTraversal(node *r)
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
                if (!q.empty())
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
    bool FindNode(node *temp, int key)
    {

        if (temp == NULL)
        {
            return false;
        }
        if (temp->data == key)
        {
            return true;
        }
        if (temp->data > key)
        {
            return FindNode(temp->left, key);
        }
        else
        {
            return FindNode(temp->right, key);
        }
    }
    bool Find_Key(int key)
    {
        bool ans = FindNode(root, key);
        return ans;
    }
    int height(node* temp)
    {
        if(temp == NULL)
        {
            return 0;
        }
        int LeftAns = height(temp->left);
        int rightans = height(temp->right);
        int ans = max(LeftAns,rightans)+1;
        return ans;
    }
    int GetSize(node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return GetSize(root->left) + GetSize(root->right) + 1;
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
    cout << "\t Key is " << tree.Find_Key(15);
    cout << "\n\t Height : " << tree.height(tree.root);
    cout << "\n\t Size : " << tree.GetSize(tree.root);
    cout << endl;
    return 0;
}