#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
    Node *left;
    bool helper(Node *right)
    {
        if (right == nullptr)
            return true;
        // recurisvely making right node reach the end of the list
        bool rec_res = helper(right->next);

        if (rec_res == false)
            return false;
        // comparing the right and left nodes' data
        else if (right->data != left->data)
            return false;
        else
        {
            left = left->next;
            return true;
        }
    }

public:
    bool is_palindrome()
    {
        left = head;
        return helper(head);
    }
};

int main()
{
    LL ll;
    ll.add_last(1);
    ll.add_last(2);
    ll.add_last(3);
    ll.add_last(3);
    ll.add_last(2);
    ll.add_last(1);
    ll.display();
    if (ll.is_palindrome())
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
    return 0;
}