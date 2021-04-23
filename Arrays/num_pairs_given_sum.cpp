// Give total number of pairs with given sum in array
#include <bits/stdc++.h>
using namespace std;

// naive approach - time complexity = O(n^2)
int count_pairs_naive(vector<int> arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
                count++;
        }
    }
    return count;
}

// optimized approach, using maps to store frequency, time complexity - o(n)
int count_pairs(vector<int> arr, int k)
{
    map<int, int> freq;
    int count = 0;
    for (auto x : arr)
        freq[x]++;

    // while looping we will consider each pair twice
    for (auto x : arr)
    {
        count += freq[k - x];

        // we do not consider pair with element at same index, ie, (arr[i], arr[i]) is not considered
        if (k - x == x)
            count--;
    }
    return count / 2;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << count_pairs_naive(arr, k) << endl;
    cout << count_pairs(arr, k) << endl;
    return 0;
}