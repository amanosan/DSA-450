#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the elements of array from end to beginning each in a separate line.
4. For the above purpose complete the body of displayArrReverse function.
*/

void reverse_display(int arr[], int idx, int n)
{
    if (idx == n)
        return;
    reverse_display(arr, idx + 1, n);
    cout << arr[idx] << " ";
}

int main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse_display(arr, 0, n);
    return 0;
}