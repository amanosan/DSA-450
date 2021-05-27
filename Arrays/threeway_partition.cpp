// parition the array around two values a and b.
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

// naive approach - sort the array - time complexity - O(nlogn)
void threeway_partition_1(vi &arr, int a, int b)
{
    // simply sort the array.
    sort(arr.begin(), arr.end());
}

// optimized approach - time complexity - o(n)
void threeway_partition_2(vi &arr, int a, int b)
{
    int n = arr.size();
    // values before pointer_a will be smaller than a
    // values before pointer_b will be larger than b
    int pointer_a = 0, pointer_b = n - 1;

    for (int i = 0; i <= pointer_b;)
    {
        if (arr[i] < a)
        {
            swap(arr[i], arr[pointer_a]);
            pointer_a++;
            i++;
        }
        else if (arr[i] > b)
        {
            swap(arr[i], arr[pointer_b]);
            pointer_b--;
        }
        else
        {
            i++;
        }
    }
}

// function to display the array
void display(vi arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int32_t main()
{
    int n, a, b;
    vi arr({1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32});
    a = 14, b = 20;
    threeway_partition_2(arr, a, b);
    display(arr);
    return 0;
}
