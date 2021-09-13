#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers, representing n elements.
3. You are required to find the maximum sum of a subsequence with no adjacent elements.
*/

void max_sum_non_adj(vector<int> &arr)
{
    int n = arr.size();
    // for each element we will have two options:
    // 1. select the element only if it is not adjacent
    // 2. not select the element.

    int include = arr[0];
    int exclude = 0;

    for (int i = 1; i < n; i++)
    {
        // if we are including the current item,
        // we can't add it to the previous included item as we dont want adjacent
        // so inclusion can only happen on previous excluded element
        int new_include = arr[i] + exclude;

        // when we are excluding the item
        // then we can select the max of both the previous included and excluded
        // here we have choice to select previous inclusion or exclusion and
        // we select the max of both as we need maximum sum.
        int new_exclude = max(include, exclude);

        include = new_include;
        exclude = new_exclude;
    }
    int result = max(include, exclude);
    cout << result << "\n";
}

int main()
{
    vector<int> arr = {5, 10, 10, 100, 5, 6};
    max_sum_non_adj(arr);
    return 0;
}