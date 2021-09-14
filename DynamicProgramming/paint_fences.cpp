#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number k in separate lines, representing the number 
of fences and number of colors.
2. You are required to calculate and print the number of ways in which the fences 
could be painted so that not more than two consecutive  fences have same colors.
*/

void paint_fences(int n, int k)
{
    // when two adjacent fences are same we have k ways of coloring them
    // eg k = 3 (r,g,b)
    // we will have --> (rr, gg, bb)
    int same = k;
    // when two adjacent fences are different we have k * (k - 1) ways
    // for fence 1 we will have k ways of coloring
    // for fence 2 we will have k-1 colors remaining.
    int diff = k * (k - 1);
    // total ways will be same + diff.
    int total = same + diff;

    // if we have 0 we cannot color it
    if (n == 0)
    {
        cout << 0 << "\n";
        return;
    }
    // if we have 1 fence we can color it in k ways
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    // this is the smallest problem:
    // when we have 2 fences:
    // we can either paint them the same
    // or we can paint them with different colors
    if (n == 2)
    {
        cout << same + diff << "\n";
        return;
    }

    for (int i = 3; i <= n; i++)
    {
        // the new same will be the previous different
        // just add the last color of the previous fence to it
        int new_same = diff;

        // the new diff will be the previous total + k - 1 colors
        // the last of the previous had 1 color
        // so for this fence we have k - 1 colors remaining
        int new_diff = total * (k - 1);
        int new_total = new_same + new_diff;

        same = new_same;
        diff = new_diff;
        total = new_total;
    }
    // the total number of ways:
    cout << total << "\n";
    return;
}

int main()
{
    int n = 8;
    int k = 3;
    // output should be 3672
    paint_fences(n, k);
    return 0;
}