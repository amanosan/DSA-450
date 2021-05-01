// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

#include <bits/stdc++.h>
using namespace std;
#define int long long

void subarray_with_sum_zero(vector<int> arr)
{
    int n = arr.size();
    map<int, bool> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 or mp[sum] == true)
        {
            cout << "YES\n";
            return;
        }
        else
            mp[sum] = true;
    }
    cout << "NO\n";
    return;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    subarray_with_sum_zero(arr);
    return 0;
}