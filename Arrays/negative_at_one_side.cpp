// Move negative elements to one side of the array
#include <bits/stdc++.h>
using namespace std;

void moveNegative(vector<int> &arr)
{
    int p1 = 0, p2 = 0;
    while (p1 < arr.size())
    {
        if (arr[p1] < 0)
        {
            swap(arr[p1++], arr[p2++]);
        }
        else if (arr[p1] > 0)
            p1++;
    }
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    moveNegative(arr);
    display(arr);
    return 0;
}