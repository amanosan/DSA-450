#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n representing the length of a floor space which is 2m wide. 
It's a 2 * n board.
2. You've an infinite supply of 2 * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.
*/

void tile_2x1(int n)
{
    // we have a floor of (2 x n) and tile of (2 x 1)

    vector<int> dp(n + 1, 0);
    dp[1] = 1; // number of ways to tile 2 x 1 floor
    dp[2] = 2; // number of ways to tile 2 x 2 floor (both horizontal or both vertical)

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << "\n";
}

int main()
{
    int n = 8;
    // output should be 34
    tile_2x1(n);
    return 0;
}