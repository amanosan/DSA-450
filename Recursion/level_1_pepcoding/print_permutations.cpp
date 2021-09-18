#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str.
2. Calculate and print all permutations of str.
*/

void print_permutations(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << ", ";
        return;
    }
    // we will select each char of the string to be the first char of the answer
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        // from 0 to i-1 and from i + 1 till end will give string minus str[i]
        string left_part = str.substr(0, i);
        string right_part = str.substr(i + 1);
        string remaining_str = left_part + right_part;
        print_permutations(remaining_str, ans + ch);
    }
}

int main()
{
    string ans = "";
    string str = "abc";
    print_permutations(str, ans);
    return 0;
}