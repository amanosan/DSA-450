#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), 
or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Print the list of all paths that can be used to move from top-left to bottom-right.
*/

void print_maze_path_jumps(int sc, int sr, int dc, int dr, string ans)
{
    if (sc == dc and sr == dr)
    {
        cout << ans << ", ";
        return;
    }

    // for horizontal
    for (int i = 1; i <= dc - sc; i++)
        print_maze_path_jumps(sc + i, sr, dc, dr, ans + "h" + to_string(i));

    // for vertical
    for (int i = 1; i <= dr - sr; i++)
        print_maze_path_jumps(sc, sr + i, dc, dr, ans + "v" + to_string(i));

    // for diagonal
    for (int i = 1; i <= dr - sr and i <= dc - sc; i++)
        print_maze_path_jumps(sc + i, sr + i, dc, dr, ans + "d" + to_string(i));
}
int main()
{
    string ans = "";
    int n = 3;
    int m = 3;
    print_maze_path_jumps(1, 1, n, m, ans);
    return 0;
}