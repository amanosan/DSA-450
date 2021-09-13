#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number m separated by line-break representing the length and breadth of a m * n floor.
2. You've an infinite supply of m * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.
*/

// this is similar to tiling with tiles (2 x 1)
void tile_mx1(int n, int m)
{
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        // we wont be able to fit the tile horizontally if width of floor is less than tile.
        if (i < m)
            dp[i] = 1;
        // if width of tile and floor are equal
        // we can put all horizontally
        // we can put all vertically
        else if (i == m)
            dp[i] = 2;
        else
            // when we keep vertically, remaining width of floor = i - 1
            // when we keep horizontally, remaining width of floor = i - m
            dp[i] = dp[i - 1] + dp[i - m];
    }

    cout << dp[n] << "\n";
}

int main()
{
    int n = 39;
    int m = 16;
    // output should be 61
    tile_mx1(n, m);
    return 0;
}
