#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be 
    partitioned in k non-empty subsets.
E.g.
For n = 4 and k = 3 total ways is 6
12-3-4
1-23-4
13-2-4
14-2-3
1-24-3
1-2-34
*/

void partition_into_subsets(int n, int k)
{
    // k - number of teams, n - number of people
    // dp[n][k] = number of ways for n people to form k teams.
    int **dp = new int *[k + 1];
    for (int i = 0; i <= k; i++)
        dp[i] = new int[n + 1];

    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    // if we have 0 teams we have 0 ways to form 0 teams
    // if we have 0 people we have 0 ways to form any team

    // if we have only 1 team and n people number of ways = 1 (only 1 team can be formed)
    for (int j = 0; j <= n; j++)
        dp[1][j] = 1;

    // if n < k, we cannot form k teams --> 0 ways
    // if n == k, then each person is in each team --> 1 way

    // traversing through team size.
    for (int i = 2; i <= k; i++)
    {
        // traversing through number of people
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                dp[i][j] = 0;
            else if (j == i)
                dp[i][j] = 1;

            // if number of people are greater than the team size
            // jth person has two options:
            // 1. Form one team and let remaining people form remaining number of teams:
            //      which is --> dp[i-1][j-1]
            // 2. let remaining people form all the teams and join in anyone of the teams:
            //      which is --> dp[i][j-1] * (i)
            //      since jth person will have dp[i][j-1] number of teams to join in i ways
            else
                dp[i][j] = dp[i - 1][j - 1] + (i * dp[i][j - 1]);
            // 1st term --> number of ways for (n-1) teams and (k-1) people.
            // 2nd term --> number of ways for n teams with (k-1) people.
        }
    }
    cout << dp[k][n] << "\n";
    return;
}

int32_t main()
{
    // output should be 6
    partition_into_subsets(4, 3);
    // output should be 0, since cannot divide 3 people into 4 teams
    partition_into_subsets(3, 4);
    // output should be 10
    partition_into_subsets(5, 4);
    return 0;
}
