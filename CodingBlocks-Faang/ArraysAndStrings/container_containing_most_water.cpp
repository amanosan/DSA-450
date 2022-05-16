/*
Find Container Containing Maximum Amount of Water.
Two Pointer Approach
*/

#include <bits/stdc++.h>
using namespace std;

int max_water_container(vector<int> v)
{
    int max_area = INT_MIN;
    int lp = 0, rp = v.size() - 1;

    while (lp < rp)
    {
        int area = min(v[lp], v[rp]) * (rp - lp);
        max_area = max(max_area, area);

        if (v[lp] < v[rp])
            lp++;
        else
            rp--;
    }
    return max_area;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << max_water_container(v) << "\n";
    return 0;
}