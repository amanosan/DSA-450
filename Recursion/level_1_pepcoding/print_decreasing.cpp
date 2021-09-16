#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a positive number n. 
2. You are required to print the counting from n to 1.
3. You are required to not use any loops. Complete the body of print Decreasing function to achieve it.
*/

void print_decreasing(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    print_decreasing(n - 1);
}

int main()
{
    int n = 10;
    print_decreasing(n);
    return 0;
}