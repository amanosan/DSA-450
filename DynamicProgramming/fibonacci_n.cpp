#include <bits/stdc++.h>
using namespace std;

// function to print the nth fibonacci term
int fibonacci(int n, vector<int> &dp)
{
    // base condition for 0 and 1
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return dp[n];
    }
    // if already exists:
    if (dp[n] != 0)
        return dp[n];

    // if does not exist, we call the function for n-1 and n-2
    int nm1 = fibonacci(n - 1, dp);
    int nm2 = fibonacci(n - 2, dp);
    int fibn = nm1 + nm2;

    // storing the nth fibonacci term in the dp array
    dp[n] = fibn;
    return fibn;
}

int main()
{
    int n = 10;
    vector<int> dp(n + 1, 0);
    cout << fibonacci(10, dp) << endl;
    return 0;
}