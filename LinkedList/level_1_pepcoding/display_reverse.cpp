#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    void display_reverse_helper(Node *node)
    {
        if (node == nullptr)
            return;
        display_reverse_helper(node->next);
        cout << node->data << " --> ";
    }

    void display_reverse()
    {
        display_reverse_helper(this->head);
        cout << "NULL\n";
    }
};

int main()
{
    LL ll;
    ll.add_last(1);
    ll.add_last(2);
    ll.add_last(3);
    ll.add_last(4);
    ll.add_last(5);
    ll.add_last(6);
    cout << "Normal Display" << endl;
    ll.display();
    cout << "Reverse Display" << endl;
    ll.display_reverse();
    return 0;
}