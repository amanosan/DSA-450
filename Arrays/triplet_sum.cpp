// given an array and integer x, find triplet in array if any that sum to x
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

// using two pointer approach
// time complexity - O(n^2), space complexity - O(1)
bool triplet_sum(vi arr, int x)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        int sum = x - arr[i];
        while (j < k)
        {
            if (arr[j] + arr[k] == sum)
                return true;
            else if (arr[j] + arr[k] < sum)
                j++;
            else
                k--;
        }
    }
    return false;
}

int32_t main()
{
    vi arr({1, 4, 45, 6, 10, 8});
    int x = 13;
    bool result = triplet_sum(arr, x);
    cout << result << "\n";
    return 0;
}
