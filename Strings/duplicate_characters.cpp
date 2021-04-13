// Find duplicate characters in string
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// time complexity: O(n), space comlexity: O(NO_OF_CHARS)
void duplicateChars(string str)
{
    vector<int> freq(NO_OF_CHARS);
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++;
    }

    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > 1)
            cout << char(i) << ": " << freq[i] << endl;
    }
}
// the above method will make array of 256 spaces regardless of any number of characters.

// time complecity - O(nlogn), space complexity - O(size of map)
void duplicate_char_map(string str)
{
    map<char, int> freq;
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++;
    }
    for (auto f : freq)
    {
        if (f.second > 1)
            cout << f.first << ": " << f.second << endl;
    }
}
// this method is better in terms of space

int main()
{
    string str = "aaaabbbccd";
    duplicate_char_map(str);
    duplicateChars(str);
    return 0;
}