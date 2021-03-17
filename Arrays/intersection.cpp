// Perform intersection of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    set<int> s1;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else if (arr1[i] == arr2[j])
        {
            s1.emplace(arr1[i]);
            i++;
            j++;
        }
    }

    set<int>::iterator itr;
    for (itr = s1.begin(); itr != s1.end(); itr++)
        cout << *itr << " ";
    cout << endl;
    return 0;
}
