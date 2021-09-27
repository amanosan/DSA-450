#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Print the list of all paths that can be used to move from top-left to bottom-right.
*/

void print_maze_path(int sc, int sr, int dc, int dr, string ans)
{
    if (sc == dc and sr == dr)
    {
        cout << ans << "\n";
        return;
    }

    // we can travel horizontal only if sc is less than dc
    if (sc < dc)
        print_maze_path(sc + 1, sr, dc, dr, ans + "h");
    // we can travel vertical only if sr is less than dr
    if (sr < dr)
        print_maze_path(sc, sr + 1, dc, dr, ans + "v");
}

int main()
{
    int n = 3;
    int m = 3;
    string ans = "";
    print_maze_path(1, 1, n, m, ans);
    return 0;
}