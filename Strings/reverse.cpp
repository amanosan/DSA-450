// Reverse a string
#include <bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
    return string(str.rbegin(), str.rend());
}

int main()
{
    string str;
    getline(cin, str);
    str = reverseString(str);
    cout << str << endl;
    return 0;
}