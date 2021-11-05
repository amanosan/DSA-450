#include <bits/stdc++.h>
using namespace std;

// Adapting the linked list to act as a Stack - Linked List to Stack Adapter.
class StackAdapter
{
private:
    list<int> l;

public:
    int size()
    {
        return l.size();
    }
    void push(int x)
    {
        l.push_front(x);
    }
    void pop()
    {
        if (l.size() == 0)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Element popped: " << l.front() << "\n";
        l.pop_front();
    }
    void top()
    {
        if (l.size() == 0)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Top Element: " << l.front() << "\n";
    }
    void display()
    {
        for (auto element : l)
        {
            cout << element << "  ";
        }
        cout << "\n";
    }
};

int main()
{
    StackAdapter st;
    st.top();
    st.pop();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    st.top();
    st.pop();
    st.display();
    st.top();
    return 0;
}