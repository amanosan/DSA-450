#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are given a number k, representing the number of transactions allowed.
3. You are required to print the maximum profit you can make if you are allowed k 
transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed
(a buy followed by a sell) before opening another transaction (another buy).
*/

// unoptimized solution - time complexity = O(n^3)
void solution1(vector<int> &arr, int k)
{
    int n = arr.size();
    int **dp = new int *[k + 1];
    for (int i = 0; i <= k; i++)
        dp[i] = new int[n];

    for (int i = 0; i <= k; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    // // if we have 0 transactions allowed or just 1 day, profit = 0
    // for (int i = 0; i <= k; i++)
    //     dp[i][0] = 0;
    // for (int i = 0; i < n; i++)
    //     dp[0][i] = 0;

    // traversing through number of transactions
    for (int t = 1; t <= k; t++)
    {
        // traversing through each day for given transaction
        for (int d = 1; d < n; d++)
        {
            // to calculate we have two options:
            // 1. value of t transactions till d-1 days.
            // 2. max value of t-1 transactions from any day from 0 to d-1
            // and 't'th transaction between d and (0 to d-1) day.
            // we will take the maximum of the above two values.

            // finding max of 0 to d-1 days for t-1 transactions:
            int max_profit = dp[t][d - 1];
            for (int pd = 0; pd < d; pd++)
            {
                // value of t-1 transaction for days:
                int temp = dp[t - 1][pd];
                // value of t th transaction for d-1 and d day
                int profit = arr[d] - arr[pd];

                max_profit = max(max_profit, temp + profit);
            }

            dp[t][d] = max_profit;
        }
    }
    cout << dp[k][n - 1] << endl;
}

// optimized solution - time complexity - O(n^2)
void solution2(vector<int> &arr, int k)
{
    int n = arr.size();
    int **dp = new int *[k + 1];
    for (int i = 0; i <= k; i++)
        dp[i] = new int[n];

    for (int i = 0; i <= k; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    // traversing through the transactions
    for (int t = 1; t <= k; t++)
    {
        int max_profit = INT_MIN;
        // traversing through the days
        for (int d = 1; d < n; d++)
        {
            if (dp[t - 1][d - 1] - arr[d - 1] > max_profit)
                max_profit = dp[t - 1][d - 1] - arr[d - 1];

            if (max_profit + arr[d] > dp[t][d - 1])
                dp[t][d] = max_profit + arr[d];
            else
                dp[t][d] = dp[t][d - 1];
        }
    }

    cout << dp[k][n - 1] << "\n";
    return;
}

int main()
{
    vector<int> arr = {9, 6, 7, 6, 3, 8};
    int k = 3;
    // output should be 6
    solution1(arr, k);
    solution2(arr, k);
    return 0;
}