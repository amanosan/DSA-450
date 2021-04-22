// best day to buy and sell stocks
#include <bits/stdc++.h>
using namespace std;

// naive approach, time complexity - O(n^2)
int max_profit_naive(vector<int> arr)
{
    int n = arr.size();
    int max_profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            max_profit = max(max_profit, (arr[j] - arr[i]));
        }
    }
    return max_profit;
}

// peak and valley approach, time complexity- O(n)
int max_profit_optimized(vector<int> prices)
{
    int n = prices.size();
    int max_profit = INT_MIN;
    int buy = prices[0];

    for (int i = 1; i < n; i++)
    {
        if (buy > prices[i])
            buy = prices[i];

        max_profit = max(max_profit, (prices[i] - buy));
    }
    return max(max_profit, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << max_profit_naive(arr) << endl;
    cout << max_profit_optimized(arr) << endl;
    return 0;
}