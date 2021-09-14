#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number k separated by a space, representing the number of 
    houses and number of colors.
2. In the next n rows, you are given k space separated numbers representing the cost of 
    painting nth house with one of the k colors.
3. You are required to calculate and print the minimum cost of painting all houses without 
    painting any consecutive house with same color.
*/

// time complexity = O(n^3)
void solution_1(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];

    // setting initiale values as 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = 0;

    // cost of painting first house will remain same:
    for (int i = 0; i < n; i++)
        dp[0][i] = arr[0][i];

    // traversing for each house
    for (int i = 1; i < n; i++)
    {
        // traversing through each color
        for (int j = 0; j < m; j++)
        {
            int min_val = INT_MAX;
            // finding the minimum cost for all colors except for j,
            // as we do not want adjacent houses of same color.
            for (int k = 0; k < m; k++)
            {
                if (k != j)
                    min_val = min(min_val, dp[i - 1][k]);
            }

            dp[i][j] = arr[i][j] + min_val;
        }
    }

    // now the minimum cost will be at the last row:
    int result = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        result = min(result, dp[n - 1][i]);
    }

    cout << result << "\n";
}

// optimized - time complexity - O(n^2)
// to optimize we will take min and second min element as we go through the houses (rows)
void solution_2(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];

    // setting initiale values as 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = 0;

    int least = INT_MAX, second_least = INT_MAX;
    // filling the first row:
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = arr[0][j];
        if (arr[0][j] <= least)
        {
            least = arr[0][j];
            second_least = least;
        }
        else if (arr[0][j] <= second_least)
            second_least = arr[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        int new_least = INT_MAX;
        int new_second_least = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            // we will see if the min value of previous houses is the least
            // we will then add second least value since we don't want adjacent
            // houses to be painted same
            if (least == dp[i - 1][j])
                dp[i][j] = arr[i][j] + second_least;
            else
                dp[i][j] = arr[i][j] + least;

            // calculating the least and the second least
            if (dp[i][j] <= new_least)
            {
                new_least = dp[i][j];
                new_second_least = new_least;
            }
            else if (dp[i][j] <= new_second_least)
                new_second_least = dp[i][j];
        }

        // updating the value of least and second least
        least = new_least;
        second_least = new_second_least;
    }
    // the min cost will be at the 'least' of the last row:
    cout << least << endl;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 5, 7},
        {5, 8, 4},
        {3, 2, 9},
        {1, 2, 4}};

    // output should be 8
    solution_1(arr);
    solution_2(arr);
    return 0;
}