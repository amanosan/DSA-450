#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a prefix expression.
2. You are required to evaluate it and print it's value.
3. You are required to convert it to infix and print it.
4. You are required to convert it to postfix and print it.
*/

int calculate(int v1, int v2, int op)
{
    if (op == '+')
        return v1 + v2;
    else if (op == '-')
        return v1 - v2;
    else if (op == '*')
        return v1 * v2;
    else
        return v1 / v2;
}

void solve(string str)
{
    stack<int> value;
    stack<string> postfix;
    stack<string> infix;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];

        if (isdigit(ch))
        {
            value.push(ch - '0');
            string operand;
            operand += ch;
            postfix.push(operand);
            infix.push(operand);
        }
        else if (ch == '+' or ch == '-' or ch == '*' or ch == '/')
        {
            // calculating the value of the expresion
            int v1 = value.top();
            value.pop();
            int v2 = value.top();
            value.pop();
            int result = calculate(v1, v2, ch);
            value.push(result);

            // getting infix
            string iv1 = infix.top();
            infix.pop();
            string iv2 = infix.top();
            infix.pop();
            string i_res = "(" + iv1 + ch + iv2 + ")";
            infix.push(i_res);

            // getting postfix
            string pv1 = postfix.top();
            postfix.pop();
            string pv2 = postfix.top();
            postfix.pop();
            string p_res = pv1 + pv2 + ch;
            postfix.push(p_res);
        }
    }
    // printing the result
    cout << "VALUE : " << value.top() << "\n";
    cout << "INFIX : " << infix.top() << "\n";
    cout << "POSTFIX : " << postfix.top() << "\n";
}

int main()
{
    string str = "-+2/*6483";
    solve(str);
    return 0;
}