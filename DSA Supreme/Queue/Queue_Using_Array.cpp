#include <iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = 0;
        rear = 0;
    }
    void push(int data)
    {
        if(rear == size)
        {
            cout << "\n\t Queue Overflow ";
            return;
        }
        arr[rear] = data;
        rear++;
    }
    void pop()
    {
        if(front == rear)
        {
            cout << "\n\t Queue is Empty ";;
            return;
        }
        arr[front] = -1;
        front++;
        if(front == rear)
        {
            front = 0;
            rear = 0;
        }
    }
    int getfront()
    {
        if(front == rear)
        {
            cout << "\n\t Queue is Empty ";;
            return -1;
        }
        return arr[front];

    }
    int getsize()
    {
        return rear - front;
    }
    bool isEmpty()
    {
        if(front == rear)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue *q = new Queue(20);
    q->push(30);
    q->push(25);
    q->push(20);
    q->push(15);
    q->push(10);
    while (!q->isEmpty())
    {
        cout << "\n\t" << q->getfront();
        q->pop();
    }
    
    cout << endl;
    cout << endl;
}