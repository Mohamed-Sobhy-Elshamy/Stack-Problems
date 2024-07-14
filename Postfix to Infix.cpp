#include <bits/stdc++.h>
using namespace std;
/*
Postfix notation, also known as reverse Polish notation,
is a syntax for mathematical expressions in which the mathematical operator is always placed after the operands.
Though postfix expressions are easily and efficiently evaluated by computers,
they can be difficult for humans to read.
Complex expressions using standard parenthesized infix notation are often more
readable than the corresponding postfix expressions. Consequently,
we would sometimes like to allow end users to work with infix notation and then convert it to postfix notation for computer processing.
Sometimes, moreover, expressions are stored or generated in postfix, and we would like to convert them to infix for the purpose of reading and editing

Examples:

Input  : abc++
Output : (a + (b + c))

Input  : ab*c+
Output : ((a*b)+c)
*/

bool isOperand(char operand) {
    return ( operand >= 'a' && operand <= 'z' ) ||
            ( operand >= 'A' && operand <= 'Z' );
}

// get infix for a given postfix expression
string get_infix(string expression) {
    stack<string> s;

    for(int i = 0; expression[i] != '\0'; i++) {
        // push operands
        if(isOperand(expression[i])) {
            string op(1, expression[i]);
            s.push(op);
        }
        // we assume that input is a valid postfix and expect an operator
        else {
            string op_1 = s.top();
            s.pop();
            string op_2 = s.top();
            s.pop();
            s.push( "(" + op_2 + expression[i] + op_1 + ")" );
        }
    }
    // there must be a single element in stack now which is the required infix
    return s.top();
}


int main() {
    string expre = "ab*c+";
    cout << get_infix(expre) << endl;


    return 0;
}
