#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        next == nullptr;
    }
};

void insert_at_head(Node **head, int val)
{
    Node *temp = new Node(val);
    if (!head)
        (*head) = temp;
    else
    {
        temp->next = (*head);
        (*head) = temp;
    }
}

Node *reverse_k(Node *head, int k)
{
    if (head == nullptr)
        return NULL;

    int count = 1;
    Node *next = nullptr, *prev = nullptr;
    Node *current = head;

    while (current != nullptr and count <= k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // now calling recursively, when next is not null
    // that is we still have values after current
    if (next != nullptr)
        head->next = reverse_k(next, k);

    return prev;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "--->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;
    insert_at_head(&head, 8);
    insert_at_head(&head, 7);
    insert_at_head(&head, 6);
    insert_at_head(&head, 5);
    insert_at_head(&head, 4);
    insert_at_head(&head, 3);
    insert_at_head(&head, 2);
    insert_at_head(&head, 1);
    print(head);
    Node *new_head = reverse_k(head, 3);
    print(new_head);
    return 0;
}