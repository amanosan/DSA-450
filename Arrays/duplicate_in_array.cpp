// To find duplicate in an array of size n+1

#include <bits/stdc++.h>
using namespace std;

int duplicate(vector<int> arr)
{
    int n = arr.size();
    int sum = n * (n + 1) / 2;
    int sum_of_array = 0;
    for (int i = 0; i < n; i++)
        sum_of_array += arr[i];
    return (n - (sum - sum_of_array));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << duplicate(arr) << endl;
    }
    return 0;
}