#include <bits/stdc++.h>
using namespace std;

/*
1. You are given an infix expression.
2. You are required to convert it to postfix and print it.
3. You are required to convert it to prefix and print it.
*/

// function to get precedence of operator
int precedence(char opt)
{
    if (opt == '+' or opt == '-')
        return 1;
    else if (opt == '*' or opt == '/')
        return 2;
    else
        return 0;
}

void to_postfix_prefix(string str)
{
    int n = str.length();
    stack<char> opts; // operators
    stack<string> post;
    stack<string> pre;

    // traversing through the chars:
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch == '(')
            opts.push(ch);
        else if (isalnum(ch))
        {
            string operand;
            operand += ch; // converting char to string
            // pushing char to the stack of postfix and pre fix
            post.push(operand);
            pre.push(operand);
        }
        else if (ch == ')')
        {
            while (opts.top() != '(')
            {
                char opt = opts.top();
                opts.pop();
                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();

                string post_res = postv1 + postv2 + opt; // a + b = ab+
                string pre_res = opt + prev1 + prev2;    // a + b = +ab
                post.push(post_res);
                pre.push(pre_res);
            }
            // remove the opening bracket
            opts.pop();
        }
        else if (ch == '+' or ch == '-' or ch == '*' or ch == '/')
        {
            while (opts.size() > 0 && opts.top() != '(' && precedence(ch) <= precedence(opts.top()))
            {
                char opt = opts.top();
                opts.pop();
                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();

                string post_res = postv1 + postv2 + opt; // a + b = ab+
                string pre_res = opt + prev1 + prev2;    // a + b = +ab
                post.push(post_res);
                pre.push(pre_res);
            }
            opts.push(ch); // pushing the operator to the stack
        }
    }

    // if operators stack has still some operators
    while (opts.size() > 0)
    {
        char opt = opts.top();
        opts.pop();

        string postv2 = post.top();
        post.pop();
        string postv1 = post.top();
        post.pop();

        string prev2 = pre.top();
        pre.pop();
        string prev1 = pre.top();
        pre.pop();

        string post_res = postv1 + postv2 + opt; // a + b = ab+
        string pre_res = opt + prev1 + prev2;    // a + b = +ab
        post.push(post_res);
        pre.push(pre_res);
    }

    // printing the result
    cout << "POSTFIX : " << post.top() << "\n";
    cout << "PREFIX  : " << pre.top() << "\n";
}

int main()
{
    string infix = "a*(b-c+d)/e";
    // output:
    // abc-d+*e/
    // /*a+-bcde
    to_postfix_prefix(infix);
    return 0;
}