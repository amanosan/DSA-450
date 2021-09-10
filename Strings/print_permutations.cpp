#include <bits/stdc++.h>
using namespace std;

// using STL function next_permutation
void print_permutations(string s)
{
    sort(s.begin(), s.end());
    cout << s << " ";
    while (next_permutation(s.begin(), s.end()))
    {
        cout << s << " ";
    }
    cout << "\n";
}

// iterative method
void print_perm_iter(string s)
{
    int n = s.length();
    vector<string> perm;
    string first(1, s[0]);
    perm.push_back(first);
    // from char at first index till last
    for (int i = 1; i < n; i++)
    {
        vector<string> temp;
        // iterating the already existing permuations
        for (int j = 0; j < perm.size(); j++)
        {
            auto y = perm[j];
            int len = y.length();
            // iterating from the -th index to the last to insert char at that index
            // to get the permutations.
            for (int k = 0; k <= len; k++)
            {
                // inserting at index k
                y.insert(y.begin() + k, s[i]);
                // storing to the temp ans
                temp.push_back(y);
                y = perm[j];
            }
        }
        // getting the final answers in the perm vector
        perm = temp;
    }

    // printing the permutations
    for (auto x : perm)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    string s = "abc";
    print_permutations(s);
    print_perm_iter(s);
    return 0;
}
