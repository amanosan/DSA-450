#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, the size of a chess board.
2. You are given a row and a column, as a starting point for a knight piece.
3. You are required to generate the all moves of a knight starting in (row, col) 
such that knight visits  all cells of the board exactly once.
4. Calculate and  print all configurations of the chess board representing the route
of knight through the chess board.
*/

void print_board(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void knights_tour(vector<vector<int>> &arr, int row, int col, int move_number)
{
    // checking for edge cases.
    if (row < 0 or col < 0 or row >= arr.size() or col >= arr.size())
        return;

    // checking if the square of the board is already filled.
    if (arr[row][col] > 0)
        return;

    // base case
    if (move_number == arr.size() * arr.size())
    {
        // making the last move
        arr[row][col] = move_number;
        // printing the board
        print_board(arr);
        // removing while backtracking
        arr[row][col] = 0;
        return;
    }

    arr[row][col] = move_number;
    // exploring all the options that the knight has to move
    // since knight moves to steps in one direction and then one step in the other.
    knights_tour(arr, row - 2, col + 1, move_number + 1);
    knights_tour(arr, row - 1, col + 2, move_number + 1);
    knights_tour(arr, row + 1, col + 2, move_number + 1);
    knights_tour(arr, row + 2, col + 1, move_number + 1);
    knights_tour(arr, row + 2, col - 1, move_number + 1);
    knights_tour(arr, row + 1, col - 2, move_number + 1);
    knights_tour(arr, row - 1, col - 2, move_number + 1);
    knights_tour(arr, row - 2, col - 1, move_number + 1);
    // removing while backtracking, since we want option to remain for other calls.
    arr[row][col] = 0;
}

int main()
{
    int n = 5;
    int row = 2;
    int col = 0;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = vector<int>(n, 0);
    knights_tour(arr, row, col, 1);
    return 0;
}