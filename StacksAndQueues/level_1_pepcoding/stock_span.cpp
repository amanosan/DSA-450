#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the prices of a share on n days.
3. You are required to find the stock span for n days.
4. Stock span is defined as the number of days passed between the current day 
and the first day before today when price was higher than today.
*/

vector<int> stock_span(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    // we will find the next greatest element on the left
    st.push(0);
    result[0] = 1; // since span of first element is 1.

    for (int i = 1; i < n; i++)
    {
        // popping all elements less than current day
        while (st.size() > 0 and arr[i] > arr[st.top()])
        {
            st.pop();
        }

        // if stack is empty, we could'nt find a greater element
        if (st.size() == 0)
            result[i] = i + 1;
        else
            result[i] = i - st.top();

        // pushing the current index
        st.push(i);
    }

    return result;
}

int32_t main()
{
    vector<int> arr = {2, 5, 9, 3, 1, 12, 6, 8, 7};
    auto result = stock_span(arr);
    // output should be -> 1 2 3 1 1 6 1 2 1
    for (auto x : result)
        cout << x << " ";
    return 0;
}