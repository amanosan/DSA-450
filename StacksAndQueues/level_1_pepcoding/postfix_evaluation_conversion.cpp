#include <bits/stdc++.h>
using namespace std;

/*
1. You are given a postfix expression.
2. You are required to evaluate it and print it's value.
3. You are required to convert it to infix and print it.
4. You are required to convert it to prefix and print it.
*/

int calculate(int val1, int val2, char op)
{
    if (op == '+')
        return val1 + val2;
    else if (op == '-')
        return val1 - val2;
    else if (op == '*')
        return val1 * val2;
    else
        return val1 / val2;
}

void solve(string str)
{
    stack<char> opts;
    stack<string> infix;  // to keep note of the infix expression
    stack<string> prefix; // to keep note of the postfix expression
    stack<int> value;     // to keep note of the evaluation

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // if the char is a digit, we push it into all the stacks
        if (isdigit(ch))
        {
            value.push(ch - '0');
            string operand;
            operand += ch;
            infix.push(operand);
            prefix.push(operand);
        }
        else if (ch == '+' or ch == '-' or ch == '*' or ch == '/')
        {
            // calculating the value of the expression
            int val2 = value.top();
            value.pop();
            int val1 = value.top();
            value.pop();
            int result = calculate(val1, val2, ch);
            value.push(result);

            // calculating the postfix and infix expression
            string infix_val2 = infix.top();
            infix.pop();
            string infix_val1 = infix.top();
            infix.pop();
            string infix_result = "(" + infix_val1 + ch + infix_val2 + ")";
            infix.push(infix_result); // pushing the result;

            string prefix_val2 = prefix.top();
            prefix.pop();
            string prefix_val1 = prefix.top();
            prefix.pop();
            string prefix_result = ch + prefix_val1 + prefix_val2;
            prefix.push(prefix_result);
        }
    }

    // printing the results:
    cout << "EVALUATION : " << value.top() << "\n";
    cout << "INFIX : " << infix.top() << "\n";
    cout << "PREFIX : " << prefix.top() << "\n";
}

int main()
{
    string postfix = "264*8/+3-";
    solve(postfix);
    return 0;
}