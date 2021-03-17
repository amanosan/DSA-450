// Perform Union of two sorted arrays
// output should be number of elements in the union
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    unordered_map<int, int> map;

    // taking input of first array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        map[a[i]]++;
    }

    // taking input of second array
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        map[b[i]]++;
    }

    // number of elements in the union is the size of the map
    cout << map.size() << endl;
    return 0;
}