/*
Build a Queue to Stack Adapter using Queues:
Here is the list of functions that you are supposed to complete
    1. push -> Should accept new data in LIFO manner. (can be O(n))
    2. pop -> Should remove and return data in LIFO manner. If not available, print 
    "Stack underflow" and return -1.
    3. top -> Should return data in LIFO manner. If not available, print "Stack 
    underflow" and return -1.
    4. size -> Should return the number of elements available in the stack.

Pop and Top operations should be in constant time. Push can be in linear time.
*/

#include <bits/stdc++.h>
using namespace std;

class QueueToStackAdapter
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
        // shifting all elements from main to helper, so that main is empty
        while (main.size() > 0)
        {
            int temp = main.front();
            main.pop();
            helper.push(temp);
        }
        // now adding val to main queue
        main.push(val);

        // now adding back the elements from helper to main
        while (helper.size() > 0)
        {
            int temp = helper.front();
            helper.pop();
            main.push(temp);
        }
    }

    int pop() // constant time
    {
        if (size() == 0)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        else
        {
            int val = main.front();
            main.pop();
            return val;
        }
    }

    int top() // constant time
    {
        if (size() == 0)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            return main.front();
        }
    }
};

int main()
{
    QueueToStackAdapter q;
    q.push(10);
    cout << q.top() << endl;
    q.push(20);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    return 0;
}