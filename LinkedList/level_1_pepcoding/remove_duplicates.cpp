// Remove Duplicates in SORTED linked list.
#include "LinkedList.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    void add_last(int val)
    {
        Node *new_node = new Node(val);
        if (size == 0)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new_node;
        }
        size++;
    }
};

LL remove_duplicates(LL ll)
{
    LL result;
    Node *temp = ll.head;

    // adding the first element of ll to result
    result.add_last(temp->data);
    temp = temp->next;

    Node *tail = result.head;

    // traversing through the entire linked list
    while (temp != nullptr)
    {
        // recent element in linked list with duplicates
        int first_ele = temp->data;
        // recent element in linked list without duplicates
        int second_ele = tail->data;

        // if the first_ele is same as second_ele
        if (first_ele == second_ele)
        {
            temp = temp->next;
        }
        else
        {
            result.add_last(first_ele);
            tail = tail->next;
        }
    }
    return result;
}

int main()
{
    LL ll;
    ll.add_first(5);
    ll.add_first(5);
    ll.add_first(5);
    ll.add_first(5);
    ll.add_first(4);
    ll.add_first(4);
    ll.add_first(3);
    ll.add_first(2);
    ll.add_first(2);
    ll.add_first(2);
    cout << "Original Linked List: \n";
    ll.display();
    LL result = remove_duplicates(ll);
    cout << "After removing duplicates: \n";
    result.display();
    return 0;
}