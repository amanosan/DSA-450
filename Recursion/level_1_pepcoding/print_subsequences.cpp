#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str.
2. Calculate and print all subsequences of str.
*/

void print_subsequence(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << ", ";
        return;
    }
    char ch = str[0];
    string remaining = str.substr(1);

    // option 1 -> first char in the answer:
    print_subsequence(remaining, ans + ch);
    // option 2 -> first char not in the anser
    print_subsequence(remaining, ans + "");
}
int main()
{
    string str = "abc";
    string ans = "";
    print_subsequence(str, ans);
    return 0;
}