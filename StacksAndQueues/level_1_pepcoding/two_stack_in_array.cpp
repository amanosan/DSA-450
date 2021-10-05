/*
1.Two stacks in an array
2. Here is the list of functions that you are supposed to complete
    2.1. push1, push2 -> Should accept new data for appropriate stack if there is 
    space available in the underlying array or print "Stack overflow" otherwise.
    2.2. pop1, po2 -> Should remove and return data from appropriate stack if 
    available or print "Stack underflow" otherwise and return -1.
    2.3. top1, top2 -> Should return data from appropriate stack if available or print 
    "Stack underflow" otherwise and return -1.
    2.4. size1, size2 -> Should return the number of elements available in appropriate 
     stack.

Two stacks should be implemented by using just a single array.
*/
#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
private:
    vector<int> arr;
    int tos1;
    int tos2;
    int cap;

public:
    // the two pointers of the stack will start from -1 and arr.length()
    // tos1 will start from 0th index (left to right)
    // tos2 will start from nth index (right to left)
    TwoStack(int cap)
    {
        this->cap = cap;
        arr = vector<int>(cap);
        tos1 = -1;
        tos2 = arr.size();
    }

    int size1()
    {
        return tos1 + 1;
    }
    int size2()
    {
        return arr.size() - tos2;
    }

    void push1(int val)
    {
        if (tos2 == tos1 + 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            tos1++;
            arr[tos1] = val;
        }
    }

    void push2(int val)
    {
        if (tos2 == tos1 + 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            tos2--;
            arr[tos2] = val;
        }
    }

    int pop1()
    {
        if (size1() == 0)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            int temp = arr[tos1];
            tos1--;
            cout << "Popped from Stack 1: " << temp << "\n";
            return temp;
        }
    }

    int pop2()
    {
        if (size2() == 0)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            int temp = arr[tos2];
            tos2++;
            cout << "Popped from Stack 2: " << temp << "\n";
            return temp;
        }
    }

    int top1()
    {
        if (size1() == 0)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            cout << "Top of Stack 1: " << arr[tos1] << "\n";
            return arr[tos1];
        }
    }

    int top2()
    {
        if (size2() == 0)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            cout << "Top of Stack 2: " << arr[tos2] << "\n";
            return arr[tos2];
        }
    }
};

#include <bits/stdc++.h>
using namespace std;

int main()
{
    TwoStack st(5);
    st.pop1(); // underflow
    st.pop2(); // underflow
    st.top1(); // underflow
    st.top2(); // underflow
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push1(5);
    st.push2(6); // overflow
    st.push1(6); // overflow
    st.pop1();   // 5
    st.pop1();   // 4
    st.top1();   // 3
    st.push2(12);
    st.top2(); // 12
    return 0;

    /*
    Expected Output:
    Stack Underflow
    Stack Underflow
    Stack Underflow
    Stack Underflow
    Stack Overflow
    Stack Overflow
    Popped from Stack 1: 5
    Popped from Stack 1: 4
    Top of Stack 1: 3
    Top of Stack 2: 12
    */
}