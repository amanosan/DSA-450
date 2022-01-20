#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

LinkedList odd_even(LinkedList ll)
{
    LinkedList odd;
    LinkedList even;

    // looping through the linked list
    Node *temp = ll.head;
    while (temp != nullptr)
    {
        if ((temp->data & 1)) // checking for odd/even
        {
            odd.add_last(temp->data);
        }
        else
        {
            even.add_last(temp->data);
        }
        temp = temp->next;
    }
    // checking if we only have odd or even
    if (odd.size == 0)
        return even;
    if (even.size == 0)
        return odd;

    // now connecting the odd to even linked list
    // making odd's last node point to even's head
    Node *temp_odd = odd.head;
    Node *temp_even = even.head;
    // getting last node of
    while (temp_odd->next != nullptr)
        temp_odd = temp_odd->next;

    temp_odd->next = temp_even;
    return odd;
}

int main()
{
    LinkedList ll;
    ll.add_last(2);
    ll.add_last(9);
    ll.add_last(7);
    ll.add_last(8);
    ll.add_last(1);
    ll.add_last(6);
    ll.add_last(5);
    ll.add_last(4);
    cout << "Original Linked List:\n";
    ll.display();
    LinkedList rearranged = odd_even(ll);
    cout << "After applying odd_even() function:\n";
    rearranged.display();
}