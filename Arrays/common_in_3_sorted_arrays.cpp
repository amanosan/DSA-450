// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

#include <bits/stdc++.h>
using namespace std;

// using maps to keep a note of frequencies
// time complexity - O(n1 + n2 + n3), space complexity - O(n1 + n2 + n3)
void common_elements_frequency(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    vector<int> result;
    map<int, int> freq1, freq2, freq3;
    for (int i = 0; i < arr1.size(); i++)
        freq1[arr1[i]]++;
    for (int i = 0; i < arr2.size(); i++)
        freq2[arr2[i]]++;
    for (int i = 0; i < arr3.size(); i++)
        freq3[arr3[i]]++;

    for (int i = 0; i < arr1.size(); i++)
    {
        if (freq1[arr1[i]] && freq2[arr1[i]] && freq3[arr1[i]])
        {
            cout << arr1[i] << " ";
            freq1[arr1[i]] = 0;
        }
    }
    cout << "\n";
}

// optimized approach
void common_element_optim(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    vector<int> result;
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size())
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            result.push_back(arr1[i]);
            int temp = arr1[i];
            while (i < arr1.size() && arr1[i] == temp)
                i++;
            while (j < arr2.size() && arr2[j] == temp)
                j++;
            while (k < arr3.size() && arr3[k] == temp)
                k++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr3[k])
            j++;
        else
            k++;
    }

    // displaying the result
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << "\n";
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    vector<int> arr3(n3);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    for (int i = 0; i < n3; i++)
        cin >> arr3[i];

    common_elements_frequency(arr1, arr2, arr3);
    common_element_optim(arr1, arr2, arr3);
    return 0;
}