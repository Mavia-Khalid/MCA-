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
        return top + 1;
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
        return 0;
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
void Display_Middle(stack &s, int &size)
{
    if (s.GetSIze() == 0)
    {
        cout << "There is no element in stack" << endl;
        return;
    }
    if (s.GetSIze() == size / 2 + 1)
    {
        cout << "\n\t" << s.GetTop();
        return;
    }
    int TopElement = s.GetTop();
    s.pop();
    Display_Middle(s, size);
    s.push(TopElement);
}
int main()
{
    stack *s = new stack(30);
    s->push(50);
    s->push(10);
    s->push(12);
    s->push(22);
    s->push(25);
    int size = s->GetSIze();
    Display_Middle(*s, size);
    cout << endl << endl;
    return 0;
}