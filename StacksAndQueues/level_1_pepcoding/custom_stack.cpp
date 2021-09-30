#include <bits/stdc++.h>
using namespace std;

class CustomStack
{
private:
    int *arr; // array to store the elemnents of the stack
    int top;  // top pointer to point at the top element
    int cap;  // capacity/size of the stack

public:
    CustomStack();
    CustomStack(int cap);
    void push(int val); // function to push value into stack
    int pop();          // function to pop value from stack
    int get_top();      // function to return the value on top
    void display();     // function to display the stack
    int get_size();     // function to return the size of the stack
};
CustomStack::CustomStack(int cap)
{
    this->cap = cap;
    arr = new int[cap];
    top = -1;
}
void CustomStack::push(int val)
{
    if (top == cap - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        arr[top] = val;
    }
}

int CustomStack::pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int result = arr[top];
    top--;
    return result;
}

int CustomStack::get_top()
{
    return arr[top];
}

void CustomStack::display()
{
    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int CustomStack::get_size()
{
    return cap;
}

int main()
{
    CustomStack st(3);
    st.pop(); // stack underflow
    cout << "Size of the Stack: " << st.get_size() << "\n";
    st.push(4);
    st.push(5);
    cout << st.get_top() << "\n"; // 5
    st.push(10);
    st.push(40); // stack overflow
    return 0;
}