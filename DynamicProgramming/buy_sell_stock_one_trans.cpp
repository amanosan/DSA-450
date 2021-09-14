#include <bits/stdc++.h>
using namespace std;

void buy_sell_stock_one_trans(vector<int> &arr)
{
    int n = arr.size();
    int buy = arr[0];    // starting by taking day 0 as buying day, it stores the least from i-1 to 1
    int best_so_far = 0; // best till day i
    int best = 0;        // overall best profit

    // traversing through each day.
    for (int i = 1; i < n; i++)
    {
        // checking if the previous buying amount is smaller than current day price
        if (buy <= arr[i])
        {
            // checking if profit by selling at current day price is best so far
            if (arr[i] - buy >= best_so_far)
                best_so_far = arr[i] - buy;
        }
        // if the current day price is smaller than the previous buy
        else if (arr[i] < buy)
        {
            // we change our buying price to the the price of the current day
            buy = arr[i];
        }
        // the overall best will be the max of best and best so far.
        best = max(best_so_far, best);
    }
    cout << best << "\n";
}

int main()
{
    vector<int> arr1 = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    vector<int> arr2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // output should be 17 (18 - 1)
    buy_sell_stock_one_trans(arr1);
    // output should be 0, since we wont be able to make any profit
    buy_sell_stock_one_trans(arr2);
    return 0;
}