#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the 
    amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
        used for many installments in payment of "amt"
Note2 -> You are required to find the count of combinations and not permutations i.e.
        2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
        combination. You should treat them as 1 and not 3.
*/

// coin change combination
void coin_change_combination(vector<int> &arr, int target)
{
    int n = arr.size();
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[target + 1];

    // intitializing the array
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= target; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            // if coin denomination is less than equal to the target:
            if (arr[i - 1] <= j)
            {
                // taking both options into consideration
                // 1. taking the coin
                // 2. not taking the coin
                dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << "Number of ways: " << dp[n][target] << "\n";
}

// another approach
void coin_change_combination_2(vector<int> &arr, int target)
{
    int *dp = new int[target + 1];
    for (int i = 0; i < target + 1; i++)
        dp[i] = 0; // setting all values to be 0.
    // to get 0 amount we have 1 way which is to not take any coin
    dp[0] = 1;
    // outer loop is for the coin denominations, since we want combinations
    for (int i = 0; i < arr.size(); i++)
    {
        // inner loop is from the coin to the total target
        for (int j = arr[i]; j <= target; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << "Number of ways: " << dp[target] << "\n";
}

int main()
{
    vector<int> arr = {2, 3, 5, 6};
    int target = 10;
    // output should be 5
    coin_change_combination(arr, target);
    coin_change_combination_2(arr, target);
    return 0;
}