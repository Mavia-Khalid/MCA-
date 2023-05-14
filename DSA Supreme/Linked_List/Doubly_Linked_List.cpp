#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
class Doubly_List
{

public:
    Node *head;
    Node *tail;
    Doubly_List()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    int GetSize()
    {
        int len = 0;
        Node* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    void InsertAtHead(int data)
    {
        if(head == NULL)
        {
            Node* newNode = new Node(data);
            head= newNode;
            tail = newNode;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void InsertAtTail(int data)
    {
        if(head == NULL)
        {
            Node* newNode = new Node(data);
            head= newNode;
            tail = newNode;
            return;
        }
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void Insert(int data , int pos)
    {
        if(pos == 1)
        {
            InsertAtHead(data);
            return;
        }
        int len = GetSize();
        if(pos > len)
        {
            InsertAtTail(data);
            return;
        }
        Node* newNode = new Node(data);
        int i = 1;
        Node* prev = head;
        while(i < pos-1)
        {
            prev = prev->next;
            i++;
        }
        newNode->next = prev->next;
        newNode->prev = prev;
        (prev->next)->prev = newNode;    // or store prev->next in a new node current and use that
        prev->next = newNode;
    }
    void Print_List()
    {
        if(head == NULL)
        {
            cout << "\n\t Linked List is Empty " << endl;
            return;
        }
        cout << "\n\t Head : " << head->data << endl;
        cout << "\t Tail : " << tail->data << endl;
        Node* temp = head;
        cout << "\n\t";
        while(temp != NULL)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
    void Delete(int pos)
    {
        if(pos < 1 || pos > GetSize())
        {
            return;
        }
        if(head == NULL)
        {
            cout << "Linked List is Empty " << endl;
            return;
        }
        if(pos == 1)
        {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            return;
        }
        int len  = GetSize();
        if(pos == len)
        {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
        Node* prev = head;
        int i = 1;
        while(i < pos-1)
        {
            prev = prev->next;
            i++;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        (temp->next)->prev = prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp; 
        return;
    }
};
Node* Reverse(Node* prev , Node* curr)
{
    if(curr == NULL)
    {
        return prev;
    }     
    Node* temp = curr->next;
    curr->next = prev;
    curr->prev = temp;
    prev = curr;
    curr = temp;
    return Reverse(prev , curr);   
}
void Reverse(Doubly_List* List)
{
    Node* curr = List->head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        curr->prev = temp;
        prev = curr;
        curr = temp;
    }
    List->tail = List->head;
    List->head = prev;
}
void ReverseDirect(Doubly_List* l)
{
    Node* s = l->head;
    Node* t = l->tail;
    int i = 0;
    while(i < l->GetSize()/2)
    {
        swap(s->data,t->data);
        s = s->next;
        t = t->prev;
        i++;
    }
}
int GetMiddle(Doubly_List* l)
{
    Node* slow = l->head;
    Node* fast = l->head->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow->data;
}
int main()
{
    Doubly_List* list1 = new Doubly_List();
    for (int i = 1; i <= 20; i++)
    {
        list1->InsertAtTail(i);
    }
    // list1->InsertAtTail(70);
    // list1->InsertAtHead(10);
    // list1->InsertAtHead(20);
    // list1->InsertAtTail(80);
    // list1->InsertAtTail(90);
    // list1->Insert(0 , 4);
    // list1->Insert(30 , 1);
    // list1->Insert(40 , 7);
    list1->Print_List();

    cout << "\n\t Size of LL : " << list1->GetSize() << endl;

    // Node* prev = NULL;
    // Node* curr = list1->head;
    // list1->tail = list1->head;
    // list1->head = Reverse(prev , curr);
    cout << "\n\t " << GetMiddle(list1) << endl;
    ReverseDirect(list1);
    list1->Print_List();
    cout << "\n\t " << GetMiddle(list1) << endl;
    cout << endl << endl;
    return 0;
}