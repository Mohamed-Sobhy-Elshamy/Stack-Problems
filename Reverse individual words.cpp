#include <bits/stdc++.h>
using namespace std;
/*
Given string str, we need to print the reverse of individual words.

Examples:

Input : Hello World

Output : olleH dlroW
*/
void reverse_words(string str) {
    stack<char> stack_;

    // Traverse given string and push all chars to stack until we see a space
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ' ')
            stack_.push(str[i]);
        // when we see a space, we print contents of stack
        else {
            while(stack_.empty() == false) {
                cout << stack_.top();
                stack_.pop();
            }
            cout << " ";
        }
    }
    // there may not be space after last word
    while(stack_.empty() == false) {
        cout << stack_.top();
        stack_.pop();
    }
}


int main()
{
    string str = "hello world";
    reverse_words(str);

    // output = ollew dlrow

    // Time complexity : O(n) -> n is the length of string
    // Space complexity : O(n) -> n is the length of string

    return 0;
}
/*
We use a stack to push all words before space. As soon as we encounter a space, we empty the stack.
*/
