#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Get the list of all paths that can be used to move from top-left to bottom-right.
*/

// sr - source row, sc - source column, dr - destination row, dc - destination column
vector<string> maze_path(int sr, int sc, int dr, int dc)
{
    // base case
    if (sr == dr and sc == dc)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }

    vector<string> horizontal_paths;
    vector<string> vertical_paths;

    // if we are at the last column we cannot call horizontal path
    if (sc < dc)
        horizontal_paths = maze_path(sr, sc + 1, dr, dc);
    // if we are at the last row we cannot call vertical path
    if (sr < dr)
        vertical_paths = maze_path(sr + 1, sc, dr, dc);

    vector<string> final_paths;
    // adding h to the horizontal paths:
    for (auto x : horizontal_paths)
        final_paths.push_back("h" + x);
    // adding v to the vertical paths:
    for (auto x : vertical_paths)
        final_paths.push_back("v" + x);

    return final_paths;
}

int main()
{
    int n = 3;
    int m = 3;
    // going from (1, 1) to (n, m)
    auto results = maze_path(1, 1, n, m);
    for (auto x : results)
        cout << x << " ";
    cout << "\n";
    return 0;
}