// Minimum number of swaps to bring all elements less than equal to k together.
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

int min_no_swaps(vi arr, int k)
{
    int good = 0, bad = 0;

    // finding values less than equal to k in array:
    for (auto x : arr)
    {
        if (x <= k)
            good++;
    }

    // finding values greater than k in window of size good values:
    for (int i = 0; i < good; i++)
    {
        if (arr[i] > k)
            bad++;
    }

    // our window size will be equal to the number of good values:
    int i = 0, j = good, ans = bad;
    while (j < arr.size())
    {
        // if starting value in the current window is greater than k:
        if (arr[i] > k)
            bad--;

        // if end value in the current window is greater than k:
        if (arr[j] > k)
            bad++;

        ans = min(ans, bad);
        // increasing the size of the window.
        i++;
        j++;
    }
    return ans;
}

int32_t main()
{
    vi arr = {1, 2, 5, 6, 3};
    int k = 3;
    cout << min_no_swaps(arr, k) << "\n";
    return 0;
}
