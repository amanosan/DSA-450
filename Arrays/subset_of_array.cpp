// find whether an array is a subset of another array

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

// time complexity - O(mlogn), space complexity - 1
bool isSubset_1(vi a, vi b)
{
    // sorting the array.
    int ans = false;
    sort(a.begin(), a.end());
    // searching for each element of b in a, using binary search.
    for (auto x : b)
    {
        if (binary_search(a.begin(), a.end(), x))
            ans = true;
        else
            ans = false;
    }
    return ans;
}

// another approach, with better time complexity but worse space complexity
// time complexity - O(m + n), space complexity - O(n)
bool isSubset_2(vi a, vi b)
{
    mii freq;
    for (auto x : a)
    {
        freq[x]++;
    }
    int ans = false;
    // now checking the in the array b
    for (auto x : b)
    {
        if (freq[x] > 0)
            ans = true;
        else
            ans = false;
    }
    return ans;
}

int32_t main()
{
    vi arr1({11, 1, 13, 21, 3, 7});
    vi arr2({11, 3, 7, 1});
    bool result_1 = isSubset_1(arr1, arr2);
    bool result_2 = isSubset_2(arr1, arr2);

    cout << result_1 << "\n";
    cout << result_2 << "\n";
    return 0;
}
