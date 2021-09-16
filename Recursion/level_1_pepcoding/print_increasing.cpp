#include <bits/stdc++.h>
using namespace std;

void print_increasing(int n)
{
    // base case
    if (n == 0)
        return;
    print_increasing(n - 1);
    cout << n << " ";
}

int main()
{
    int n = 10;
    print_increasing(n);
    return 0;
}