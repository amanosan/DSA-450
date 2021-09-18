#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), 
or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. get the list of all paths that can be used to move from top-left to bottom-right.
*/

// sr - source row, sc - source column, dr - destination row, dc - destination column
vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{
    // base case
    if (sr == dr and sc == dc)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }

    // since we can take as many steps as possible:
    vector<string> paths;

    // horizontal paths: (s = move size)
    for (int s = 1; s <= dc - sc; s++)
    {
        vector<string> hpaths = get_maze_paths(sr, sc + s, dr, dc);
        for (auto path : hpaths)
            paths.push_back("h" + to_string(s) + path);
    }

    // vertical paths:
    for (int s = 1; s <= dr - sr; s++)
    {
        vector<string> vpaths = get_maze_paths(sr + s, sc, dr, dc);
        for (auto path : vpaths)
            paths.push_back("v" + to_string(s) + path);
    }

    // diagonal paths:
    for (int s = 1; s <= dr - sr and s <= dc - sc; s++)
    {
        vector<string> dpaths = get_maze_paths(sr + s, sc + s, dr, dc);
        for (auto path : dpaths)
            paths.push_back("d" + to_string(s) + path);
    }

    return paths;
}

int main()
{
    int n = 3;
    int m = 3;
    auto results = get_maze_paths(1, 1, n, m);
    for (auto x : results)
        cout << x << " ";
    cout << "\n";
    return 0;
}