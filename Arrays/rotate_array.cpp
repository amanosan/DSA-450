// Program to Rotate Array of size n by d digits.

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v, int l, int h)
{
    for (int i = l, j = h; i < j; i++, j--)
    {
        swap(v[i], v[j]);
    }
}

void rotate(vector<int> &v, int size, int d)
{
    reverse(v, 0, d - 1);
    reverse(v, d, size - 1);
    reverse(v, 0, size - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        rotate(v, n, d);
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}