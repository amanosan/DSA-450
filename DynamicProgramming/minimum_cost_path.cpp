#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
4. You are standing in top-left cell and are required to move to bottom-right cell.
5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom- 
    right cell).
7. You are required to traverse through the matrix and print the cost of path which is least 
*/

int minimum_cost_path(vector<vector<int>> &cost)
{
    int n = cost.size();
    int m = cost[0].size();

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = 0;

    // cost of going from (0,0) to (0,0):
    dp[0][0] = cost[0][0];

    // initializing the first row
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + cost[0][j];

    // initializing the first column
    for (int j = 1; j < n; j++)
        dp[j][0] = dp[j - 1][0] + cost[j][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // the last cell will have the answer
    return dp[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> cost = {{1, 7, 9, 2}, {8, 6, 3, 2}, {1, 6, 7, 8}, {2, 9, 8, 2}};
    // output should be 29
    cout << minimum_cost_path(cost) << "\n";
    return 0;
}