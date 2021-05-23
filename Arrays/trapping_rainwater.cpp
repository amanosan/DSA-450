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

int trappedWater(vi arr)
{
    int n = arr.size();
    // total_water will store the final answer.
    // water will store the temporary answer.
    int total_water = 0, water = 0;
    int max_height = arr[0];

    // traversing the array
    for (int i = 1; i < n; i++)
    {
        // if the current height is greater than max_height
        if (arr[i] >= max_height)
        {
            total_water += water;
            water = 0;
            max_height = arr[i];
        }
        //if the current height is smaller than the max_height
        else
        {
            water += (max_height - arr[i]);
        }
    }
    // re initializing for traversing the array in reverse order.
    max_height = arr[n - 1];
    water = 0;
    for (int i = n - 1; i > 1; i--)
    {
        if (arr[i] > max_height)
        {
            total_water += water;
            water = 0;
            max_height = arr[i];
        }
        else
        {
            water += (max_height - arr[i]);
        }
    }

    return total_water;
}

int32_t main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << trappedWater(arr) << "\n";
    return 0;
}
