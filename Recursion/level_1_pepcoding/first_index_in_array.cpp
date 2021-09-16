#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the first index at which x occurs in array a.
5. If x exists in array, print the first index where it is found otherwise print -1.
*/

int first_index_in_array(int arr[], int idx, int n, int element)
{
    if (idx == n)
        return -1;
    if (arr[idx] == element)
        return idx;
    return first_index_in_array(arr, idx + 1, n, element);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << first_index_in_array(arr, 0, n, 7) << "\n"; // expected output = -1
    cout << first_index_in_array(arr, 0, n, 4) << "\n"; // expected output = 3
    return 0;
}