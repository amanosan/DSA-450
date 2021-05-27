// given an array, find smallest subarray with sum greater than x
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

// we will be using sliding window approach
// time complexity - O(n)
int solve(vi arr, int x)
{
    int n = arr.size();
    int sum = 0, ans = INT_MAX;
    int start = 0, end = 0;
    while (end < n)
    {
        // increasing the window size till the sum is not greater than x
        while (sum <= x && end < n)
        {
            sum += arr[end];
            end++;
        }

        // decreasing the window size till sum is greater than x.
        while (sum > x && start < n)
        {
            ans = min(ans, end - start);
            sum -= arr[start];
            start++;
        }
    }
    return ans;
}

int32_t main()
{
    int n, x;
    cin >> n >> x;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, x);
    return 0;
}
