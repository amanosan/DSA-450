/*
Here is the list of functions that you are supposed to complete
    1. push -> Should accept new data in LIFO manner.
    2. pop -> Should remove and return data in LIFO manner. If not available, print 
    "Stack underflow" and return -1.
    3. top -> Should return data in LIFO manner. If not available, print "Stack 
    underflow" and return -1.
    4. size -> Should return the number of elements available in the stack.

Push should be constant in time, Pop and Top can be of linear time
*/

#include <bits/stdc++.h>
using namespace std;

class QueuetoStackAdapter // from FIFO to LIFO
{
private:
    queue<int> main;
    queue<int> helper;

public:
    int size()
    {
        return main.size();
    }

    void push(int val)
    {
        main.push(val);
    }

    int pop()
    {
        if (size() == 0)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        // removing from the main queue till last element
        while (main.size() > 1)
        {
            int temp = main.front();
            main.pop();
            helper.push(temp);
        }
        // we dont push last element from to the helper as we want to remove it
        int popped = main.front();
        main.pop();
        // shifting the elements from helper to main queue
        while (helper.size() > 0)
        {
            int temp = helper.front();
            helper.pop();
            main.push(temp);
        }
        return popped;
    }

    int top()
    {
        if (size() == 0)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        // removing from main to helper till the last element
        while (main.size() > 1)
        {
            int temp = main.front();
            main.pop();
            helper.push(temp);
        }
        // last element in the main is the top element:
        int top_element = main.front();
        main.pop();
        // pushing last element to the helper
        helper.push(top_element);

        // now shifting from helper to main queue
        while (helper.size() > 0)
        {
            int temp = helper.front();
            helper.pop();
            main.push(temp);
        }
        return top_element;
    }
};

int main()
{
    QueuetoStackAdapter q;
    q.pop();
    q.top();
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Top: " << q.top() << "\n";
    cout << "Popped: " << q.pop() << "\n";
    cout << "Top: " << q.top() << "\n";
    q.pop();
    cout << "Top: " << q.top() << "\n";
    return 0;
}