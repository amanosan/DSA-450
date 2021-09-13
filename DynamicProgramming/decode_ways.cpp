#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. You are required to calculate and print the count of encodings for the string str.

    For 123 -> there are 3 encodings. abc, aw, lc
    For 993 -> there is 1 encoding. iic 
    For 013 -> This is an invalid input. A string starting with 0 will not be passed.
    For 103 -> there is 1 encoding. jc
    For 303 -> there are 0 encodings. But such a string maybe passed. In this case 
    print 0.
*/

void decode_ways(string str)
{
    int n = str.length();
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
        dp[i] = 0;

    // number of ways to decode a single character is 1
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        // when both previous and current char is 0, we cannot encode them
        if (str[i - 1] == '0' and str[i] == '0')
        {
            dp[i] = 0;
        }
        // when previous is 0 but current is not zero we see get two options:
        // 03 --> we cannot decode 03
        // 0_3 --> but we can decode previous string and attach 3 to it.
        else if (str[i - 1] == '0' and str[i] != '0')
        {
            dp[i] = dp[i - 1];
        }
        // when previous is non zero and current is 0
        // but the number formed should not be greater than 26
        else if (str[i - 1] != '0' and str[i] == '0')
        {
            if (str[i - 1] == '1' or str[i - 1 == '2'])
            {
                // since loop is running from i = 1
                // subtracting 2 from 1 will lead to array out of bounds
                // so to count number of ways, we will just have 1
                // example:
                // 20 -> when i is at 0, we won't be able to call for 20 as a whole
                // so to decode 20 we will just have 1 way.
                dp[i] = (i >= 2) ? dp[i - 2] : 1;
            }
            // since we cannot decode 30, 40.... etc.
            else
                dp[i] = 0;
        }
        else
        {
            // we can take ith or i-1th and ith char together
            // but we need to make sure the number is less equal to 26
            if (stoi(str.substr(i - 1, 2)) <= 26)
            {
                dp[i] = dp[i - 1] + ((i >= 2) ? dp[i - 2] : 1);
            }
            // else if the number is greater we cannot call for i-1 and i
            else
                dp[i] = dp[i - 1];
        }
    }
    cout << dp[n - 1] << "\n";
}

int main()
{
    string str = "21123";
    // output should be 8
    decode_ways(str);
    return 0;
}