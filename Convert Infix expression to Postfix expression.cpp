#include <bits/stdc++.h>
using namespace std;
/*
Write a program to convert an Infix expression to Postfix form.

Infix expression: The expression of the form “a operator b” (a + b), when an operator is in-between every pair of operands.
Postfix expression: The expression of the form “a b operator” (ab+)
When every pair of operands is followed by an operator.

Examples:

Input: A + B * C + D
Output: ABC*+D+

Input: ((A + B) – C * (D / E)) + F
Output: AB+CDE/*-F+
*/

// Function to return precedence of operators
int precedence(char Char) {
    if(Char == '^')
        return 3;
    else if(Char == '/' || Char == '*')
        return 2;
    else if(Char == '+' || Char == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if(c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// The function to convert infix expression to postfix expression
void infixToPostfix(string s) {
    stack<char> str;
    string result; // postfix

    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        // if the scanned char is an operand, add it to the output string
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
            result += c;
        // if the scanned char is an '(' push it to the stack
        else if ( c == '(' )
            str.push('(');
        // if the scanned char is an ')', pop and add to the output string from the stack until an '(' is encountered
        else if ( c == ')' ) {
            while(str.top() != '(') {
                result += str.top();
                str.pop();
            }
            str.pop(); // pop '('
        }
        // if an operator is scanned
        else {
            while(!str.empty() && precedence(s[i]) < precedence(str.top()) ||
                !str.empty() && precedence(s[i]) == precedence(str.top()) &&
                associativity(s[i]) == 'L' ) {
                    result += str.top();
                    str.pop();
            }
            str.push(c);
        }
    }

    // pop all the remaining elements from the stack
    while(!str.empty()) {
        result += str.top();
        str.pop();
    }
    cout << result << endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);


    return 0;
}
/*
To convert infix expression to postfix expression, use the stack data structure.
Scan the infix expression from left to right.
Whenever we get an operand, add it to the postfix expression and
if we get an operator or parenthesis add it to the stack by maintaining their precedence.
*/
