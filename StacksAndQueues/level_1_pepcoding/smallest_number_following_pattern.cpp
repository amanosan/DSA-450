#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
2. 'd' stands for decreasing and 'i' stands for increasing
3. You have to print the smallest number, using the digits 1 to 9 only without repetition, 
such that the digit decreases following a d and increases following an i
*/

// we will use the principle of LIFO of stacks
void smallest_number_following(string str)
{
    // the string will break at all i's
    int n = str.length();
    int sn = 1; // starting number
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        // if the char is 'd', we push the number and increase it as well.
        if (ch == 'd')
        {
            st.push(sn);
            sn++;
        }
        // if the char is 'i', we push the number and increase it
        // as well as print all the numbers in the stack - in LIFO fashion
        if (ch == 'i')
        {
            st.push(sn);
            sn++;
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    // if stack still has elements, we will print them as well
    // also we need to push the last element in the stack as well
    st.push(sn);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << "\n";
}

int main()
{
    string str1 = "diddidi";  // output - 21543768
    string str2 = "ddddiiii"; // output - 543216789
    smallest_number_following(str1);
    smallest_number_following(str2);
    return 0;
}