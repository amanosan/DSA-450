#include "LinkedList.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    void kth_last_element(int k)
    {
        if (k > size)
        {
            cout << "enter valid value for k.\n";
            return;
        }
        Node *temp = head;
        for (int i = 0; i < size - k; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
};

int main()
{
    LL ll;
    ll.add_first(5);
    ll.add_first(7);
    ll.add_first(10);
    ll.add_first(7);
    ll.add_first(19);
    ll.add_first(6);
    ll.display();
    ll.kth_last_element(3); // output: 10
    ll.kth_last_element(1); // output: 5
    return 0;
}