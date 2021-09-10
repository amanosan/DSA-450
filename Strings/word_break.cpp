#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// word break
int number_of_sentences(unordered_set<string> dictionary, string sentence)
{
    // array to keep count of sentences formed till index
    vector<int> dp(sentence.length(), 0);
    // traversing through the sentence
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // checking if word makes a sentence
            // checking from index j till the index i
            string word_to_check = sentence.substr(j, i - j + 1);
            // if word is found
            if (dictionary.find(word_to_check) != dictionary.end())
            {
                if (j > 0)
                    // adding previous amount of sentences that have already been made
                    dp[i] += dp[j - 1];
                else
                    // if j is at 0 and we got a word/sentence from j till i, we add 1
                    dp[i] += 1;
            }
        }
    }
    return dp[sentence.length() - 1];
}

int main()
{
    string sentence = "pepcodinglovesmangoicecream";
    unordered_set<string> dictionary;
    dictionary.insert("pep");
    dictionary.insert("loves");
    dictionary.insert("coding");
    dictionary.insert("ice");
    dictionary.insert("cream");
    dictionary.insert("icecream");
    dictionary.insert("pepcoding");
    dictionary.insert("mango");
    dictionary.insert("man");
    dictionary.insert("go");
    cout << number_of_sentences(dictionary, sentence);
    return 0;
}