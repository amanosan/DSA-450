#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to "next greater element on the right" for all elements of array.
*/

vector<int> next_greater(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    // for the last element, there is no greater element
    result[n - 1] = -1;
    st.push(arr[n - 1]);

    // now traversing from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        // if there are smaller elements than arr[i] in the stack, we will pop them
        while (st.size() > 0 and arr[i] >= st.top())
        {
            st.pop();
        }

        // if the stack becomes empty then all elements to the right
        // were smaller than the current element, so result becomes -1
        if (st.size() == 0)
            result[i] = -1;
        // else after removing smaller elements, the top element becomes the result
        else
            result[i] = st.top();
        // pushing the current element in the stack
        st.push(arr[i]);
    }

    return result;
}

// alternate approach (traversing from left to right)
vector<int> method_2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n);
    stack<int> st; // we will insert the index in the stack instead of the element itself

    st.push(0); // inserting the first index

    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 and arr[i] >= arr[st.top()])
        {
            int position = st.top(); // getting the top
            // the result for that position will be the element
            result[position] = arr[i];
            st.pop();
        }

        st.push(i); // inserting the index of the current index
    }

    // for those elements which are still in the stack
    // which means no element to their right is greater than them
    while (st.size() > 0)
    {
        int position = st.top();
        result[position] = -1;
        st.pop();
    }
    return result;
}

int main()
{
    vector<int> arr = {2, 5, 9, 3, 1, 12, 6, 8, 7};
    auto result = next_greater(arr);
    // output should be -> 5, 9, 12, 12, 12, -1, 8, -1, -1
    for (auto x : result)
        cout << x << " ";
    cout << endl;
    auto result2 = method_2(arr);
    for (auto x : result2)
        cout << x << " ";
    return 0;
}