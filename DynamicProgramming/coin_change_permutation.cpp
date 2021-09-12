#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of permutations of the n coins using which the 
    amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
        used for many installments in payment of "amt"
Note2 -> You are required to find the count of permutations and not combinations i.e.
        2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
        combination. You should treat them as 3 and not 1.
*/

void coin_change_permutations(vector<int> &coins, int target)
{
    vector<int> dp(target + 1, 0);
    // number of ways to get 0 from coins is 1 --> do not give/take anything
    dp[0] = 1;

    // the outer loop is for the target sum
    for (int i = 1; i <= target; i++)
    {
        // the inner loop is for the coins, since we need permutations
        for (int j = 0; j < coins.size(); j++)
        {
            // if the denomination of coin is smaller than or equal to the target
            // we add number of ways we can have (target - coin denomination)
            if (coins[j] <= i)
                dp[i] += dp[i - coins[j]];
        }
    }
    cout << dp[target] << "\n";
}

int main()
{
    vector<int> coins = {2, 3, 5, 6};
    int target = 10;
    // output should be 17
    coin_change_permutations(coins, target);
    return 0;
}