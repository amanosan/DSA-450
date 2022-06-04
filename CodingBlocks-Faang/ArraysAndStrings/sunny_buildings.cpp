/*
Given an array representing heights of buildings.
The array has buildings from left to right as shown in below diagram,
count number of buildings facing the sunset.
It is assumed that heights of all buildings are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0, max_height = INT_MIN;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // we do not need to use an array
        // since we have to go one by one from left only once
        int num;
        cin >> num;

        // if the height of the current building is greater than
        // max_height, we increase the count and change the max_height
        if (num >= max_height)
        {
            count++;
            max_height = num;
        }
    }
    cout << count << "\n";

    // input -
    // 7
    // 5 2 5 6 4 3 7
    return 0;
}