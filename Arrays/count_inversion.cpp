#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n^2)
int count_inversion(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

// time complexity: O(nlogn)
int merge_arrays(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[i + low];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = low, count = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            count += mid - low + 1 - i; // remember this, most important logic
        }
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    return count;
}

int merge_sort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        count = merge_sort(arr, low, mid);
        count += merge_sort(arr, mid + 1, high);
        count += merge_arrays(arr, low, mid, high);
    }
    return count;
}

int count_inversion_merge(vector<int> arr)
{
    return merge_sort(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << count_inversion(arr) << endl;
    cout << count_inversion_merge(arr) << endl;
    return 0;
}