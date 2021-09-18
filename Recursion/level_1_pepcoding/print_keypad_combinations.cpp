#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str. The string str will contains numbers only, 
where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map
    0 -> .;
    1 -> abc
    2 -> def
    3 -> ghi
    4 -> jkl
    5 -> mno
    6 -> pqrs
    7 -> tu
    8 -> vwx
    9 -> yz
3. Print the list of all words that could be produced by the keys in str.
*/

static string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
void print_keypad(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << "\n";
        return;
    }
    char ch = str[0];
    string remaining = str.substr(1);

    string code_for_ch = codes[ch - 48];
    for (char c : code_for_ch)
    {
        // adding all chars of the keypad to the answer
        print_keypad(remaining, ans + c);
    }
}

int main()
{
    string str = "78";
    string ans = "";
    print_keypad(str, ans);
    return 0;
}