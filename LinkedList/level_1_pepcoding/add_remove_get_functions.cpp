#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;   // stores the data
    Node *next; // pointer or reference of the next node

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
        if (size == 0) // when size of linked list is 0
        {
            head = new_node;
            tail = new_node;
        }
        else // if linked list size is not 0
        {
            tail->next = new_node; // adding the new node after the tail
            tail = new_node;       // making the new_node as the new tail
        }
        size++;
    }

    // function to add first in the linked list
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

    // function to add at index:
    void add_at_index(int val, int idx)
    {
        // base condition
        if (idx <= 0 or idx > size)
        {
            cout << "Invalid Index\n";
            return;
        }
        Node *new_node = new Node(val);
        if (idx == 1)
        {
            new_node->next = head;
            head = new_node;
            size++;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        size++;
    }

    // function to remove from head
    void remove_first()
    {
        if (size == 0)
        {
            cout << "Empty List\n";
            return;
        }
        if (size == 1)
        {
            Node *temp = head;
            head = tail = nullptr;
            cout << "Removed: " << temp->data << "\n";
            delete temp;
            size = 0; // size--
            return;
        }
        Node *temp = head;
        head = head->next;
        cout << "Removed: " << temp->data << "\n";
        delete temp;
        size--;
    }

    // function to remove from last
    void remove_last()
    {
        if (size == 0)
        {
            cout << "Empty List\n";
            return;
        }
        if (size == 1)
        {
            Node *temp = head;
            head = tail = nullptr;
            cout << "Removed: " << temp->data << "\n";
            delete temp;
            size = 0;
            return;
        }
        // to remove from last, we need to go to the last element and second last element
        Node *temp = head;    // points to last element
        Node *prev = nullptr; // points to second last element
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        size--;
        cout << "Removed: " << temp->data << "\n";
        tail = prev;
        prev->next = nullptr;
        delete temp;
    }

    // function to remove at index
    void remove_at_index(int idx)
    {
        if (idx <= 0 or idx > size)
        {
            cout << "Ivalid Index\n";
            return;
        }
        if (idx == 1)
        {
            remove_first();
            return;
        }
        if (idx == size)
        {
            remove_last();
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        for (int i = 1; i < idx; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        cout << "Removed: " << temp->data << "\n";
        prev->next = temp->next;
        delete temp;
        size--;
    }

    // function to get first node:
    void get_first()
    {
        if (size == 0)
        {
            cout << "Linked List empty\n";
            return;
        }
        cout << "Element at First Index: " << head->data << "\n";
    }

    // function to get the last node:
    void get_last()
    {
        if (size == 0)
        {
            cout << "Linked List empty\n";
            return;
        }
        cout << "Element at Last Index: " << tail->data << "\n";
    }

    // function to get value at particular index:
    void get_value_at_index(int i)
    {
        if (i > size)
        {
            cout << "Invalid Index: " << i << ", try again\n";
            return;
        }
        if (size == 0)
        {
            cout << "Linked list empty\n";
            return;
        }
        Node *temp = head;
        for (int j = 1; j < i; j++)
        {
            temp = temp->next;
        }
        cout << "Data at index " << i << ": " << temp->data << "\n";
    }

    // function to get the size of the linked list
    int size_of()
    {
        cout << "Size of Linked List: " << size << "\n";
        return size;
    }
    // function to display the linked list
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

int main()
{
    LinkedList ll;
    ll.add_last(10);
    ll.add_last(20);
    ll.add_last(30);
    ll.display();
    ll.remove_first();
    ll.display();
    ll.remove_first();
    ll.display();
    ll.remove_first();
    ll.display();
    ll.remove_first();
    ll.display();
    ll.add_last(10);
    ll.add_last(20);
    ll.add_last(30);
    ll.display();
    ll.get_first();
    ll.get_last();
    ll.get_value_at_index(1);
    ll.get_value_at_index(2);
    ll.get_value_at_index(3);
    ll.get_value_at_index(4);
    ll.add_first(9);
    ll.add_first(8);
    ll.display();
    ll.add_at_index(6, 1);
    ll.display();
    ll.add_at_index(11, 4);
    ll.display();
    ll.remove_last();
    ll.display();
    ll.remove_first();
    ll.display();
    ll.remove_at_index(3);
    ll.display();
    ll.remove_at_index(3);
    ll.display();
    return 0;
}