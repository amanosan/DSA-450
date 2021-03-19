// checking whether string is a palindrome
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int l = 0, r = str.size() - 1;
    while (r > l)
    {
        if (str[l] == str[r])
        {
            l++;
            r--;
        }
        else if (str[l] != str[r])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string str;
    getline(cin, str);
    if (isPalindrome(str) == 1)
        cout << "True";
    else
        cout << "False";
    return 0;
}