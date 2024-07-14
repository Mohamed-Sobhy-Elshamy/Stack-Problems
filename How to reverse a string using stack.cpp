#include <bits/stdc++.h>
using namespace std;
/*
Given a string, reverse it using stack.

Example:

Input: str = “GeeksQuiz”
Output: ziuQskeeG

Input: str = “abc”
Output: cba
*/

// A structure to stack
class Stack {
public:
    int top;
    unsigned capacity;
    char* Array;
};

// Function to create a stack of given capacity,
    // it initializes size of stack as 0
Stack* create_stack(unsigned capacity_) {
    Stack* stack = new Stack();
    stack->capacity = capacity_;
    stack->top = -1;
    stack->Array = new char[ (stack->capacity * sizeof(char)) ];
    return stack;
}

// stack is full when top is equal to the last index
int is_full(Stack* stack_) {
    return stack_->top == stack_->capacity - 1;
}

// is empty when top is equal to -1
int isEmpty(Stack* st) {
    return st->top == -1;
}

// to add an item to stack, it increases top by 1
void Push(Stack* stack_, char item) {
    if(is_full(stack_))
        return;
    stack_->Array[++stack_->top] = item;
}

// to remove an item from stack, it decreases top by 1
char Pop(Stack* sta) {
    if(isEmpty(sta))
        return -1;
    return sta->Array[sta->top--];
}

// stack based function to reverse a string
void reverse_stack(char str[]) {
    // create a stack of capacity equal to length of string
    int len = strlen(str);
    Stack* _stack = create_stack(len);

    // push all chars of string to stack
    int i;
    for(i = 0; i < len; i++)
        Push(_stack, str[i]);

    // pop all chars of string and put them back to str
    for(i = 0; i < len; i++)
        str[i] = Pop(_stack);
}

int main()
{
    char str[] = "abc";

    reverse_stack(str);
    cout << "Reversed string is " << str;


    return 0;
}
/*
Approach:

The idea is to create an empty stack and push all the characters from the string into it.
Then pop each character one by one from the stack and put them back into the input string starting from the 0’th index. As we all know,
stacks work on the principle of first in, last out.
After popping all the elements and placing them back to string, the formed string would be reversed.

Follow the steps given below to reverse a string using stack.

- Create an empty stack.
- One by one push all characters of string to stack.
- One by one pop all characters from stack and put them back to string.
*/
