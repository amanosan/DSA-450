// Rearrange array in alternating positive & negative items with O(1) extra space

#include <bits/stdc++.h>
using namespace std;

// time complexity - O(n), space complexity - O(1)
// in this approach the order is not maintained
void rearrange(vector<int> arr)
{
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        if (arr[i] < 0 && arr[j] >= 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[i] >= 0 && arr[j] < 0)
        {
            i++;
            j--;
        }
        else if (arr[i] >= 0)
            i++;
        else if (arr[j] < 0)
            j--;
    }
    if (i == 0 or i == arr.size())
    {
        for (int m = 0; m < arr.size(); m++)
            cout << arr[m] << " ";
        cout << "\n";
    }
    else
    {
        int k = 0;
        while (k < arr.size() and i < arr.size())
        {
            swap(arr[k], arr[i]);
            i++;
            k += 2;
        }
        for (int m = 0; m < arr.size(); m++)
        {
            cout << arr[m] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr);
    return 0;
}