#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add 
    up to "tar" or not.
*/

// target sum subsets - SIMILAR TO 0/1 KNAPSACK.
int target_sum(vector<int> &arr, int sum)
{
    int n = arr.size();
    bool **dp = new bool *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new bool[sum];

    // initializing the dp matrix
    // we can make sum = 0 with any number of elements by picking null
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    // we cannot make any sum with 0 elements
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if the number is less than the sum:
            if (arr[i - 1] <= j)
            {
                // we can either take the number or not take the number
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) or (dp[i - 1][j]);
            }
            else
                // when arr[i-1] > j, we will take the previous value for j:
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> arr = {4, 2, 7, 1, 3};
    int target = 10;
    if (target_sum(arr, target))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    return 0;
}