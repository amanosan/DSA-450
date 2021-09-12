#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.
*/

void count_binary_strings(int n)
{
    // we will take note of strings ending with 1 and 0:
    int old_count_zeros = 1, old_count_ones = 1;

    for (int i = 2; i <= n; i++)
    {
        // for strings of length i:
        // new string ending with 0 will be old strings ending with 1,
        // since we cannot have 2 consecutive 0s and thats why we wont add it to old string ending with
        // zeros
        int new_count_zeros = old_count_ones;
        // new string ending with 1 wil be both the old strings ending with 1 as well as 0
        // since we wont be having 2 consecutive zeros in this case.
        int new_count_ones = old_count_zeros + old_count_ones;

        old_count_zeros = new_count_zeros;
        old_count_ones = new_count_ones;
    }
    // the final result will be the strings ending with 0 and 1 both
    int result = old_count_ones + old_count_zeros;
    cout << result << "\n";
}

int main()
{
    // output should be 21
    count_binary_strings(6);
    return 0;
}