#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are required to find the maximum of input. 
*/

int max_element(int arr[], int idx, int n)
{
    if (idx == n)
        return -1;
    return max(arr[idx], max_element(arr, idx + 1, n));
}

int main()
{
    int arr[] = {5, 6, 1, 3, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max_element(arr, 0, n) << "\n";
    return 0;
}