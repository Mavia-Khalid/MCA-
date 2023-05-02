#include <iostream>
using namespace std;
class stack
{
    int top;
    int *arr;
    int size;

public:
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }
    void push(int data)
    {
        if (size - top <= 1)
        {
            cout << "\n\t Stack Overflow ";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\n\t Stack Enderflow ";
        }
        else
        {
            top--;
        }
    }
    int GetSIze()
    {
        return top+1;
    }
    int GetTop()
    {
        if (top == -1)
        {
            cout << "\n\t Stack Empty ";
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    stack *s = new stack(30);
    s->push(50);
    s->push(10);
    s->push(12);
    s->push(22);

    cout << "\n\t " << s->GetTop();
    s->GetSIze();
    cout << endl << endl;
    return 0;
}