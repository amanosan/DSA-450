#include "LinkedList.cpp"
#include <bits/stdc++.h>
using namespace std;

class LinkedListReverse : public LinkedList
{
private:
public:
    LinkedListReverse()
    {
        head = nullptr;
        size = 0;
    }

    // function to reverse linked list using pointer iterative approach
    void reverse()
    {
        Node *temp;           // to store current's next node
        Node *current = head; // current pointer
        Node *prev = nullptr; // previous pointer

        while (current != nullptr)
        {
            temp = current->next;

            // reversing the link
            current->next = prev;
            // updating the current and previous pointers
            prev = current;
            current = temp;
        }
        // making the prev as head pointer
        head = prev;
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
    cout << "After reversing:\n";
    ll.reverse();
    ll.display();
}