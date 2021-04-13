// Merge Intervals

#include <bits/stdc++.h>
using namespace std;

// time complexity - O(nlogn), space complexity - O(n)
void merge_method1(vector<pair<int, int>> &intervals)
{
    sort(intervals.begin(), intervals.end()); // sorts on the basis of first element of pair
    stack<pair<int, int>> s;

    // pushing the first time interval into the stack
    s.push({intervals[0].first, intervals[0].second});

    for (int i = 1; i < intervals.size(); i++)
    {
        int start1 = s.top().first;
        int end1 = s.top().second;
        int start2 = intervals[i].first;
        int end2 = intervals[i].second;

        if (start2 > end1)
        {
            s.push({start2, end2});
        }
        else
        {
            s.pop();
            end1 = max(end1, end2);
            s.push({start1, end1});
        }
    }
    while (!s.empty())
    {
        cout << s.top().first << " --- " << s.top().second << endl;
        s.pop();
    }
}

// time complexity - O(nlogn), space complexity - O(1)
void merge_method2(vector<pair<int, int>> &interval)
{
    int index = 0;
    for (int i = 1; i < interval.size(); i++)
    {
        if (interval[i].first <= interval[index].second)
        {
            interval[index].second = max(interval[index].second, interval[i].second);
        }
        else
        {
            index++;
            interval[index] = interval[i];
        }
    }
    // now the merged intervals are till the index position
    for (int i = 0; i <= index; i++)
    {
        cout << interval[i].first << " --- " << interval[i].second << endl;
    }
}

int main()
{
    vector<pair<int, int>> interval = {{2, 6}, {8, 10}, {1, 3}, {15, 18}};
    merge_method1(interval);
    cout << "******************" << endl;
    merge_method2(interval);
    return 0;
}