#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the elements of array a.
3. You are given a number k, representing the size of window.
4. You are required to find and print the maximum element in every window of size k.
*/

void max_window(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    // finding the next greatest element index on the right
    vector<int> nge(n);
    st.push(n - 1);
    nge[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 and arr[i] >= arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
            nge[i] = n;
        else
            nge[i] = st.top();

        st.push(i);
    }

    // finding the max element in the window size
    int j = 0;
    for (int i = 0; i <= n - k; i++)
    {
        // j represents the index of max element in the window
        // i represents the starting point of the windows
        if (j < i)
            j = i;
        // checking if the next greatest element is inside the window:
        // nge[j] --> gives the index of the next greatest element
        // i + k --> gives the boundary of the window
        while (nge[j] < i + k)
        {
            j = nge[j];
        }
        cout << arr[j] << " ";
    }
}

int main()
{
    int window = 4;
    vector<int> arr = {2, 9, 3, 8, 1, 7, 12, 6, 14, 4, 32, 0, 7, 19, 8, 12, 6};
    max_window(arr, window);
    // output should be -> 9 9 8 12 12 14 14 32 32 32 32 19 19 19
    return 0;
}