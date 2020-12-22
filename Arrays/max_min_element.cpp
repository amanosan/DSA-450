// To find the Maximum and Minimum element in an Array

#include <bits/stdc++.h>
using namespace std;

// function to return max element of array
int maxElement(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// function to return min element of array
int minElement(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxElement(arr, n) << " " << minElement(arr, n) << endl;
    }
    return 0;
}