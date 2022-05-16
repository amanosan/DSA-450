/*
Unique Character String
*/
#include <bits/stdc++.h>
using namespace std;

int func(vector<string> v, int i, string s)
{
    // base case:
    if (i == v.size())
    {
        int freq[26] = {0};
        for (int k = 0; k < s.length(); k++)
        {
            if (freq[s[k] - 'a'] == 1)
                return 0;
            freq[s[k] - 'a']++;
        }
        return s.length();
    }
    // we can include the ith string
    int op1, op2;
    op1 = op2 = INT_MIN;
    if (s.length() + v[i].length() <= 26)
        op1 = func(v, i + 1, s + v[i]);
    // we can exclude it
    op2 = func(v, i + 1, s);
    return max(op1, op2);
}

int unique_string(vector<string> v)
{
    string s = "";
    return func(v, 0, s);
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }

    cout << unique_string(v) << "\n";
    return 0;
}
