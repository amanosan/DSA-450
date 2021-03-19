// To find the contiguous subarray with the largest sum
#include <bits/stdc++.h>
using namespace std;

// using kadane's algorithm
int max_subarray_sum(vector<int> arr)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;

        else if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}

// handling the case when all numbers are negative
int max_sum_negative(vector<int> arr)
{
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << max_subarray_sum(arr) << endl;
    cout << max_sum_negative(arr) << endl;
    return 0;
}