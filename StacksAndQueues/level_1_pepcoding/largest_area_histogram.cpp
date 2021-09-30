#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the height of bars in a bar chart.
3. You are required to find and print the area of largest rectangle in the histogram.
*/

void largest_area(vector<int> &arr)
{
    int n = arr.size();
    // each element can form a rectangle from:
    // its next smallest element on its right and left both.
    vector<int> rb(n); // next smaller element on the right (index)
    vector<int> lb(n); // next smaller element on the left (index)

    // height will be the height of the current element
    // width will be the index of (right - left - 1) smallest element.
    // then we can find the area

    // finding next smallest on the right
    stack<int> st;
    st.push(n - 1);
    rb[n - 1] = n; // putting default value as n (length of array)
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 and arr[i] < arr[st.top()])
        {
            st.pop(); // removing greater elements till we find smaller element
        }
        if (st.size() == 0)
            rb[i] = n;
        else
            rb[i] = st.top();

        st.push(i);
    }

    // finding next smallest element on the left
    stack<int> st_1;
    st_1.push(0);
    lb[0] = -1; // putting default value as -1;
    for (int i = 1; i < n; i++)
    {
        while (st_1.size() > 0 and arr[i] < arr[st_1.top()])
        {
            st_1.pop(); // removing greater elements till we find smaller element
        }
        if (st_1.size() == 0)
            lb[i] = -1;
        else
            lb[i] = st_1.top();

        st_1.push(i);
    }

    // finding the max area
    int max_area = 0;
    for (int i = 0; i < n; i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = arr[i] * width;
        max_area = max(max_area, area);
    }
    cout << max_area << "\n";
}

int main()
{
    vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
    // output should be 12
    largest_area(arr);
    return 0;
}