#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of friends.
2. Each friend can stay single or pair up with any of it's friends.
3. You are required to print the number of ways in which these friends can stay single or pair up.
E.g.
1 person can stay single or pair up in 1 way.
2 people can stay singles or pair up in 2 ways. 12 => 1-2, 12.
3 people (123) can stay singles or pair up in 4 ways. 123 => 1-2-3, 12-3, 13-2, 23-1.
*/

void friends_pairing(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1; // number of ways 1 person can pair
    dp[2] = 2; // number of ways 2 people can pair --> both alone or both together

    for (int i = 3; i <= n; i++)
    {
        // ith person has two options:
        // 1. staying alone, ie. not forming a pair
        //      in which case we will need number of ways for i - 1 people, excluding i
        // 2. forming a pair with any of the remaining i-1 people
        //      in which case i can form pair in (i-1) ways
        //      and then we call for remaining i-2 people --> dp[i-2]
        dp[i] = dp[i - 1] + ((i - 1) * dp[i - 2]);
    }
    cout << dp[n] << "\n";
    return;
}

int main()
{
    // output should be 10.
    friends_pairing(4);
    // output should be 26
    friends_pairing(5);
    return 0;
}