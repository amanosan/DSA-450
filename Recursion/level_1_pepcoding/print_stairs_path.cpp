#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 
2 steps or 3 steps in one move.
3. Print the list of all paths that can be used to climb the staircase up.
*/

void print_stairs_path(int n, string ans)
{
    // n cannot be negative, we cannot be on a negative step
    if (n < 0)
    {
        return;
    }
    // if we have reached the 0th step, we print the answer
    if (n == 0)
    {
        cout << ans << ", ";
        return;
    }
    print_stairs_path(n - 1, "1" + ans); // if we take one step
    print_stairs_path(n - 2, "2" + ans); // if we take two steps
    print_stairs_path(n - 3, "3" + ans); // if we take three steps
}

int main()
{
    int n = 4;
    string ans = "";
    print_stairs_path(n, ans);
    return 0;
}