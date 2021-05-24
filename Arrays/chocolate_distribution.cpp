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

// time complexity - O(nlogn)
int chocolate_distribution(vi arr, int m)
{
    int n = arr.size();
    int min = INT_MAX;
    // sorting the array
    sort(arr.begin(), arr.end());

    // now checking the subarrays:
    for (int i = 0; i < n - m; i++)
    {
        if ((arr[m - 1 + i] - arr[i]) < min)
        {
            min = arr[m - 1 + i] - arr[i];
        }
    }
    return min;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << chocolate_distribution(arr, m) << "\n";
    return 0;
}
