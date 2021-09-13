#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string str.
2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
For abbc -> there are 3 subsequences. abc, abc, abbc
For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.
*/

void count_subsequence(string str)
{
    int a = 0;   // to store subsequene of a+
    int ab = 0;  // to store subsequences of a+b+
    int abc = 0; // to store subsequences of a+b+c+

    for (int i = 0; i < str.length(); i++)
    {
        // checking the char at i
        char c = str[i];

        if (c == 'a')
            // we have two options:
            // either a is taken into subsequence
            // ot is not taken into subseuence, that's why (2 * a)
            // and a can be put after the subsequence of a+ to get a+
            a = (2 * a) + 1;
        else if (c == 'b')
            // we have two options:
            // either b is taken into subsequence
            // or is not taken into subsequence, that's why (2 * ab)
            // and b can be put after all the subsequence of a+ to get a+b+
            ab = (2 * ab) + a;
        else
            // we have two options:
            // either c is taken into subsequence
            // or is not taken into subsequence, that's why (2 * abc)
            // and c can be put after all the subsequence of a+b+ to get a+b+c+
            abc = (2 * abc) + ab;
    }

    // so the total a+b+c+ subsequences are:
    cout << abc << "\n";
}

int main()
{
    string str = "abcabc";
    count_subsequence(str);
    return 0;
}