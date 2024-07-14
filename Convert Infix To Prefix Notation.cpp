#include <bits/stdc++.h>
using namespace std;
/*
Given an infix expression, the task is to convert it to a prefix expression.
Infix Expression: The expression of type a ‘operator’ b (a+b, where + is an operator),
when the operator is between two operands.
Prefix Expression: The expression of type ‘operator’ a b (+ab where + is an operator),
when the operator is placed before the operands.

Examples:

Input: A * B + C / D
Output: + * A B/ C D

Input: (A – B/C) * (A/K-L)
Output: *-A/BC-/AKL
*/

// Function to check if the char is an operator
bool isOPerator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

// Function to get the priority of operators
int get_priority(char Ch) {
    if(Ch == '-' || Ch == '+')
        return 1;
    else if(Ch == '*' || Ch == '/')
        return 2;
    else if(Ch == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
string infix_to_postfix(string infix) {
    infix = '(' + infix + ')';
    int length = infix.size();
    stack<char> char_stack;
    string output;

    for(int i = 0; i < length; i++) {
        // if the scanned char is an operand, add it to output
        if(isalpha(infix[i]) || isdigit(infix[i])) {
            output += infix[i];
        }
        // if the scanned char is an '(' push it to the stack
        else if(infix[i] == '(') {
            char_stack.push('(');
        }
        // if the scanned char is an ')' , pop and output from stack until an '(' is encountered
        else if(infix[i] == ')') {
            while(char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            // remove '(' from the stack
            char_stack.pop();
        }
        // operator found
        else {
            if(isOPerator(char_stack.top())) {
                if(infix[i] == '^') {
                    while(get_priority(infix[i]) <= get_priority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else {
                    while(get_priority(infix[i]) < get_priority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                // push current operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    while(!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}

// Function to convert infix to prefix
string infix_to_prefix(string infix) {
    // reverse string and replace get postfix
    int len = infix.size();
    // reverse infix
    reverse(infix.begin(), infix.end());

    // replace
    for(int i=0; i<len; i++) {
        if(infix[i] == '(') {
            infix[i] = ')';
        } else if(infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string prefix = infix_to_postfix(infix);
    // reverse postfix
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string str = ("x+y*z/w+u");
    // calling function
    cout << infix_to_prefix(str) << endl;

    // output: ++x/*yzwu
    return 0;
}
/*
To convert an infix expression to a prefix expression, we can use the stack data structure. The idea is as follows:

Step 1: Reverse the infix expression. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
Step 2: Convert the reversed infix expression to “nearly” postfix expression.
    While converting to postfix expression, instead of using pop operation to
    pop operators with greater than or equal precedence,
    here we will only pop the operators from stack that have greater precedence.
Step 3: Reverse the postfix expression.
The stack is used to convert infix expression to postfix form.
*/
