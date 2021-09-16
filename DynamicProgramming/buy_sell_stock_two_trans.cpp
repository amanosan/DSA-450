#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed 
two transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed 
(a buy followed by a sell) before opening another transaction (another buy).
*/

void buy_sell_stock_two_trans(vector<int> &arr)
{
    int n = arr.size();

    // finding max profit if sold today or before today
    vector<int> before(n, 0);
    before[0] = 0;
    int mpist = 0;
    int lsf = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < lsf)
            lsf = arr[i];

        mpist = arr[i] - lsf;
        if (mpist > before[i - 1])
            before[i] = mpist;
        else
            before[i] = before[i - 1];
    }

    // finding max profit if bought today or after today
    vector<int> after(n, 0);
    after[n - 1] = 0;
    int mpibt = 0;
    int gsf = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > gsf)
            gsf = arr[i];

        // selling at greatest price after today:
        mpibt = gsf - arr[i];
        if (mpibt > after[i + 1])
            after[i] = mpibt;
        else
            after[i] = after[i + 1];
    }

    // at each i:
    // before --> stores the best transaction on the left of i including i
    // after --> stores the best transaction on the right of i including i
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, before[i] + after[i]);
    }
    cout << result << "\n";
}

int main()
{
    vector<int> arr = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    // output should be 30
    buy_sell_stock_two_trans(arr);
    return 0;
}