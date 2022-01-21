#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    Node *reverse(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        // if we have reached the tail
        if (node->next == nullptr)
        {
            head = node; // making the tail the new head
            return node;
        }

        // recursively getting the next node till we reach the tail node
        Node *next_node = reverse(node->next);
        // making current node next of next_node, to reverse connection
        next_node->next = node;
        // making current node point to null
        node->next = nullptr;
        return node;
    }
};

int main()
{
    LL ll;
    ll.add_last(1);
    ll.add_last(2);
    ll.add_last(3);
    ll.add_last(4);
    ll.display();
    ll.reverse(ll.head);
    ll.display();
    return 0;
}