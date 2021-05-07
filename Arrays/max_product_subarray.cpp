// Find Subarray with maximum product, the array may contain +ve, -ve or 0.

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
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

// time complexity - O(n), space complexity - O(1)
int max_product(vi &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    int result = 1;
    int min_prod = 1, max_prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            max_prod = max(max_prod, max_prod * arr[i]);
            min_prod = min(min_prod, min_prod * arr[i]);
        }
        else if (arr[i] < 0)
        {
            swap(min_prod, max_prod);
            min_prod = min(min_prod, min_prod * arr[i]);
            max_prod = max(max_prod, max_prod * arr[i]);
        }
        // since we want subarray, once we encounter 0, we will start getting 0 as the product
        // hence we reset the max and min products as soon as we encounter 0
        else if (arr[i] == 0)
        {
            max_prod = 1;
            min_prod = 1;
        }
        result = max(max_prod, result);
    }
    return result;
}

int32_t main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << max_product(arr) << "\n";
    return 0;
}