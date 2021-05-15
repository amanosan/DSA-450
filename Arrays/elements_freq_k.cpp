// Given an array of size n find elements which appear more than n/k times
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

// time complexity - O(n), space complexity - O(n)
void elements_with_freq_k(vi arr, int n, int k)
{
    mii freq;
    for (auto x : arr)
    {
        freq[x]++;
    }
    for (auto x : freq)
    {
        if (x.ss >= (n / k))
        {
            cout << x.ff << "\n";
        }
    }
}

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    elements_with_freq_k(arr, arr.size(), k);
    return 0;
}