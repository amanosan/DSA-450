#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string exp representing an expression.
2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
3. But, some of the pair of brackets maybe extra/needless. 
4. You are required to print true if you detect extra brackets and false otherwise.
*/

void duplicate_brackets(string str)
{
    stack<char> st;
    for (auto ch : str)
    {
        if (ch == ')')
        {
            if (st.top() == '(')
            {
                cout << "true" << endl;
                return;
            }
            else
            {
                while (st.top() != '(')
                    st.pop();
                st.pop(); // to remove the opening bracket.
            }
        }
        else
        {
            st.push(ch);
        }
    }
    cout << "false" << endl;
    return;
}

int main()
{
    string str1 = "(a + b) + ((c + d))";
    // output should be true, since c+d has two brackets enclosing it, which is duplicate
    duplicate_brackets(str1);
    string str2 = "((a + b) + (c + d))";
    // output should be false
    duplicate_brackets(str2);
    return 0;
}