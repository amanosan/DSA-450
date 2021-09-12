#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
1. You are given a number n, which represents the length of a road. The road has n plots on 
it's each side.
2. The road is to be so planned that there should not be consecutive buildings on either 
side of the road.
3. You are required to find and print the number of ways in which the buildings can be built on both side 
of roads.

Similar to count_binary_strings.cpp
*/

void arrange_buildings(int n)
{
    int space = 1;
    int building = 1;

    for (int i = 2; i <= n; i++)
    {
        int new_space = building + space;
        int new_building = space;

        space = new_space;
        building = new_building;
    }

    // now for one side we will have (building + space) ways to arrange
    // and the other side also we will have (building + space) ways to arrange
    int result = building + space;
    result *= result;
    cout << result << "\n";
}

int32_t main()
{
    int n;
    cin >> n;
    arrange_buildings(n);
    return 0;
}
