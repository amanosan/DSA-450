#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given n numbers, where ith element's value represents - till how far from the step you 
    could jump to in a single move.  You can of-course fewer number of steps in the move.
4. You are required to print the number of minimum moves in which you can reach the top of 
    staircase.
Note -> If there is no path through the staircase print null.
*/

int min_jumps(int n, vector<int> &arr)
{
    vector<int> dp(n + 1, -1);
    // there is one path from n to n --> do not move from n.
    // but number of moves to go from n to n is 0.
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        //we will check if we can take any steps, ie. the steps should not be 0
        if (arr[i] > 0)
        {
            // taking min value
            int min_steps = INT_MAX;
            // taking loop from 1 to number of steps we can take:
            for (int j = 1; j <= arr[i] and i + j < dp.size(); j++)
            {
                // if the value is not null then we update the min value
                if (dp[i + j] != -1)
                    min_steps = min(min_steps, dp[i + j]);
            }
            // if min value was updated, then we insert it into the dp
            if (min_steps != INT_MAX)
                dp[i] = 1 + min_steps;
        }
    }
    // returning the minimum steps from 0 to n
    return dp[0];
}

int main()
{
    int n = 10;
    vector<int> arr = {1, 1, 1, 4, 9, 8, 1, 1, 10, 1};
    // output should be 5
    cout << min_jumps(n, arr) << "\n";
    return 0;
}