#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without 
    overflowing it's capacity.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item 
        again and again.
*/

int zero_one_knapsack(vector<int> &wt, vector<int> &val, int target)
{
    int n = wt.size();

    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[target + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
            dp[i][j] = -1;
    }

    // for every element we will see if we put into the bag or not.
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            // initialization
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            // if the weight of item i is less than capacity j
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            // if the weight of item i is greater than capacity j
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // with n elements and given target, result is:
    return dp[n][target];
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int target = 50;
    cout << zero_one_knapsack(wt, val, target) << "\n";
    return 0;
}