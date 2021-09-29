#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a number n, representing the number of people in a party.
2. You are given n strings of n length containing 0's and 1's
3. If there is a '1' in ith row, jth spot, then person i knows about person j.
4. A celebrity is defined as somebody who knows no other person than himself but 
everybody else knows him.
5. If there is a celebrity print it's index otherwise print "none".
*/

void celebrity_problem(vector<vector<int>> &arr)
{
    // we will use process of elimination
    int n = arr.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() >= 2)
    {
        int person1 = st.top();
        st.pop();
        int person2 = st.top();
        st.pop();

        // checking the conditions:
        // checking if person1 knows person2, then person1 cannot be a celebrity
        if (arr[person1][person2] == 1)
            st.push(person2);
        // if person1 does not know person2, then person2 cannot be a celebrity
        else
            st.push(person1);
    }

    // after the above loop we will just have one person in the stack
    // we will check its row and column to make sure if that person is a celebrity
    int person = st.top();
    st.pop();

    // checking the rows and column,
    // columns values should be 1 --> since every person should know person
    // rows values should be 0 --> since person should not know anyone
    for (int i = 0; i < n; i++)
    {
        if (i == person)
            continue;
        if (arr[i][person] == 0 or arr[person][i] == 1)
        {
            cout << "none" << endl;
            return;
        }
    }

    // finally if we did not return from any of the above checks
    // the answer is person
    cout << person << "\n";
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 1},
                               {0, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 1, 0}};
    // output should be 0
    celebrity_problem(arr);
    return 0;
}