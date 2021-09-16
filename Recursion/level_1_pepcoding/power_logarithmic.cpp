#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n.
*/

// time complexity - O(log(n))
int power_log(int x, int n)
{
    if (n == 0)
        return 1;

    // if n is even --> x^n = x^(n/2).x^(n/2)
    if (n % 2 == 0)
        return power_log(x, n / 2) * power_log(x, n / 2);

    // if n is odd --> x^n = x.x^(n/2).x^(n/2)
    return x * power_log(x, n / 2) * power_log(x, n / 2);
}

int main()
{
    cout << power_log(4, 3) << "\n";
    cout << power_log(5, 5) << "\n";
    return 0;
}