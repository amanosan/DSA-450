// To minimize the maximum difference of heights given in array
#include <bits/stdc++.h>
using namespace std;

int getDiff(vector<int> arr, int k)
{
    int n = arr.size();
    // pair has first element as height and second is index
    vector<pair<int, int>> v;
    // keeping track of visited elements
    vector<int> visited(n);

    for (int i = 0; i < n; i++)
    {
        // checking if height - k is positive integer
        if (arr[i] - k >= 0)
            // now pushing the element along with index
            v.push_back({arr[i] - k, i});

        // adding elements after adding k
        v.push_back({arr[i] + k, i});
    }

    // sorting the elements height wise in increasing order
    sort(v.begin(), v.end());

    // element to keep count of number of elements out of n
    int elements = 0;
    // left and right for window
    int left = 0, right = 0;

    // finding the first window
    while (elements < n && right < v.size())
    {
        // checking if we have visited index or not
        if (visited[v[right].second] == 0)
        {
            elements++; // adding 1 to it
        }
        visited[v[right].second]++;
        right++;
    }

    // lets take answer of the first window
    int ans = v[right - 1].first - v[left].first;

    while (right < v.size())
    {
        if (visited[v[left].second] == 1)
        {
            elements--;
        }
        visited[v[left].second]--;
        left++;

        while (elements < n && right < v.size())
        {
            if (visited[v[right].second] == 0)
            {
                elements++;
            }
            visited[v[right].second]++;
            right++;
        }

        if (elements == n)
        {
            ans = min(ans, v[right - 1].first - v[left].first);
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = getDiff(arr, k);
    cout << result << endl;
    return 0;
}