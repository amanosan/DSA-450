#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n.
2. You are required to calculate the factorial of the number. 
Don't change the signature of factorial function.
*/
int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << factorial(n);
    return 0;
}