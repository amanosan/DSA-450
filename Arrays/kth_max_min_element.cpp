// To find kth maximum and minimum element in array

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<int> maxHeap;                            // max heap
        priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
        int n, k;                                               // n - number of elements, k - kth element
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (auto x : arr)
        {
            minHeap.push(x);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        for (auto x : arr)
        {
            maxHeap.push(x);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        cout << "Kth max - " << minHeap.top() << endl;
        cout << "Kth min - " << maxHeap.top() << endl;
    }
    return 0;
}
