#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of time-intervals.
2. In the next n lines, you are given a pair of space separated numbers.
3. The pair of numbers represent the start time and end time of a meeting 
(first number is start time and second number is end time)
4. You are required to merge the meetings and print the merged meetings output 
in increasing order of start time.
*/

// function to sort 2D vector by a certain column, in this case 0th column
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0]; // sorting by 0th column.
}

void merge_intervals(vector<vector<int>> &arr)
{
    // sorting the time intervals by start time (0th element in each row)
    sort(arr.begin(), arr.end(), sortcol);
    stack<vector<int>> st;

    st.push(arr[0]); // pushing the first time interval
    for (int i = 1; i < arr.size(); i++)
    {
        auto stack_time = st.top();
        int cst = arr[i][0];
        int cet = arr[i][1];
        vector<int> temp(2);
        // checking the starting time and end time
        if (cst <= stack_time[1])
        {
            temp[0] = min(stack_time[0], cst);
            temp[1] = max(stack_time[1], cet);
            st.pop();
            st.push(temp);
        }
        else
            st.push(arr[i]);
    }

    stack<vector<int>> result;
    while (st.size() > 0)
    {
        auto v = st.top();
        st.pop();
        result.push(v);
    }
    while (!result.empty())
    {
        auto v = result.top();
        result.pop();
        for (auto x : v)
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> arr = {{22, 28},
                               {1, 8},
                               {25, 27},
                               {14, 19},
                               {27, 30},
                               {5, 12}};
    merge_intervals(arr);
    // 1 12
    // 14 19
    // 22 30
    return 0;
}