/*
Distribute Candies
Given 2N candies, distribute the candies equally among Brother and Sister.
Note - Sister cannot have repeated candies, ie., all candies distributed to the
sister should be unique.

We can use MAP or SET, time complexity - O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int distribute_candies(vector<int> &candies)
{
    int n = candies.size();
    int max_candies_possible = n / 2;
    unordered_map<int, bool> unique_candies;
    for (int i = 0; i < n; i++)
    {
        unique_candies[candies[i]] = true;
    }

    // now we have unique candies and max_possible_candies
    // we can return the min of both to get the number of candies
    // that the sister can get.
    // if the number of unique candies is greater than N/2 then we
    // can give N/2 candies otherwise we give unique candies
    return min(int(unique_candies.size()), max_candies_possible);
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> candies;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        candies.push_back(x);
    }
    cout << distribute_candies(candies) << "\n";
    return 0;
}