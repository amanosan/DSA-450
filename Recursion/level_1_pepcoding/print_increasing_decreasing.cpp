#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a positive number n. 
2. You are required to print the counting from n to 1 and back to n again.
3. You are required to not use any loops. Complete the body of pdi function to 
achieve it. Don't change the signature of the function.
*/

void print_inc_dec(int n)
{
    if (n == 0)
        return;
    cout << n << "\n";
    print_inc_dec(n - 1);
    cout << n << "\n";
}

int main()
{
    int n = 3;
    print_inc_dec(n);
    return 0;
}