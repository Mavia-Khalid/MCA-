#include <iostream>
using namespace std;
#include <queue>
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
class Binary_Tree
{
    node *root;

public:
    Binary_Tree()
    {
        root = NULL;
    }
    node *Build_Tree()
    {
        node *r = root;
        int data;
        cout << "\n\t Enter Data : ";
        cin >> data;
        if (data == -1)
        {
            return NULL;
        }
        r = new node(data);
        cout << "\n\t Enter Left Part of " << data << endl;
        r->left = Build_Tree();
        cout << "\n\t Enter Right Part of " << data << endl;
        r->right = Build_Tree();
        return r;
    }
    void Binary_Tre()
    {
        root = Build_Tree();
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
    Binary_Tree t;
    t.Binary_Tre();
    t.LevelOrderTraversal();
    cout << endl;
    return 0;
}