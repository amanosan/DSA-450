#include <bits/stdc++.h>
using namespace std;

/*

1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are give a number fee, representing the transaction fee for every transaction.
4. You are required to print the maximum profit you can make if you are allowed 
infinite transactions, but has to pay "fee" for every closed transaction.
Note - There can be no overlapping transaction. One transaction needs to be closed 
(a buy followed by a sell) before opening another transaction (another buy).
*/

void buy_sell_stock_inf_trans_fee(vector<int> &arr, int fee)
{
    int n = arr.size();
    // if we buy at the first day, we will be -10 rupees in loan
    int buying_state = -arr[0];
    // cannot sell on first day as we don't have any stock with us
    int sell_state = 0;

    for (int i = 1; i < n; i++)
    {
        // sell state on 2nd day:
        // we can sell on previous bought state
        // so we add the amount we are getting and deducting the fee
        int ns = arr[i] + buying_state - fee;
        // buying state on 2nd day:
        // we can do this on previous sold state as we cannot buy without selling first
        int nb = sell_state - arr[i];

        // we will select the buying day where we have the min loan
        // max since loans are in negative.
        buying_state = max(buying_state, nb);
        // we will select teh selling day where we get maximum profit
        sell_state = max(sell_state, ns);
    }
    cout << sell_state << "\n";
    return;
}

int main()
{
    vector<int> arr1 = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
    int fee1 = 3;
    // output should be 13
    buy_sell_stock_inf_trans_fee(arr1, fee1);

    vector<int> arr2 = {10, 20, 30};
    int fee2 = 2;
    // output should be 18
    buy_sell_stock_inf_trans_fee(arr2, fee2);
    return 0;
}