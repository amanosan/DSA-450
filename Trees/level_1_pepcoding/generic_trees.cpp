#include <bits/stdc++.h>
using namespace std;

// Node class for Tree Node.
class Node
{
public:
    int data;
    vector<Node *> child;
};

// FUNCTION TO DISPLAY THE TREE
void display(Node *node)
{
    // displaying the node
    cout << node->data << "-> ";
    for (auto c : node->child)
    {
        cout << c->data << ", ";
    }
    cout << endl;

    // displaying all the children of the current node
    for (auto c : node->child)
        display(c);
}

// FUNCTION TO RETURN SIZE OF TREE
int size_of_tree(Node *node)
{
    int size = 0;
    for (auto c : node->child)
    {
        // getting size of the subtree
        int cs = size_of_tree(c);
        size += cs;
    }
    size += 1; // adding 1 becuase of the current node
    return size;
}

// FUNCTION TO RETURN THE MAXIMUM ELEMENT OF THE TREE
int max_of_tree(Node *node)
{
    int m = INT_MIN;
    for (auto c : node->child)
    {
        int m_subtree = max_of_tree(c);
        m = max(m, m_subtree);
    }
    m = max(m, node->data);
    return m;
}

// FUNCTION TO RETURN HIEGHT OF TREE
int height_of_tree(Node *node)
{
    // int h = -1; // in terms of edges
    int h = 0; // in terms of nodes
    for (auto c : node->child)
    {
        int height_subtree = height_of_tree(c);
        h = max(h, height_subtree);
    }
    h += 1; // adding 1 due to the height of the current node
    return h;
}

// TRAVERSALS IN TREES:
void pre_post_traversal(Node *node)
{
    // euler's left - before recursion call
    cout << "Node Pre " << node->data << "\n";
    for (auto c : node->child)
    {
        cout << "Edge Pre " << node->data << "--" << c->data << "\n";
        pre_post_traversal(c);
        cout << "Edge Post " << node->data << "--" << c->data << "\n";
    }
    // euler's right - after recursion call
    cout << "Node Post " << node->data << "\n";
}

// LEVEL ORDER TRAVERSAL
void level_order(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        // getting the top
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        for (auto c : temp->child)
            q.push(c);
    }
    cout << "\n";
}

// LEVEL ORDER LINEWISE TRAVERSAL
void level_order_linewise(Node *node)
{
    queue<Node *> q;
    queue<Node *> child_q;
    q.push(node);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        for (auto c : temp->child)
            child_q.push(c);

        if (q.empty())
        {
            queue<Node *> empty;
            q.swap(child_q);     // making the child queue as the main queue
            child_q.swap(empty); // making the child queue as empty
            cout << "\n";
        }
    }
}

// LEVEL ORDER LINEWISE ZIGZAG
void level_order_linewise_zigzag(Node *node)
{
    // instead of queues we will use stacks
    stack<Node *> s;       // main stack
    stack<Node *> child_s; // child stack
    int level = 1;
    s.push(node);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";

        // adding according to the level, since we want zigzag
        if (level % 2 == 1)
            for (int i = 0; i < temp->child.size(); i++)
                child_s.push(temp->child[i]);
        else
            for (int i = temp->child.size() - 1; i >= 0; i--)
                child_s.push(temp->child[i]);

        if (s.empty())
        {
            stack<Node *> empty;
            s.swap(child_s);
            child_s.swap(empty);
            level++;
            cout << "\n";
        }
    }
}

int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    stack<Node *> st;
    Node *root;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *temp = new Node();
            temp->data = arr[i];

            // adding the element to children of the top of stack
            if (st.size() > 0)
                st.top()->child.push_back(temp);
            else
                root = temp;
            st.push(temp);
        }
    }
    display(root);
    cout << "Size: " << size_of_tree(root) << "\n";
    cout << "Max: " << max_of_tree(root) << "\n";
    cout << "Height: " << height_of_tree(root) << "\n";
    cout << "Traversals\n";
    pre_post_traversal(root);
    cout << "Level Order Traversal:\n";
    level_order(root);
    cout << "Level Order Linewise Traversal:\n";
    level_order_linewise(root);
    cout << "Level Order Linewise ZigZag:\n";
    level_order_linewise_zigzag(root);
    return 0;
}