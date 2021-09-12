#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without 
    overflowing it's capacity.
Note -> Each item can be taken any number of times. You are allowed to put the same item again 
        and again.
*/

void unbounded_knapsack(vector<int> &wt, vector<int> &val, int target)
{
    int n = wt.size();
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[target + 1];
    // setting the values of the 2D array with -1
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= target; j++)
            dp[i][j] = -1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            // we will take the max of both conditions:
            // 1. if we put the item in the bag.
            // 2. if we don't put the item in the bag.
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            // if weight of the item is bigger than capacity, we will not take the item
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][target] << "\n";
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {10, 40, 50, 70};
    int target = 8;
    // output should be 110
    unbounded_knapsack(wt, val, target);
    return 0;
}