#include <bits/stdc++.h>
using namespace std;

// min element has to be displayed using constant time and space.
class MinStack
{
private:
    int top;
    int min_value;
    int size;
    int *arr;

public:
    MinStack()
    {
        top = -1;
        min_value = -1;
        arr = new int[5];
    }
    MinStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
        min_value = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        if (top == -1)
        {
            top++;
            arr[top] = val;
            min_value = val;
        }
        else if (val >= min_value)
        {
            top++;
            arr[top] = val;
        }
        else // if value is less than the current min_value
        {
            top++;
            // detection: storing a fake smaller value
            arr[top] = val + (val - min_value);
            min_value = val;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }

        int val = arr[top];
        top--;
        if (val >= min_value)
        {
            cout << val << " popped" << endl;
        }
        else // if the popped element is the min_value
        {
            int original_value = min_value;
            // arr[top] = val + (val - min)
            // min = val;
            // so to get back the original value:
            // min = (2 * val) - arr[top]  --> (val == min) by second line
            // min = (2 * val) - val -val + min;
            // min = min;
            min_value = (2 * min_value) - (arr[top]);
            // the above will restore the min value
            cout << original_value << " popped" << endl;
            return;
        }
    }

    void top()
    {
        if (arr[top] >= min_value)
        {
            cout << arr[top] << "\n";
            return;
        }
        // if not, we stored the encrypted value (val + val - min_value)
        // and stored the value in the min_value, so we return the min_value:
        else
        {
            cout << min_value << "\n";
        }
    }

    void get_min()
    {
        if (top == -1)
        {
            cout << "Stack Underflow : -1" << endl;
            return;
        }
        cout << min_value << endl;
    }
};

int main()
{
    return 0;
}