#include <bits/stdc++.h>
using namespace std;
/*
Write a program to reverse a stack using recursion, without using any loop.

Example:

Input: elements present in stack from top to bottom 1 2 3 4
Output: 4 3 2 1

Input: elements present in stack from top to bottom 1 2 3
Output: 3 2 1
*/

// Below is a recursive fun that inserts an element at the bottom
void insert_at_bottom(stack<int>& stack_, int element) {
    if(stack_.size() == 0)
        stack_.push(element);
    else {
        // all items are held in fun call stack until we reach end of the stack when stack
        // becomes empty, if part is executed end the item is inserted at bottom
        int x = stack_.top();
        stack_.pop();
        insert_at_bottom(stack_, element);
        // push all items held in fun call stack once the item is inserted at the bottom
        stack_.push(x);
    }
}

// function that reverse the given stack using insert_at_bottom
void reverse_(stack<int>& stack_) {
    if(!stack_.empty()) {
        // hold all items in fun call stack until we reach end of stack
        int x = stack_.top();
        stack_.pop();
        reverse_(stack_);
        // insert all items in fun stack one by one from the bottom. every item is inserted at bottom
        insert_at_bottom(stack_, x);
    }
    return;
}

int main()
{
    stack<int> st1, st2;
    // push elements into stack
    for(int i=1; i<=4; i++) {
        st1.push(i);
    }
    st2 = st1;

    cout << "Original stack" << endl;
    // printing stack after reversal
    while(!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    // fun to reverse
    reverse_(st1);
    cout << "Reversed stack" << endl;
    while(!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }


    return 0;
}
/*
Follow the steps mentioned below to implement the idea:

- Create a stack and push all the elements in it.
- Call reverse(), which will pop all the elements from the stack and pass the popped element to
    function insert_at_bottom()
- Whenever insert_at_bottom() is called it will insert the passed element at the bottom of the stack.
- Print the stack
Below is the implementation of the above approach:
*/
