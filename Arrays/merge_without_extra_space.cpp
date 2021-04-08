// To merge two arrays of size m and n without using extra space

#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2 + gap % 2); // ceil value of gap divided by 2
}

// First way - comparing -> swapping -> sorting arr2 --> Time Complexity - O(nmlog(mn))
// Second way - take last element of arr1, insert first element of arr2 at correct position in arr1
// similar to insertion sort, and last element of arr1 insert to arr2. ---> Time Complexity - O(nm)

// Time complexity - O((n+m) * log(m + n))
void mergeArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    int gap = n + m;
    int i = 0, j = 0;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {

        // if both pointers are inside arr1
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[gap + i])
                swap(arr1[i], arr1[i + gap]);
        }

        // if one pointer is in arr1 and other in arr2
        for (j = (gap > n) ? (gap - n) : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }

        // if both pointers are inside arr2 and j is less than m
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    }
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int j = 0; j < m; j++)
        cin >> arr2[j];

    mergeArrays(arr1, arr2);
    display(arr1);
    display(arr2);
    return 0;
}