#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Linked_List
{

public:
    Node *head;
    Node *tail;
    Linked_List()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void InsertAtHead(int data)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void InsertAtTail(int data)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }

        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
    void Insert(int data, int pos)
    {
        if (pos == 1)
        {
            InsertAtHead(data);
            return;
        }

        int len = GetSize();
        if (pos > len)
        {
            InsertAtTail(data);
            return;
        }

        Node *prev = head;
        int i = 1;
        while (i < pos - 1)
        {
            prev = prev->next;
            i++;
        }
        Node *curr = prev->next;
        Node *newNode = new Node(data);
        newNode->next = curr;
        prev->next = newNode;
    }
    void Delete(int pos)
    {
        if (head == NULL)
        {
            cout << "\n\t Linked List is Empty ";
            return;
        }

        if (pos == 1)                           // Delete at Head
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        int len = GetSize();
        if (pos == len)                         // Delete at Tail
        {
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            Node *temp = tail;
            prev->next = NULL;
            tail = prev;
            delete temp;
            return;
        }

        Node* prev = head;
        int i = 1;
        while (i < pos - 1)
        {
            prev = prev->next;
            i++;
        }
        Node* curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    // void insert(int data)              // Insertion at End By Traversing
    // {
    //     Node* temp = head;
    //     while(temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     Node* newNode = new Node(data);
    //     temp -> next = newNode;
    // }

    void print()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty " << endl;
            return;
        }
        Node *Temp = head;
        cout << "\n\t Head : " << head->data << endl;
        cout << "\t Tail : " << tail->data << endl;
        cout << "\n\t";
        while (Temp != NULL)
        {
            cout << " " << Temp->data;
            Temp = Temp->next;
        }
    }
    int GetSize()
    {
        int i = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
};
void reverse(Linked_List* l)
{
    Node *prev = NULL;
    Node* curr = l->head;
    //Node* curr = l->head;
    while(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp; 
    }
    l->tail = l->head;
    l->head = prev;
}
Node* Reverse(Node* prev , Node* curr)
{
    if(curr == NULL)
    {
        return prev;
    }     
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    return Reverse(prev , curr); 
}
int main()
{
    Linked_List *List1 = new Linked_List();
    for (int i = 1; i <= 20; i++)
    {
        List1->InsertAtTail(i);
    }
    
    List1->print();
    cout << "\n\t Size of LL : " << List1->GetSize() << endl;

    // List1->Insert(100, 8);
    // List1->print();

    // cout << "\n\t Size of LL : " << List1->GetSize();

    // List1->Delete(4);
    // List1->print();

    // cout << "\n\t Size of LL : " << List1->GetSize();

    Node* prev = NULL;
    Node* curr  = List1->head;
    Node* temp = Reverse(prev , curr);
    cout << temp->data << endl;
    List1->tail = List1->head;
    List1->print();
    
    cout << endl;
    cout << endl;
    return 0;
}