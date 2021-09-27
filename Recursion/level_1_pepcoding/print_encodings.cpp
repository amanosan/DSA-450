#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Calculate and print all encodings of str.
*/

void print_encodings(string str, string ans)
{
    // if we have no string
    if (str.length() == 0)
        cout << ans;
    // if we have just a single character
    else if (str.length() == 1)
    {
        char ch = str[0];
        if (ch == '0')
            return;
        else
        {
            int chv = ch - '0';
            char code = char('a' + chv - 1);
            cout << ans + code << "\n";
        }
    }
    // if length of string is greater or equal to 2
    else
    {
        // taking just the first char
        char ch = str[0];
        string remaining = str.substr(1);

        if (ch == '0')
            return;
        else
        {
            int chv = ch - '0';
            char code = char('a' + chv - 1);
            print_encodings(remaining, ans + code);
        }

        // taking the first two chars
        string first_two = str.substr(0, 2);
        string remaining_12 = str.substr(2);

        int first_two_value = stoi(first_two);
        // since we do not have encoding for int greater than 26
        if (first_two_value <= 26)
        {
            char code = char('a' + first_two_value - 1);
            print_encodings(remaining_12, ans + code);
        }
    }
}

int main()
{
    string str = "655196";
    string ans = "";
    print_encodings(str, ans);
    return 0;
}