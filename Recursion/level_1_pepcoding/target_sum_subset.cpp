#include <bits/stdc++.h>
using namespace std;

void target_sum_subset(vector<int> &arr, int index, int target, int sum, string set)
{
    // base condition
    if (index == arr.size())
    {
        if (sum == target)
        {
            cout << set << endl;
        }
        return;
    }
    // each element has two options:
    // 1. to get selected into the subset
    target_sum_subset(arr, index + 1, target, sum + arr[index], set + to_string(arr[index]) + ", ");

    // 2. not getting selected into the subset
    target_sum_subset(arr, index + 1, target, sum, set);
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 70;
    target_sum_subset(arr, 0, target, 0, "");
    return 0;
}