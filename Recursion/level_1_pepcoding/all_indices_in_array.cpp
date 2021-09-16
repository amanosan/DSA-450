#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the all indices at which x occurs in array a.
5. Return an array of appropriate size which contains all indices at which x occurs in array a.
*/

vector<int> all_indices(vector<int> &arr, int idx, int data, int count)
{
    if (idx == arr.size())
    {
        vector<int> arr(count);
        return arr;
    }

    // if we found the element, we increase both count and index
    if (arr[idx] == data)
    {
        vector<int> iarr = all_indices(arr, idx + 1, data, count + 1);
        // putting the index in the array at count position
        iarr[count] = idx;
        // returning the vector at last
        return iarr;
    }
    // if we did not find the element, we increase only the index
    else
    {
        vector<int> iarr = all_indices(arr, idx + 1, data, count);
        // since we did not get the element, we return the array as it is.
        return iarr;
    }
}

int main()
{
    vector<int> arr = {2, 3, 6, 9, 8, 3, 2, 3, 6, 4};
    vector<int> result = all_indices(arr, 0, 3, 0);
    for (auto x : result)
        cout << x << "\n";
    return 0;
}