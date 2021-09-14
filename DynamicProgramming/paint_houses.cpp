#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
1. You are given a number n, representing the number of houses.
2. In the next n rows, you are given 3 space separated numbers representing the cost of 
    painting nth house with red or blue or green color.
3. You are required to calculate and print the minimum cost of painting all houses without 
    painting any consecutive house with same color.
*/

void paint_houses(vector<vector<int>> &arr)
{
    int n = arr.size();    // houses
    int m = arr[0].size(); // colors (red, green and blue)

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];

    // setting all values equal to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = 0;

    // setting values of first house for each color:
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    // traversing for the second house
    for (int i = 1; i < n; i++)
    {
        // for coloring red:
        // we take cost of coloring current house red
        // and add minimum cost of coloring previous house green or blue
        dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);

        // for coloring green
        // we take cost of coloring current house green
        // and add minimum cost of coloring previous house red or blue
        dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);

        // for coloring blue
        // we take cost of coloring current house blue
        // and add minimum cost of coloring previous house red or green
        dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    // the answer will be minimum of the values in the final column
    int result = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << result << "\n";
}

int32_t main()
{
    vector<vector<int>> arr = {
        {1, 5, 7},
        {5, 8, 4},
        {3, 2, 9},
        {1, 2, 4}};
    // output shoulde be 8.
    paint_houses(arr);
    return 0;
}