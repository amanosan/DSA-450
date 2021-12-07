#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

class LL : public LinkedList
{
public:
    void middle_node()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast->next != nullptr and fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle Element: " << slow->data << " \n";
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
    ll.middle_node();
}