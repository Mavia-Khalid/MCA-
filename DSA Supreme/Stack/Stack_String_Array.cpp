#include <iostream>
using namespace std;
class stack
{
    int top;
    string *arr;
    int size;

public:
    stack(int size)
    {
        arr = new string[size];
        this->size = size;
        top = -1;
    }
    void push(string data)
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
    int GetSize()
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
            cout << "\n\t" << arr[top];
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
    s->push("mavia");
    s->push("aa");
    s->push("a");
    s->push("22");
    cout << "\n\t" << s->GetSize();
    s->GetTop();
    s->pop();
    s->GetTop();
    cout << endl<< endl;
    return 0;
}