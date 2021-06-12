#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

string count_and_say(int n)
{
    if (n <= 0)
        return " ";

    // initially we will start with string = 1;
    string result = "1";

    // now looping n-1 times:
    while (n > 1)
    {
        string temp = "";
        for (int i = 0; i < result.length(); i++)
        {
            int count = 1;
            while (i + 1 < result.length() and result[i] == result[i + 1])
            {
                count++;
                i++;
            }
            temp = temp + to_string(count);
            temp = temp + result[i];
        }
        result = temp;
        n--;
    }
    return result;
}

int32_t main()
{
    int n = 6;
    cout << count_and_say(n) << "\n";
    return 0;
}
