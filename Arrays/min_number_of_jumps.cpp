// Find the minimum number of jumps required to reach end of array

#include <bits/stdc++.h>
using namespace std;

// using dynamic programming tabulation method
// time complexity is O(n^2)
int minJumps(vector<int> v)
{
    vector<int> jumps_to_reach(v.size());
    // since number of jumps to reach 0th index will be 0
    jumps_to_reach[0] = 0;
    for (int i = 1; i < v.size(); i++)
    {
        jumps_to_reach[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (v[j] + j >= i && jumps_to_reach[j] != INT_MAX)
                jumps_to_reach[i] = min(jumps_to_reach[j] + 1, jumps_to_reach[i]);
        }
    }
    return (jumps_to_reach[v.size() - 1] != INT_MAX) ? jumps_to_reach[v.size() - 1] : -1;
}

// optimizing the solution, time complexity - O(n)
int minJumpsOptimized(vector<int> arr)
{
    int n = arr.size();
    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1; // min 1 jump we have to do to proceed ahead

    if (n <= 1)
        return 0;
    else if (arr[0] == 0)
        return -1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            // checking if i has reached final point
            if (i == n - 1)
            {
                return jump;
            }
            // updating max reach now
            maxReach = max(maxReach, arr[i] + i);
            step--;

            // if step becomes zero, we need to jump and updat step
            if (step == 0)
            {
                jump++;
                if (i >= maxReach)
                    return -1;

                step = maxReach - i;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << minJumps(v) << endl;
        cout << minJumpsOptimized(v) << endl;
    }
    return 0;
}