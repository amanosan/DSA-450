// Find the longest consecutive subsequence in the array:

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

// first approach is to sort the array, iterate and keep checking
// time complexity - O(nlogn)
int longest_subsequence_sort(vi arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int result = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
            count++;
        else
        {
            count = 1;
        }
        result = max(result, count);
    }
    return result;
}

// we will use set to store the elements (fetching will be O(1))
// time complexity - O(n), space complexity - O(n)
int longest_subsequence_optimized(vi arr)
{
    set<int> s;
    int n = arr.size();
    int ans = INT_MIN;
    // inserting all the elements in the set
    for (auto x : arr)
        s.insert(x);

    for (int i = 0; i < n; i++)
    {
        // if we dont find "arr[i] - 1" in the set
        if (s.find(arr[i] - 1) == s.end())
        {
            int j = arr[i] + 1;
            // till we find arr[j]
            while (s.find(j) != s.end())
                j++;
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longest_subsequence_sort(arr) << "\n";
    cout << longest_subsequence_optimized(arr) << "\n";
    return 0;
}