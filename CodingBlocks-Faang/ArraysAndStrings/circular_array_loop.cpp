#include <bits/stdc++.h>
using namespace std;

// function to get the next index
int next_index(vector<int> v, int current)
{
    // the below calculation will not give us negative index
    return (current + v[current] + v.size()) % v.size();
}

bool circular_loop(vector<int> v)
{
    // we will have 2 pointers, slow and fast
    // slow moves by one step
    // fast moves by two steps
    int n = v.size();
    // we will check for each index as the starting point of the cycle
    for (int i = 0; i < n; i++)
    {
        int slow = i, fast = i;
        // the value at the next index should be of the same sign
        // for both the poiters, slow pointer and fast pointer
        // a[sp] * a[next(a, sp)] > 0

        if (v[i] == 0)
            continue;
        while (
            (v[slow] * v[next_index(v, slow)] > 0) and
            (v[fast] * v[next_index(v, fast)] > 0) and
            (v[fast] * v[next_index(v, next_index(v, fast))] > 0))
        {
            // sending slow to take one step
            slow = next_index(v, slow);
            // sending fast to take two steps
            fast = next_index(v, next_index(v, fast));

            // condition for cycle
            if (fast == slow)
            {
                // checking that cycle length should be greater than 1
                // ie. the next index of slow should not be slow itself
                if (slow == next_index(v, slow))
                    break;
                return true;
            }
        }

        // when we know that a cycle cannot be made
        // we take that element and make elements with same sign as 0
        slow = i;
        int val = v[slow];
        while (val * v[slow] > 0)
        {
            int x = slow;
            slow = next_index(v, slow);
            v[x] = 0;
        }
    }
    return false;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << circular_loop(v) << "\n";
    // input:
    // 5
    // 2 -1 1 2 2
    // output: 1
    return 0;
}