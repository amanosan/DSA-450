#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, the size of a chess board.
2. You are required to place n number of queens in the n * n cells of board 
such that no queen can kill another.
Note - Queens kill at distance in all 8 directions
3. Calculate and print all safe configurations of n-queens.
*/

bool is_queen_safe(vector<vector<int>> &arr, int row, int col)
{
    // checking if any queen is placed in the vertical column
    for (int i = row - 1, j = col; i >= 0; i--)
    {
        if (arr[i][j] == 1)
            return false;
    }

    // checking if any queen is placed in the left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (arr[i][j] == 1)
            return false;
    }

    // checking if any queen is placed in the right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 and j < arr.size(); i--, j++)
    {
        if (arr[i][j] == 1)
            return false;
    }
    return true;
}

void print_queens(vector<vector<int>> &arr, string psf, int row)
{
    // we know that we have n queens so each row will have only one queen
    // since we have an n x n board
    if (row == arr.size())
    {
        cout << psf << endl;
        return;
    }

    // now traversing through the columns
    for (int col = 0; col < arr[0].size(); col++)
    {
        // checking if it is safe to put the queen at arr[row][col]
        if (is_queen_safe(arr, row, col))
        {
            // placing queen in arr[row][col] by putting value of 1
            arr[row][col] = 1;
            print_queens(arr, psf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            // removing queen from arr[row][col] by putting value of 0
            arr[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = vector<int>(n, 0);
    }

    // output should be
    // 0-1, 1-3, 2-0, 3-2,
    // 0-2, 1-0, 2-3, 3-1,
    print_queens(arr, "", 0);
    return 0;
}