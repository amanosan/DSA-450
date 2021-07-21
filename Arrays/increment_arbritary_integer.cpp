/*
Example:
Input - A vector with {1, 2, 9}
Output - A vector with {1, 3, 0}
*/

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

// time complexity - O(n) - n is the number of digits in the number.
vi plus_one(vi num)
{
    // adding one to the least significant digit.
    num.back()++;

    for (int i = num.size() - 1; i > 0 && num[i] == 10; i--)
    {
        num[i] = 0;   // making it 0
        num[i - 1]++; // adding carry 1 to the next digit.
    }
    // if the most significant digit becomes 10, we split it into two individual digits:
    if (num[0] == 10)
    {
        num[0] = 0;
        num.insert(num.begin(), 1);
    }
    return num;
}

int32_t main()
{
    vi arr = {9, 9, 9};
    auto result = plus_one(arr);
    for (auto x : result)
    {
        cout << x;
    }
    cout << "\n";
    return 0;
}