#include <bits/stdc++.h>
using namespace std;
/*
Given a Prefix expression, convert it into a Infix expression.
Computers usually does the computation in either prefix or postfix (usually postfix).
But for humans, its easier to understand an Infix expression rather than a prefix.
Hence conversion is need for human understanding.

Examples:

Input :  Prefix :  *+AB-CD
Output : Infix : ((A+B)*(C-D))

Input :  Prefix :  *-A/BC-/AKL
Output : Infix : ((A-(B/C))*((A/K)-L))
*/
bool isOperator(char oper) {
    switch(oper) {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '%':
        return true;
    }
    return false;
}

// convert prefix to infix expression
string prefix_to_infix(string pre_exp) {
    stack<string> s;
    // length of expression
    int length = pre_exp.size();
    // reading from right to left
    for(int i = length - 1; i >= 0; i--) {
        // check if symbol is operator
        if(isOperator(pre_exp[i])) {
            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            // concat the operands and operator
            string temp = "(" + op1 + pre_exp[i] + op2 + ")";
            // push string temp back to stack
            s.push(temp);
        } else { // if symbol is an operand
            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }
    // stack now contains the infix expression
    return s.top();
}


int main()
{
    string prefix_expression =  "*-A/BC-/AKL";
    cout << "Infix: " << prefix_to_infix(prefix_expression) << endl;

    // Time Complexity: O(n)
    // Auxiliary Space: O(n)

    return 0;
}
/*
Algorithm for Prefix to Infix:

- Read the Prefix expression in reverse order (from right to left)
- If the symbol is an operand, then push it onto the Stack
- If the symbol is an operator, then pop two operands from the Stack
    Create a string by concatenating the two operands and the operator between them.
    string = (operand1 + operator + operand2)
    And push the resultant string back to Stack
- Repeat the above steps until the end of Prefix expression.
- At the end stack will have only 1 string i.e resultant string
*/
