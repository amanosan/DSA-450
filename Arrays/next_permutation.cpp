// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int index = n - 2;
    // finding peak element
    while (index >= 0 && arr[index] >= arr[index + 1])
        index--;

    if (index >= 0)
    {
        int j = n - 1;
        while (j >= 0 && arr[j] <= arr[index])
            j--;
        swap(arr[index], arr[j]);
    }
    reverse(arr.begin() + index + 1, arr.end());

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}