#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite 
transactions, but have to cooldown for 1 day after 1 transaction
i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least 
before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed 
(a buy followed by a sell) before opening another transaction (another buy).
*/

void buy_sell_stock_cool_down(vector<int> &arr)
{
    int n = arr.size();
    int bsp = -arr[0]; // bought state profit
    int ssp = 0;       // sold state profit
    int cdp = 0;       // cool down profit

    for (int i = 1; i < n; i++)
    {
        // we can buy after cool down period:
        int nbsp = cdp - arr[i];
        // adding the price at current day to the loan at buying price
        int nssp = bsp + arr[i];
        // we can cool down only after selling the stock
        // since on cool down day we cannot sell and cannot buy
        int ncdp = ssp;

        // we want min buying price, since --> negative --> we take max
        bsp = max(bsp, nbsp);
        // max of selling state and new selling state
        ssp = max(ssp, nssp);
        cdp = max(cdp, ncdp);
    }
    cout << ssp << "\n";
    return;
}

int main()
{
    vector<int> arr1 = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
    // output should be 19
    buy_sell_stock_cool_down(arr1);
    return 0;
}