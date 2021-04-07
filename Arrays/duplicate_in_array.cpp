// To find duplicate in an array of size n+1

#include <bits/stdc++.h>
using namespace std;

int duplicate(vector<int> arr)
{
    int n = arr.size();
    vector<int> freq(n);
    // memset(&freq, 0, freq.size());
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > 1)
            return i;
    }
    return -1;
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