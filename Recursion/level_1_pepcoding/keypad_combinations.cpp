#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str. The string str will contains numbers only, 
where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map :
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
3. Get the list of all words that could be produced by the keys in str.
*/

static string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> get_keypad_combinations(string str)
{
    // base case
    if (str.length() == 0)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }

    // taking first char of the string
    char ch = str[0];
    string remaining = str.substr(1);

    vector<string> rec_res = get_keypad_combinations(remaining);
    vector<string> final_result;
    // getting the code string for the character
    // to convert char to integer, we subtract '0' from it
    string code_for_ch = codes[ch - 48]; // ASCII code of '0' = 48
    for (int i = 0; i < code_for_ch.length(); i++)
    {
        char chcode = code_for_ch[i];
        for (auto s : rec_res)
            final_result.push_back(chcode + s);
    }

    return final_result;
}

int main()
{
    string str = "78";
    // getline(cin, str);
    // cin >> str;
    vector<string> result = get_keypad_combinations(str);
    for (string x : result)
        cout << x << "\n";
    // expected output = [tv, tw, tx, uv, uw, ux]
    return 0;
}