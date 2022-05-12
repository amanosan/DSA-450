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

// FUNCTION TO REMOVE LEAVES
void remove_leaves(Node *node)
{
    for (int i = node->child.size() - 1; i >= 0; i--)
    {
        Node *c = node->child[i];
        if (c->child.size() == 0)
            node->child.erase(node->child.begin() + i);
    }

    for (auto c : node->child)
        remove_leaves(c);
}

// LINEARIZE GENERIC TREE
Node *get_tail(Node *node)
{
    while (node->child.size() == 1)
    {
        node = node->child[0];
    }
    return node;
}
// time complexity - O(N^2)
void linearize(Node *node)
{
    for (auto c : node->child)
    {
        linearize(c);
    }
    while (node->child.size() > 1)
    {
        Node *last = node->child[node->child.size() - 1];                // getting the last child
        node->child.erase(node->child.begin() + node->child.size() - 1); // removing the last child
        Node *second_last = node->child[node->child.size() - 1];         // getting second last child
        Node *second_last_tail = get_tail(second_last);
        second_last_tail->child.push_back(last); // connecting tail of second last to last child
    }
}
// a better approach - time complexity - O(N)
Node *linearize_2(Node *node)
{
    // base case
    if (node->child.size() == 0)
        return node;
    // linearizing the last node and getting it's tail
    Node *last_tail = linearize_2(node->child[node->child.size() - 1]);
    while (node->child.size() > 1)
    {
        // getting the last node
        Node *last = node->child[node->child.size() - 1];
        // removing the last node now
        node->child.erase(node->child.begin() + node->child.size() - 1);
        Node *second_last = node->child[node->child.size() - 1];
        Node *second_last_tail = linearize_2(second_last);
        second_last_tail->child.push_back(last);
    }
    return last_tail;
}

// FIND ELEMENT IN TREE
bool find_element(Node *node, int value)
{
    if (node->data == value)
    {
        cout << "Found\n";
        return true;
    }
    for (auto c : node->child)
    {
        bool is_found = find_element(c, value);
        if (is_found)
            return true;
    }
    return false;
}

// NODE TO ROOT PATH
vector<int> node_to_root(Node *node, int data)
{
    if (node->data == data)
    {
        vector<int> temp;
        temp.push_back(node->data);
        return temp;
    }
    // searching for path in children of the node
    for (auto c : node->child)
    {
        vector<int> path_till_child = node_to_root(c, data);
        if (path_till_child.size() > 0)
        {
            // this means that there exists a path
            path_till_child.push_back(node->data);
            return path_till_child;
        }
    }
    vector<int> temp;
    return temp;
}

// LOWEST COMMON ANCESTOR
int lowest_common_ancestor(Node *node, int d1, int d2)
{
    vector<int> path1 = node_to_root(node, d1);
    vector<int> path2 = node_to_root(node, d2);

    int p1 = path1.size() - 1;
    int p2 = path2.size() - 1;
    // the lowest common ancestor will be the last common element in
    // both the paths from node
    while (p1 >= 0 and p2 >= 0 and path1[p1] == path2[p2])
    {
        p1--;
        p2--;
    }
    // now both the pointers are at the first uncommon element
    // to get the last common we increment the pointers again
    p1++;
    p2++;
    return path1[p1];
}

// DISTANCE BETWEEN TWO NODES
int distance_between_nodes(Node *node, int d1, int d2)
{
    auto path1 = node_to_root(node, d1);
    auto path2 = node_to_root(node, d2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;

    while (i >= 0 and j >= 0 and path1[i] == path2[j])
    {
        i--;
        j--;
    }
    // getting the lowest common ancestor
    i++;
    j++;
    // now the remaining elements will be the distance
    int dist = i + j;
    return dist;
}

// ARE TWO TREES SIMILAR IN SHAPE
bool is_similar(Node *node1, Node *node2)
{
    if (node1->child.size() != node2->child.size())
        return false;

    for (int i = 0; i < node1->child.size(); i++)
    {
        Node *child1 = node1->child[i];
        Node *child2 = node2->child[i];
        // checking if children are same
        if (is_similar(child1, child2) == false)
            return false;
    }
    return true;
}

// ARE TWO TREES MIRROR IMAGES OF EACH OTHER
bool is_mirror(Node *node1, Node *node2)
{
    if (node1->child.size() != node2->child.size())
        return false;

    for (int i = 0; i < node1->child.size(); i++)
    {
        // pointer from right, i is the pointer from left
        int j = node1->child.size() - 1 - i;
        Node *c1 = node1->child[i];
        Node *c2 = node2->child[j];

        if (is_mirror(c1, c2) == false)
            return false;
    }
    return true;
}

// IS TREE SYMMETRIC
bool is_symmetric(Node *node)
{
    // a tree is symmetric if it is a mirror image of itself
    return is_mirror(node, node);
}

// MULTISOLVER
int size_tree = 0;
int min_val = INT_MAX;
int max_val = INT_MIN;
int height = 0;
void multisolver(Node *node, int depth)
{
    size_tree++;
    min_val = min(min_val, node->data);
    max_val = max(max_val, node->data);
    height = max(height, depth);

    for (auto c : node->child)
        multisolver(c, depth + 1);
}

// PREDECESSOR AND SUCCESSOR OF NODE
Node *pred;
Node *succ;
int state_var1 = 0;
void pred_succ(Node *node, int val)
{

    if (state_var1 == 0)
    {
        if (node->data == val)
            state_var1 = 1;
        else
            pred = node;
    }
    else if (state_var1 == 1)
    {
        succ = node;
        state_var1 = 2;
    }

    // running for each child of the node
    for (auto c : node->child)
        pred_succ(c, val);
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
    // cout << "Removing Leaves:\n";
    // remove_leaves(root);
    // level_order_linewise(root);
    // cout << "Linearizing the Tree:\n";
    // linearize(root);
    // linearize_2(root);
    level_order_linewise(root);
    cout << "Finding Element:\n";
    find_element(root, 110);
    cout << "Path from Node till Root:\n";
    vector<int> ntr = node_to_root(root, 110);
    for (auto x : ntr)
        cout << x << " ";
    cout << "\n";
    cout << "Lowest Common Ancestor:\n";
    cout << lowest_common_ancestor(root, 110, 90) << "\n";
    cout << "Distance between Nodes:\n";
    cout << distance_between_nodes(root, 70, 110) << "\n";
    cout << "Checking for Similarity:\n";
    if (is_similar(root, root))
        cout << "Similar\n";
    else
        cout << "Not Similar\n";

    cout << "Checking for Mirror Image:\n";
    if (is_mirror(root, root))
        cout << "Mirror Image\n";
    else
        cout << "Not Mirror Image\n";

    cout << "Checking for Symmetry:\n";
    if (is_symmetric(root))
        cout << "Symmetrical\n";
    else
        cout << "Not Symmetrical\n";

    cout << "Multisolver Values:\n";
    multisolver(root, 0);
    cout << "Size: " << size_tree << "\n";
    cout << "Min: " << min_val << "\n";
    cout << "Max: " << max_val << "\n";
    cout << "Height: " << height << "\n";

    cout << "Predecessor and Successor:\n";
    pred_succ(root, 90);
    cout << "Predecessor: " << pred->data << "\n";
    cout << "Successor: " << succ->data << "\n";
    return 0;
}