#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }

    // function to add to the last
    void add_last(int val)
    {
        Node *new_node = new Node(val);
        if (size == 0)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// function to get the middle node
Node *mid_node(Node *head, Node *tail)
{
    Node *f = head;
    Node *s = head;
    while (f != tail and f->next != tail)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}

// function to merge two sorted lists
LinkedList merge(LinkedList l1, LinkedList l2)
{
    LinkedList result;
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

// function to merge_sort
LinkedList merge_sort(Node *head, Node *tail)
{
    // base case
    // when we have one element, i.e., head is equal to tail
    // then we send a LinkedList with that remaining one element
    if (head == tail)
    {
        LinkedList base_result;
        base_result.add_last(head->data);
        return base_result;
    }
    Node *mid = mid_node(head, tail);
    // getting the first and second halves which are sorted
    LinkedList first_half = merge_sort(head, mid);
    LinkedList second_half = merge_sort(mid->next, tail);
    // merging both the halves to get the complete list
    LinkedList complete_list = merge(first_half, second_half);
    return complete_list;
}

int main()
{
    LinkedList ll;
    ll.add_last(10);
    ll.add_last(14);
    ll.add_last(5);
    ll.add_last(11);
    ll.add_last(2);
    ll.display();
    Node *head = ll.head;
    Node *tail = ll.tail;
    // calling function
    LinkedList result = merge_sort(head, tail);
    result.display();
}
