#include <bits/stdc++.h>
using namespace std;

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

bool valid_shuffle(string x, string y, string z)
{
    if (x.length() + y.length() != z.length())
        return false;

    int i = 0, j = 0, k = 0;
    while (k < z.length())
    {
        // checking if char of x matches char of z
        if (i < x.length() and z[k] == x[i])
            i++;

        // checking if char of y matches char of z
        else if (j < y.length() and z[k] == y[j])
            j++;

        /// if no char of x and y match z, then
        else
            return false;
        k++;
    }

    // now if i and j are less than z.size and y.size() we return false:
    if (i < x.size() or j < y.size())
        return false;

    return true;
}

int32_t main()
{
    string str1 = "xy", str2 = "12", result = "x1y2";
    auto res = valid_shuffle(str1, str2, result);
    if (res)
        cout << "valid shuffle\n";
    else
        cout << "invalid shuffle\n";
    return 0;
}
