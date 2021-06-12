// A Program to check if strings are rotations of each other or not

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

bool is_rotation(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;
    // concatinating string 1 to check if string 2 is a substring or not.
    string temp = str1 + str1;
    if (temp.find(str2) != string::npos)
        return true;
    else
        return false;
}

int32_t main()
{
    string a = "abcd";
    string b = "cdab";
    string c = "acdb";

    cout << is_rotation(a, b) << "\n";
    cout << is_rotation(a, c) << "\n";
    return 0;
}
