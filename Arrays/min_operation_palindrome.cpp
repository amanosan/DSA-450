// Minimum number of operations to make the array into a palindrome
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

// two pointer approach
int min_operations(vi arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    int operations = 0;
    while (i <= j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] < arr[j])
        {
            i++;
            arr[i] += arr[i - 1];
            operations++;
        }
        else
        {
            j--;
            arr[j] += arr[j + 1];
            operations++;
        }
    }
    return operations;
}

int32_t main()
{
    vi arr = {1, 2, 3, 5, 10, 1};
    cout << min_operations(arr) << "\n";
    return 0;
}
