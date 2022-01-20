#include "Node.cpp"
#include <bits/stdc++.h>
using namespace std;

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

    // function to add to first
    void add_first(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        if (size == 0)
        {
            tail = temp;
        }
        size++;
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