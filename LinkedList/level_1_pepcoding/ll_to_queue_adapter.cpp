#include <bits/stdc++.h>
using namespace std;

class QueueAdapter
{
private:
    list<int> q;

public:
    int size()
    {
        return q.size();
    }
    void add(int x)
    {
        q.push_back(x);
    }
    void remove()
    {
        if (size() == 0)
        {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Removed: " << q.front() << "\n";
        q.pop_front();
    }
    void front()
    {
        if (size() == 0)
        {
            cout << "Queue Empty\n";
            return;
        }
        cout << "First Element: " << q.front() << "\n";
    }
    void display()
    {
        for (auto element : q)
        {
            cout << element << "  ";
        }
        cout << "\n";
    }
};

int main()
{
    QueueAdapter q;
    q.remove();
    q.front();
    q.add(10);
    q.add(20);
    q.add(30);
    q.display();
    q.remove();
    q.display();
    q.front();
    cout << "Size: " << q.size() << "\n";
    q.remove();
    q.display();
    q.front();
    return 0;
}