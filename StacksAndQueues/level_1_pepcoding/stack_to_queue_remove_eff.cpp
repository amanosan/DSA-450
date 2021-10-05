/*
1. Stack to Queue Adapter.
2. Here is the list of functions that are written in the class 
    2.1. add -> Accepts new data if there is space available in the underlying array or 
    print "Queue overflow" otherwise.
    2.2. remove -> Removes and returns value according to FIFO, if available or print 
    "Queue underflow" otherwise and return -1.
    2.3. peek -> Returns value according to FIFO, if available or print "Queue 
    underflow" otherwise and return -1.
    2.4. size -> Returns the number of elements available in the queue.

The Remove and Top functions should be constant time, Add can be of linear time
*/

#include <bits/stdc++.h>
using namespace std;

class StacktoQueueAdapter
{
private:
    stack<int> main;
    stack<int> helper;

public:
    int size()
    {
        return main.size();
    }

    void add(int val)
    {
        if (main.size() == 0)
        {
            main.push(val);
            return;
        }

        // shifting from main to helper
        while (main.size() > 0)
        {
            int temp = main.top();
            main.pop();
            helper.push(temp);
        }
        main.push(val);
        // shifting from helper to main
        while (helper.size() > 0)
        {
            int temp = helper.top();
            helper.pop();
            main.push(temp);
        }
    }

    int remove()
    {
        if (size() == 0)
        {
            cout << "Queue Empty\n";
            return -1;
        }
        else
        {
            int temp = main.top();
            main.pop();
            cout << "Removed: " << temp << "\n";
            return temp;
        }
    }

    int front()
    {
        if (size() == 0)
        {
            cout << "Queue Empty\n";
            return -1;
        }
        else
        {
            int temp = main.top();
            cout << "Front: " << temp << "\n";
            return temp;
        }
    }
};

int main()
{
    StacktoQueueAdapter st;
    st.remove();
    st.front();
    st.add(10);
    st.front();
    st.add(20);
    st.front();
    st.remove(); // should remove 10
    st.front();  // new front should be 20.
    return 0;
}