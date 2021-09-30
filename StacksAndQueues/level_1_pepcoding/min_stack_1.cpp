#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    int size;
    int top;      // pointer to top element in stack
    int min;      // pointer to min element in stack
    int *arr;     // array to store elements of stack
    int *min_arr; // array to store min elements of stack

public:
    MinStack() // default constructor
    {
        top = 1;
        min = -1;
        arr = new int[5];
        min_arr = new int[5];
    }
    MinStack(int size) // parameterized constructor
    {
        this->size = size;
        top = -1;
        min = -1;
        arr = new int[size];
        min_arr = new int[size];
    }
    void push(int val)
    {
        if (top == size - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = val;
            if (min == -1)
            {
                min++;
                min_arr[min] = val;
            }
            else if (val < min_arr[min])
            {
                min++;
                min_arr[min] = val;
            }
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
        {
            // popping from arr
            int result = arr[top];
            cout << result << " popped from Stack" << endl;
            top--;
            if (result == min_arr[min])
            {
                min--;
            }
        }
    }
    void get_min() // function to get the minimum element in the stack
    {
        cout << "Min Value in Stack: ";
        cout << min_arr[min] << endl;
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    void get_top()
    {
        cout << "Top Element in Stack: " << arr[top] << "\n";
    }
};

int main()
{
    MinStack st(5);
    st.pop();
    st.push(15);
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(3);
    st.push(1);
    st.get_min();
    st.pop();
    st.get_min();
    st.display();
    st.get_top();
    return 0;
}