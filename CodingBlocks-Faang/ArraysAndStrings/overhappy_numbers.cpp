/*
A number is an overhappy number if the digits of the number are replaced
by the sum of the squares of the digits and this process is repeated until we get
the sum as 1.
The number which loops endlessly and does not sum up to 1 is not an overhappy number.
Example - 19 is an overhappy number.
Example - 02 is not an overhappy number.

Important Note: If the unordered map is loaded on the RAM then to lookup an element takes
                constant time.

NOTE:
We will never reach from a number till infinite.
eg. 99 -> 81 + 81 = 162 -> 1 + 36 + 4 = 41, so the sum of square of 162 will not be greater than 162
There will never be a case where we get x -> ...... -> infinite.
*/

#include <bits/stdc++.h>
using namespace std;

// function to return the number as sum of square of digits
int update_number(int n)
{
    int number = 0;
    while (n > 0)
    {
        int digit = n % 10;
        number += digit * digit; // squaring the digit
        n /= 10;
    }
    return number;
}

// function to check if number if overhappy or not
bool check(map<int, bool> m, int n)
{
    if (n == 1)
        return true;
    // if n is already present in the map, we return false
    // since we will enter into an endless loop.
    if (m.find(n) != m.end())
        return false;

    m.insert(make_pair(n, true));
    n = update_number(n);
    return check(m, n);
}

// function to call recursion funciton
bool is_overhappy(int n)
{
    map<int, bool> m;
    return check(m, n);
}

int main()
{
    int n;
    cin >> n;
    bool ans = is_overhappy(n);
    if (ans)
        cout << "Overhappy Number\n";
    else
        cout << "Not an Overhappy Number\n";
    return 0;
}