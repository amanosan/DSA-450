#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    void reverse_data_rec_helper(Node *right, int floor)
    {
        if (right == nullptr)
            return;

        reverse_data_rec_helper(right->next, floor + 1);

        if (floor >= size / 2)
        {
            // swapping data of left and right node
            int temp = right->data;
            right->data = left->data;
            left->data = temp;

            // moving the left node forward
            left = left->next;
        }
    }
    Node *left;
    void reverse_data_rec()
    {
        left = head;
        reverse_data_rec_helper(left, 0);
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
    cout << "original\n";
    ll.display();
    ll.reverse_data_rec();
    cout << "reversed\n";
    ll.display();
    return 0;
}