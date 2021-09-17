#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str.
2. Calculate all subsequences of str.
*/

vector<string> get_subsequence(string str)
{
    // if string is empty
    if (str.length() == 0)
    {
        vector<string> base_result;
        // since an empty string has a subsequence which is null or in this case "".
        base_result.push_back("");
        return base_result;
    }
    // example string = abc
    char ch = str[0];                                         // a
    string remaining = str.substr(1);                         // bc
    vector<string> recur_result = get_subsequence(remaining); // [--, b-, -c, bc]

    vector<string> final_result;
    for (string s : recur_result)
    {
        // adding a blank to the result of substring
        final_result.push_back("" + s); // [---, -b-, --c, -bc]
        // adding char to the result of the substring
        final_result.push_back(ch + s); // [a--, ab-, a-c, abc]
    }
    // final result contains all the subsequences.
    return final_result;
}

int main()
{
    string str = "abc";
    auto result = get_subsequence(str);
    for (auto x : result)
        cout << x << ", ";
    return 0;
}