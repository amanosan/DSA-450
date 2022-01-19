#include "LinkedList.cpp"
#include <bits/stdc++.h>
using namespace std;

class LL : public LinkedList
{
public:
    void add_last(int val)
    {
        Node *newnode = new Node(val);
        if (size == 0)
        {
            head = newnode;
            size++;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        size++;
    }
};

LL merge(LL l1, LL l2)
{
    LL result;
    Node *one = l1.head;
    Node *two = l2.head;

    while (one != nullptr and two != nullptr)
    {
        if (one->data < two->data)
        {
            result.add_last(one->data);
            one = one->next;
        }
        else
        {
            result.add_last(two->data);
            two = two->next;
        }
    }
    while (one != nullptr)
    {
        result.add_last(one->data);
        one = one->next;
    }
    while (two != nullptr)
    {
        result.add_last(two->data);
        two = two->next;
    }
    return result;
}

int main()
{
    LL ll1;
    ll1.add_first(9);
    ll1.add_first(6);
    ll1.add_first(5);
    ll1.add_last(11);
    LL ll2;
    ll2.add_first(10);
    ll2.add_first(7);
    ll2.add_first(4);
    ll1.display();
    ll2.display();

    LL final = merge(ll1, ll2);
    final.display();
    return 0;
}