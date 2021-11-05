#include "LinkedList.cpp"
#include <bits/stdc++.h>
using namespace std;

class LinkedListReverse : public LinkedList
{
private:
    Node *get_node_at(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

public:
    LinkedListReverse()
    {
        head = nullptr;
        size = 0;
    }

    // function to reverse using data attribute and not the pointer
    void reverse()
    {
        int li = 0;
        int ri = size - 1;

        while (li < ri)
        {
            Node *left = get_node_at(li);
            Node *right = get_node_at(ri);

            // swapping the data of left and right nodes
            int temp = left->data;
            left->data = right->data;
            right->data = temp;

            li++;
            ri--;
        }
    }
};

int main()
{
    LinkedListReverse ll;
    ll.add_first(20);
    ll.add_first(15);
    ll.add_first(10);
    ll.add_first(5);
    cout << "Before reversing:\n";
    ll.display();
    ll.reverse();
    cout << "After reversing:\n";
    ll.display();
}