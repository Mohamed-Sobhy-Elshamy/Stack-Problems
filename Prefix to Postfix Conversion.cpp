#include <bits/stdc++.h>
using namespace std;
/*
Given a Prefix expression, convert it into a Postfix expression.
Conversion of Prefix expression directly to Postfix without going through
the process of converting them first to Infix and then to Postfix is much better in terms of
computation and better understanding the expression (Computers evaluate using Postfix expression).

let’s discuss about Prefix and Postfix notation:

Examples:

Input :  Prefix :  *+AB-CD
Output : Postfix : AB+CD-*
Explanation : Prefix to Infix :  (A+B) * (C-D)
                         Infix to Postfix :  AB+CD-*

Input :  Prefix :  *-A/BC-/AKL
Output : Postfix : ABC/-AK/L-*
Explanation : Prefix to Infix :  (A-(B/C))*((A/K)-L)
                         Infix to Postfix : ABC/-AK/L-*
*/
// function to check if char is operator or not
bool isOperator(char oper) {
    switch(oper) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

// convert prefix to postfix expression
string pre_to_post(string pre_exp) {
    stack<string> s;

    // length of expression
    int length = pre_exp.size();
    // reading from right to left
    for(int i = length - 1; i >= 0; i--) {
        // check if symbol is operator
        if(isOperator(pre_exp[i])) {
            // pop 2 operands from stack
            string operand_1 = s.top();
            s.pop();
            string operand_2 = s.top();
            s.pop();
            // concat the operands and operator
            string result = operand_1 + operand_2 + pre_exp[i];
            // push string result back to stack
            s.push(result);
        } // if symbol is an operand
        else {
            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }
    // stack contains only the prefix expression
    return s.top();
}

int main() {
    string pre_expression= "*-A/BC-/AKL";
    cout << "Postfix : " << pre_to_post(pre_expression);

    return 0;
}
/*
Algorithm for Prefix to Postfix:
- Read the Prefix expression in reverse order (from right to left)
- If the symbol is an operand, then push it onto the Stack
- If the symbol is an operator, then pop two operands from the Stack
    Create a string by concatenating the two operands and the operator after them.
    string = operand1 + operand2 + operator
    And push the resultant string back to Stack
- Repeat the above steps until end of Prefix expression.
*/
