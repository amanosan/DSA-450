/*
Find Majority Element
Boyer-Moore Majority Vote ALgorithm
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> find_majority_element(vector<int> v)
{
    // finding elements occuring more than [N/3] times
    vector<int> majority_elements;
    int element1 = v[0];
    int count1 = 0;
    int element2 = 0;
    int count2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (element1 == v[i])
            count1++;
        else if (element2 == v[i])
            count2++;
        else if (count1 == 0)
        {
            element1 = v[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            element2 = v[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    // now we have 2 elements in element1 and element2;
    // iterate over array to check if both elements are majority or not
    int thresh = v.size() / 3;
    count1 = count2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element1)
            count1++;
        if (v[i] == element2)
            count2++;
    }
    if (count1 > thresh)
        majority_elements.push_back(element1);
    if (count2 > thresh)
        majority_elements.push_back(element2);
    return majority_elements;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    auto ans = find_majority_element(v);
    if (ans.size() == 0)
        cout << "No Majority Element";
    else
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    cout << "\n";
    return 0;
}