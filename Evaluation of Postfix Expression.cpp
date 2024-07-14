#include <bits/stdc++.h>
using namespace std;
/*
Given a postfix expression, the task is to evaluate the postfix expression.

Postfix expression: The expression of the form “a b operator” (ab+),
when a pair of operands is followed by an operator.

Examples:

Input: str = “2 3 1 * + 9 -“
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
*/

// Function that returns value of a given postfix
int evaluate_postfix(string expr) {
    // create stack of capacity equal to expression size
    stack<int> stack_;
    // scan all chars one by one
    for(int i = 0; i < expr.size(); i++) {
        // scanned char is an operand (number), push it to stack
        if(isdigit(expr[i]))
            stack_.push(expr[i] - '0');

        // scanned char is an operator, pop 2 elements from stack and apply the operator
        else {
            int value_1 = stack_.top();
            stack_.pop();
            int value_2 = stack_.top();
            stack_.pop();
                switch(expr[i]) {
                case '+':
                    stack_.push(value_2 + value_1);
                    break;
                case '-':
                    stack_.push(value_2 - value_1);
                    break;
                case '*':
                    stack_.push(value_2 * value_1);
                    break;
                case '/':
                    stack_.push(value_2 / value_1);
                    break;
                }
        }
    }
    return stack_.top();
}


int main()
{
    string expression = "231*+9-";

    cout << "Postfix evaluation : " << evaluate_postfix(expression) << endl;

    // output : -4
    // time complexity: O(n)
    // space complexity: O(n)

    return 0;
}
/*
Follow the steps mentioned below to evaluate postfix expression using stack:

- Create a stack to store operands (or values).
- Scan the given expression from left to right and do the following for every scanned element.
    If the element is a number, push it into the stack.
    If the element is an operator, pop operands for the operator from the stack.
        Evaluate the operator and push the result back to the stack.
- When the expression is ended, the number in the stack is the final answer.
*/
