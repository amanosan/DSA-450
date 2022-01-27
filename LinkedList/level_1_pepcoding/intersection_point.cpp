#include "LinkedList2.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    Node *get_node_at(int idx)
    {
        Node *temp = head;
        for (int i = 1; i < idx; i++)
            temp = temp->next;
        return temp;
    }

    void merge(LL l1, int pt)
    {
        Node *n = l1.get_node_at(pt);
        tail->next = n;
        tail = l1.tail;
        size += l1.size - pt + 1;
    }

    static int intersection_point(LL one, LL two)
    {
        Node *t1 = one.head;
        Node *t2 = two.head;

        /*
        1->2->3->4->5->6->7
        8->9->5->6->7
        We know that the number of nodes after the intersection will be equal
        so we need to find the difference of the size and then traverse the bigger
        linked list by the difference of the size.
        */
        int delta_size = abs(one.size - two.size);

        if (one.size > two.size)
            for (int i = 0; i < delta_size; i++)
                t1 = t1->next;

        if (two.size > one.size)
            for (int i = 0; i < delta_size; i++)
                t2 = t2->next;

        // looping till the nodes are not equal
        while (t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        // while loop terminates when t1 == t2, so we return t1->data or t2->data
        return t1->data;
    }
};

int main()
{
    LL l1;
    LL l2;
    l1.add_last(11);
    l1.add_last(12);
    l1.add_last(13);
    l1.add_last(14);
    l1.add_last(15);
    l1.add_last(16);
    l2.add_last(9);
    l2.add_last(10);

    l2.merge(l1, 4);
    l1.display();
    l2.display();
    cout << l1.size << "\n";
    cout << l2.size << "\n";
    // now we have made 14 as the intersection point
    cout << LL::intersection_point(l1, l2) << "\n";
}