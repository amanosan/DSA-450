#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a string exp representing an expression.
2. You are required to check if the expression is balanced 
i.e. closing brackets and opening brackets match up well.
*/

void balanced_brackets(string str)
{
    stack<char> st;
    // traversing through the expression
    for (auto ch : str)
    {
        // inserting the opening brackets
        if (ch == '(' or ch == '{' or ch == '[')
            st.push(ch);

        // checking for the closing brackets
        else if (ch == ')' or ch == '}' or ch == ']')
        {
            // checking if there are any opening brackets in the stack
            if (st.empty())
            {
                cout << "false" << endl;
                return;
            }
            char bracket = st.top();
            if (ch == ')' and bracket == '(')
                st.pop();
            if (ch == '}' and bracket == '{')
                st.pop();
            if (ch == ']' and bracket == '[')
                st.pop();
        }
    }
    if (st.empty())
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main()
{
    string str1 = "[(a + b) + {(c + d) * (e / f)}]";
    string str2 = "[(a + b) + {(c + d) * (e / f)]}";
    string str3 = "[(a + b) + {(c + d) * (e / f)}";
    string str4 = "([(a + b) + {(c + d) * (e / f)}]";
    string str5 = "[(a + b)])";
    balanced_brackets(str1); // true
    balanced_brackets(str2); // false
    balanced_brackets(str3); // false
    balanced_brackets(str4); // false
    balanced_brackets(str5); // false
    return 0;
}