// Find factorial of large number

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define int long long
#define ff first
#define ss second
#define vi vector<int>
#define mii map<int, int>
#define pii pair<int, int>
#define psi pair<string, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007 // 1e9 + 7
#define ps(x, y) fixed << setprecision(y) << x

int multiply(int x, vi &result, int size);

void factorial(int n)
{
    vi result(MAX);

    // initializing the result
    result[0] = 1;
    int size = 1;

    for (int i = 2; i <= n; i++)
    {
        size = multiply(i, result, size);
    }

    // printing the result
    for (int i = size - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << "\n";
}

int multiply(int x, vi &result, int size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int prod = result[i] * x + carry;
        // storing the last digit of product in the result
        result[i] = prod % 10;
        // put the rest of it in carry
        carry = prod / 10;
    }

    while (carry)
    {
        // putting last digit carry in the result
        result[size] = carry % 10;
        // checking if we still have carry left
        carry = carry / 10;
        size++;
    }
    return size;
}

int32_t main()
{
    int n;
    cin >> n;
    factorial(n);
    return 0;
}
