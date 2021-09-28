#include <bits/stdc++.h>
using namespace std;

/*
1. You are given an infix expression.
2. You are required to evaluate and print it's value.
NOTES:
- Follow BODMAS
- Single digit operands
- Opening and Closing brackets can be there in the expression.
*/

// function to return the precedence of the operators
int precedence(char opt)
{
    if (opt == '+' or opt == '-')
        return 1;
    else
        return 2;
}
// function to actually perform operation and return the result.
int operation(int v1, int v2, char opt)
{
    if (opt == '+')
        return v1 + v2;
    else if (opt == '-')
        return v1 - v2;
    else if (opt == '*')
        return v1 * v2;
    else
        return v1 / v2;
}

void infix_evaluation(string str)
{
    int n = str.length();
    stack<char> operators;
    stack<int> operands;

    // loop traversing through each char of the expression
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        // when ch is space we continue with the loop
        if (ch == ' ')
            continue;

        // when ch is a number:
        if (isdigit(ch))
            operands.push(ch - '0'); // converting char to integer

        // when ch is an opening bracket
        if (ch == '(')
            operators.push(ch);
        // closing bracket
        if (ch == ')')
        {
            while (operators.top() != '(')
            {
                char opt = operators.top();
                operators.pop();
                int v2 = operands.top();
                operands.pop();
                int v1 = operands.top();
                operands.pop();
                // performing operation
                int result = operation(v1, v2, opt);
                operands.push(result);
            }
            // popping the opening bracket
            operators.pop();
        }

        // else it can be an operator
        if (ch == '+' or ch == '-' or ch == '/' or ch == '*')
        {
            // ch wants higher or equal priority operators to be solved first.
            while (operators.size() > 0 and operators.top() != '(' and precedence(ch) <= precedence(operators.top()))
            {
                char opt = operators.top();
                operators.pop();
                int v2 = operands.top();
                operands.pop();
                int v1 = operands.top();
                operands.pop();
                // performing operation
                int result = operation(v1, v2, opt);
                operands.push(result);
            }
            operators.push(ch);
        }
    }

    // there can be a situation where the operators stack still has some operators:
    while (operators.size() != 0)
    {
        char opt = operators.top();
        operators.pop();
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();
        // performing operation
        int result = operation(v1, v2, opt);
        operands.push(result);
    }

    // the answer will be stored in the final value of operands stack
    cout << operands.top() << "\n";
}

int main()
{
    string str1 = "2 + 6 * 4 / 8 - 3";   // output should be 2
    string str2 = "2 + (5 - 3 * 6 / 2)"; // output should be -2
    infix_evaluation(str1);
    infix_evaluation(str2);
    return 0;
}