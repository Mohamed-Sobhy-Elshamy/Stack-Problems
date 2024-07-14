#include <bits/stdc++.h>
using namespace std;
/*
## Using Array
In an array-based implementation, the push operation is implemented
by incrementing the index of the top element and storing the new element at that index.
The pop operation is implemented by storing the element at the top,
decrementing the index of the top element and returning the value stored.
*/
const int MAX = 100;
// define stack
class Stack {
private:
    // declare the top
    int top;
public:
    // declare the array, functions and constructor.
    int arr[MAX];
    // constructor
    Stack() { top = -1; }
    bool Push(int element);
    int Pop();
    int Peek();
    bool isEmpty();
};

bool Stack::Push(int element) {
    if(top >= (MAX - 1)) {
        cout << "Stack overflow :(" << endl;
        return false;
    } else {
        arr[++top] = element;
        cout << element << " Is pushed into stack" << endl;
        return true;
    }
}

int Stack::Pop() {
    if(top < 0) {
        cout << "Stack underflow" << endl;
        return 0;
    } else {
        int element_is_deleted = arr[top--];
        return element_is_deleted;
    }
}

int Stack::Peek() {
    if(top < 0) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        int the_top_of_stack = arr[top];
        return the_top_of_stack;
    }
}

bool Stack::isEmpty() {
    return ( top < 0 );
}

int main()
{
    // create object from stack class
    class Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    /*
        first element at stack -> 10
        second element at stack -> 20
        third element at stack -> 30
    */
    // remove the top element
    cout << s.Pop() << " Popped from stack" << endl; // 30 is removed
    // print the top element
    cout << "Top element is : " << s.Peek() << endl; // 20
    // print all elements
    cout << "Elements present in stack : ";
    while(!s.isEmpty()) {
        cout << s.Peek() << " ";
        // remove top element the stack
        s.Pop();
    } // 20 10


    return 0;
}
