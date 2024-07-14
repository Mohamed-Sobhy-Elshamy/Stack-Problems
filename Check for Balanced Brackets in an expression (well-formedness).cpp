#include <bits/stdc++.h>
using namespace std;
/*
##Amazon | Oracle | Microsoft | Google | Adobe##
Given an expression string exp, write a program to examine whether the pairs and the orders of
“{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

Example:

Input: exp = “[()]{}{[()()]()}”
Output: Balanced
Explanation: all the brackets are well-formed

Input: exp = “[(])”
Output: Not Balanced
Explanation: 1 and 4 brackets are not balanced because
there is a closing ‘]’ before the closing ‘(‘
*/
bool areBracketsBalanced(string expr) {
    // Declare a stack to hold the previous brackets
    stack<char> temp;
    for(int i=0; i<expr.length(); i++) {
        // if stack is empty just push the current bracket
        if(temp.empty()) {
            temp.push(expr[i]);
        }
        else if( (temp.top() == '(' && expr[i] == ')')
              || (temp.top() == '{' && expr[i] == '}')
              || (temp.top() == '[' && expr[i] == ']')) {
            // if we found any complete pair of bracket the pop
            temp.pop();
        } else {
            temp.push(expr[i]);
        }
    }
    if(temp.empty()) {
        // if stack is empty return true
        return true;
    }
    return false;
}

int main()
{
    string expression = "{()}[]";
    if(areBracketsBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
/*
Follow the steps mentioned below to implement the idea:

- Declare a character stack (say temp).
- Now traverse the string exp.
    If the current character is a starting bracket ( ‘(‘ or ‘{‘  or ‘[‘ ) then push it to stack.
    If the current character is a closing bracket ( ‘)’ or ‘}’ or ‘]’ ) then pop from the stack
        and if the popped character is the matching starting bracket then fine.
    Else brackets are Not Balanced.
- After complete traversal, if some starting brackets are left in the stack then the expression is Not balanced, else Balanced.
*/
