#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
    Node *left;
    void helper(Node *right, int floor)
    {
        // we need to take floor becuase we need to terminate when we reach the mid point.
        if (right == nullptr)
            return;

        // traversing the right pointer recursively till the list is empty
        helper(right->next, floor + 1);

        /*
        a -> b -> c -> d -> e
        Intial Case:
        - left is at a
        - right is at e
        1. we make a point to e (left->next = right)
        2. we make e point to b, which is a->next (right->next = temp)
        3. now we need to make b as the left (left = temp, where temp = left->next)
        so from 3. we have moved left to one step ahead.

        We do this till we mid-point of the list
        */
        if (floor > size / 2)
        {
            Node *temp = left->next;
            left->next = right;
            right->next = temp;
            left = temp;
        }
        else if (floor == size / 2)
        {
            right->next = nullptr;
            tail = right;
            tail->next = nullptr;
        }
    }

public:
    void fold()
    {
        left = head;
        helper(head, 0);
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
    cout << "Original:\n";
    ll.display();
    ll.fold();
    cout << "After folding:\n";
    ll.display();
    return 0;
}