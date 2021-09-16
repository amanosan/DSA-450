#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n.
*/

int power(int x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main()
{
    int x = 2, n = 5;
    cout << power(x, n);
    return 0;
}