// given an array of 0,1,2s, sort without using any sorting algo
#include <bits/stdc++.h>
using namespace std;

// first method is to use count sort
vector<int> countSort(vector<int> arr)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else
            c2++;
    }
    vector<int> result;
    for (int i = 0; i < c0; i++)
        result.push_back(0);
    for (int i = 0; i < c1; i++)
        result.push_back(1);
    for (int i = 0; i < c2; i++)
        result.push_back(2);

    return result;
}

// using Dutch Flag Algorithm or 3-Way Partitioning
// low and mid pointer at starting position, high pointer at the last position
// [0 to low-1] ==> all 0s
// [high+1 to n] ==> all 2s
// [low to high] ==> all 1s
void dutchFlagAlgo(vector<int> &arr)
{
    int mid = 0, low = 0;
    int high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            continue;
        }
    }
}

// display function
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i];

    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting: " << endl;
    display(arr);
    dutchFlagAlgo(arr);
    cout << "After sorting: " << endl;
    display(arr);
    return 0;
}