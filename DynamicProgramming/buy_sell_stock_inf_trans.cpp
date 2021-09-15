#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed 
infinite transactions.
Note - There can be no overlapping transaction. One transaction needs to be closed 
(a buy followed by a sell) before opening another transaction (another buy)
*/

void buy_sell_stock_inf_trans(vector<int> &arr)
{
    int n = arr.size();
    // initially taking both selling and buying dates as 0
    int buy = 0;
    int sell = 0;
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        // when the price of i is higher than i-1, we increasing the selling date
        if (arr[i] >= arr[i - 1])
            sell++;
        // if not then we calculate the profit and make the ith day as both selling
        // and buying and continue the process
        else
        {
            profit += arr[sell] - arr[buy];
            buy = i;
            sell = i;
        }
    }
    // if the price at the last date is also increasing, then we need to add it to the profit
    // example:
    // 1 2 3 4 --> buying = 1, selling = 4, but there is no dip
    // so we need to calculate the profit after the loop.
    profit += arr[sell] - arr[buy];

    cout << profit << "\n";
}

int main()
{
    vector<int> arr = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    // output should be 30
    buy_sell_stock_inf_trans(arr);
    return 0;
}