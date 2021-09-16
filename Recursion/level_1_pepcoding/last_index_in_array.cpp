#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the last index at which x occurs in array a.
5. If x exists in array, print the last index where it is found otherwise print -1.
*/

int last_index_in_array(int arr[], int idx, int n, int element)
{
    if (idx == n)
        return -1;

    int last_index = last_index_in_array(arr, idx + 1, n, element);

    // did not find from idx + 1 to n
    if (last_index == -1)
    {
        // we see if element at idx is equal to element:
        if (arr[idx] == element)
            return idx;
        // if not we return -1
        else
            return -1;
    }
    // if last_index is not -1, that means we found element from idx + 1 to n
    else
        return last_index;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << last_index_in_array(arr, 0, n, 1) << "\n"; // expected output = 6
    cout << last_index_in_array(arr, 0, n, 5) << "\n"; // expected output = 7
    return 0;
}