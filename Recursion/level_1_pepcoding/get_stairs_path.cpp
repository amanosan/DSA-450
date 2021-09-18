#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 
2 steps or 3 steps in one move.
3. Get the list of all paths that can be used to climb the staircase up.
*/

vector<string> stairs_path(int n)
{
    // base case
    if (n == 0)
    {
        // for n == 0, we have 1 way which is to do nothing.
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }
    if (n < 0)
    {
        // for negative n, we dont have any way to reach 0th step
        vector<string> base_result;
        return base_result;
    }

    // these calls will return paths from (n-i) to 0:
    vector<string> r1 = stairs_path(n - 1); // 1 step
    vector<string> r2 = stairs_path(n - 2); // 2 steps
    vector<string> r3 = stairs_path(n - 3); // 3 steps
    vector<string> final_result;
    // adding 1 to r1
    for (auto x : r1)
        final_result.push_back("1" + x);
    // adding 2 to r2
    for (auto x : r2)
        final_result.push_back("2" + x);
    // adding 3 to r3
    for (auto x : r3)
        final_result.push_back("3" + x);
    return final_result;
}

int main()
{
    int n = 4;
    auto result = stairs_path(n);
    for (auto s : result)
        cout << s << " ";
    return 0;
}