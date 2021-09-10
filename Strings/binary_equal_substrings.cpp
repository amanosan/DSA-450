#include <bits/stdc++.h>
using namespace std;

/*
Given a binary string str of length N, the task is to find the maximum count of consecutive 
substrings str can be divided into such that all the substrings are balanced i.e. 
they have equal number of 0s and 1s. If it is not possible to split str satisfying the 
conditions then print -1.
Examples:
Input: str = "0111100010"
Output: 3 
*/

int substring_with_equal_1s_0s(string s)
{
    int one = 0, zero = 0;
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero++;
        else
            one++;

        if (one == zero)
            count++;
    }
    // if number of zeros and ones in the binary string are not same,
    // we wont be able to split them into substrings with equal 1s and 0s
    if (one != zero)
        return -1;
    return count;
}

int main()
{
    string s = "0111100010";
    // cin >> s;
    cout << substring_with_equal_1s_0s(s) << "\n";
    return 0;
}