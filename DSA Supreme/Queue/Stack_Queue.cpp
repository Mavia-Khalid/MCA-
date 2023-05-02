#include <iostream>
using namespace std;
class StackQueue
{
    int front;
    int rear;
    int *arr;
    int size;
    int top;
public:
    StackQueue(int size)
    {
        arr = new int[2*size];
        this->size = size;
        front = 2*size;
        rear = 2*size;
        top = -1;
    }
    void Push_Stack(int data)
    {
        if(top >= size-1)
        {
            cout << "\n\t Stack Overflow ";
            return;
        }
        arr[++top] = data;
    }
    void Pop_Stack()
    {
        if(top == -1)
        {
            cout << "\n\t Stack Underflow ";
            return;
        }
        top--;
    }
    void Push_Queue(int data)
    {
        if(rear == size)
        {
            cout << "\n\t Queue Overflow ";
            return;
        }
        arr[--rear] = data;
    }
    void Pop_Queue()
    {
        if(front == rear)
        {
            cout << "\n\t Queue is Empty ";;
            return;
        }
        arr[--front] = -1;
    }
    int GetTop()
    {
        if(top == -1)
        {
            cout << "\n\t Stack Underflow ";
            return -1;
        }
        return arr[top];
    }
    int GetFront()
    {
        if(front == rear)
        {
            cout << "\n\t Queue is Empty ";;
            return -1;
        }
        return arr[front-1];
    }
};
int main()
{
    StackQueue *sq = new StackQueue(3);
    sq->Push_Stack(1);
    sq->Push_Stack(2);
    sq->Push_Stack(3);
    sq->Push_Stack(4);
    sq->Push_Queue(4);
    sq->Push_Queue(5);
    sq->Push_Queue(6);
    sq->Push_Queue(6);
    cout << endl;
    cout << sq->GetTop() << " ";
    cout << sq->GetFront() << " ";
    
    cout << endl;
    cout << endl;
    return 0;
}