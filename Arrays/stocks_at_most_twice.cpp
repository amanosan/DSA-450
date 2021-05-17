// Find the maximum profit if the we are allowed to trade at most twice a day
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define vi vector<int>
#define mii map<int, int>
#define pii pair<int, int>
#define psi pair<string, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007 // 1e9 + 7
#define ps(x, y) fixed << setprecision(y) << x

// this approach uses Dynamic Programming, time complexity - O(n), space complexity - O(n)
int max_profit(vi price)
{
    int n = price.size();
    vi profit(n);
    // setting profits as 0 initially
    for (int i = 0; i < n; i++)
        profit.pb(0);

    int max_price = price[n - 1];
    // now traversing from 2nd last element to the first
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] > max_price)
            max_price = price[i];
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    // now traversing from the 2nd element to the last
    for (int i = 1; i < n; i++)
    {
        if (price[i] < min_price)
            min_price = price[i];

        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }

    return profit[n - 1];
}

int32_t main()
{
    vi prices({2, 30, 15, 10, 8, 25, 80});
    cout << max_profit(prices) << "\n";
    return 0;
}
