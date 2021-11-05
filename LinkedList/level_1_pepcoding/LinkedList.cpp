#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

class LinkedList
{
public:
    Node *head;
    int size;

    LinkedList()
    {
        head = nullptr;
        size = 0;
    }
    void add_first(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};