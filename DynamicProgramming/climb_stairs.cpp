#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. In one move, you are allowed to climb 1, 2 or 3 stairs.
4. You are required to print the number of different paths via which you can climb to the top.
*/

// printing the paths of climbing stairs recursive solution
void climb_stairs_recursive(int n, string path)
{
    if (n < 0)
        return;
    // if we have reached 0, we will print the path
    if (n == 0)
    {
        cout << path << "\n";
        return;
    }
    climb_stairs_recursive(n - 1, path + "1"); // climbing down 1 stair
    climb_stairs_recursive(n - 2, path + "2"); // climbing down 2 stairs
    climb_stairs_recursive(n - 3, path + "3"); // climbing down 3 stairs
}

// number of paths recursive
int count_paths(int n)
{
    // if we have reached 0, we have 1 path--> do not move
    if (n == 0)
        return 1;
    // we do not have any path if we get negative answer
    if (n < 0)
        return 0;
    // getting the paths if we take 1, 2, or 3 steps respectively
    int nm1 = count_paths(n - 1);
    int nm2 = count_paths(n - 2);
    int nm3 = count_paths(n - 3);
    // total count
    int cp = nm1 + nm2 + nm3;
    return cp;
}

// climb stairs dynamic programming, memoized
int count_paths_mem(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] > 0)
        return dp[n];

    int nm1 = count_paths_mem(n - 1, dp);
    int nm2 = count_paths_mem(n - 2, dp);
    int nm3 = count_paths_mem(n - 3, dp);
    int count = nm1 + nm2 + nm3;
    dp[n] = count;
    return count;
}

// climb stairs dynamic programming, tabulation
int count_paths_tab(int n)
{
    vector<int> dp(n + 1, 0);
    // starting from 0 we have 1 way:
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            dp[i] = dp[i - 1];
        else if (i == 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main()
{
    int n = 4;
    vector<int> dp(n + 1, 0);
    cout << count_paths(n) << "\n";
    cout << count_paths_mem(n, dp) << "\n";
    cout << count_paths_tab(n) << "\n";
    return 0;
}