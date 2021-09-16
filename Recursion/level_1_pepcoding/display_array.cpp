#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the elements of array from beginning to end each 
in a separate line.
4. For the above purpose complete the body of displayArr function.
*/

void display_array(int arr[], int idx, int n)
{
    if (idx == n)
        return;
    cout << arr[idx] << " ";
    display_array(arr, idx + 1, n);
}

int main()
{
    int arr[] = {10, 15, 14, 6, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    display_array(arr, 0, n);
    return 0;
}
