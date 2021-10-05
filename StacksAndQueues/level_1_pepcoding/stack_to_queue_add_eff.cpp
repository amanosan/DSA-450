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

The Add function should be constant time, Remove and Front can be of linear time.
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

    void add(int val) // constant time
    {
        main.push(val);
    }

    int remove() // linear time.
    {
        if (size() == 0)
        {
            cout << "Queue Empty\n";
            return -1;
        }
        // removing from the main to helper except the last element:
        while (main.size() > 1)
        {
            int temp = main.top();
            main.pop();
            helper.push(temp);
        }

        // the last element has to be removed:
        int removed = main.top();
        main.pop();

        // now moing elements back to main from helper
        while (helper.size() > 0)
        {
            int temp = helper.top();
            helper.pop();
            main.push(temp);
        }
        cout << "Removed: " << removed << "\n";
        return removed;
    }

    int front() // linear time
    {
        if (size() == 0)
        {
            cout << "Queue Empty\n";
            return -1;
        }
        // moving from main to helper except the last element:
        while (main.size() > 1)
        {
            int temp = main.top();
            main.pop();
            helper.push(temp);
        }
        // last element in main will be front
        int front_val = main.top();
        main.pop();
        helper.push(front_val);

        // moving from helper back to main
        while (helper.size() > 0)
        {
            int temp = helper.top();
            helper.pop();
            main.push(temp);
        }
        cout << "Front: " << front_val << "\n";
        return front_val;
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