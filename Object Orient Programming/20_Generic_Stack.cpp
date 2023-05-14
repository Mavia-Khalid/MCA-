#include<iostream>
using namespace std;
template<class type>
class Stack
{
    type *arr;
    int top;
    int size;
    public:
    Stack(int size)
    {
        this->size = size;
        arr = new type[size];
        top = -1;        
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }
    int getSize()
    {
        return top+1;
    }
    type getTop()
    {
        if(top > -1)
        {
            return *(arr+top);
        }
        cout << "\n\t Stack Underflow ";
        return -1;
    }
    void push(type data)
    {
        if(top >= size-1)
        {
            cout << "\n\t Stack Overflow ";
            return;
        }
        top++;
        *(arr+top) = data;
    }
    type pop()
    {
        if(top == -1)
        {
            cout << "\n\t Stack Underflow ";
            return -1;
        }
        type element = *(arr+top);
        top--;
        return element;
    }
};
int main()
{
    Stack<int> s1(30);
    Stack<char> s2(30);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << "\n\t Element at Top : " << s1.getTop() << endl;
    cout << "\t Stack Size : " << s1.getSize() << endl;
    cout << "\t Popped Element : " << s1.pop() << endl;
    cout << "\t Popped Element : " << s1.pop() << endl;

    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');

    cout << "\n\t Element at Top : " << s2.getTop() << endl;
    cout << "\t Stack Size : " << s2.getSize();

    for(int i = 0; i < 4; i++)
    {
        cout << "\n\t Popped Element : " << s2.pop();
    }
    cout << "\n\t Stack Size : " << s2.getSize() << endl;

    cout << endl;
    return 0;
}
