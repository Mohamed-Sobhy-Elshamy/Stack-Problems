#include <bits/stdc++.h>
using namespace std;
/*
In a linked list-based implementation, the push operation is implemented by creating
a new node with the new element and setting the next pointer of the current top node to the new node.
The pop operation is implemented by setting the next pointer of the current top node
to the next node and returning the value of the current top node.
*/
struct stack_node {
    int data;
    stack_node* next;
};

// create new node
stack_node* new_node(int new_data) {
    stack_node* node_of_stack = new stack_node();
    node_of_stack->data = new_data;
    node_of_stack->next = NULL;
    return node_of_stack;
}

int isEmpty(stack_node* root) {
    return !root; // false
}

void push_node(stack_node*& root, int new_data) {
    stack_node* stack_of_node_is_pushed = new_node(new_data);
    stack_of_node_is_pushed-> next = root;
    root = stack_of_node_is_pushed;
    cout << "Pushed to stack" << endl;
    cout << new_data << endl;
}

int pop_node(stack_node*& root) {
    if(isEmpty(root))
        return INT_MIN;
    stack_node* temp = root;
    int popped = temp->data;
    root = root->next;
    delete(temp);

    return popped;
}

int peek_node(stack_node* root) {
    if(isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main() {
    stack_node* root = NULL;

    push_node(root, 10);
    push_node(root, 20);
    push_node(root, 30);

    cout << "Popped from stack: " << pop_node(root) << endl;
    cout << "Top element is: " << peek_node(root) << endl;

    return 0;
}
