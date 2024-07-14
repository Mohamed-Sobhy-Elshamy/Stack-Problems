#include <bits/stdc++.h>
using namespace std;
/*
How to create mergeable stack?

Can we do it if we are not allowed to use an extra pointer?

We can do it with a circular linked list. The idea is to keep track of the last node in the linked list.
The next of the last node indicates the top of the stack.

push(): Adds the new item as next of the last node.
pop(): Removes next of last node.
merge(): Links the top (next of last) of the second list to the top (next of last) of the first list.
And makes last of the second list as last of the whole list.
*/

class node {
public:
    int data;
    node* next;
};

class my_stack {
public:
    node* head;
    node* tail;

    my_stack() {
        head = NULL;
        tail = NULL;
    }
};

my_stack* create() {
    my_stack* ms = new my_stack(); // Create a new stack
    return ms;
}

void Push(int new_data, my_stack* MS_) {
    node* temp = new node();
    temp->data = new_data;
    temp->next = MS_->head;

    // when pushing first element in the stack the tail must be pointed by that first element
    if(MS_->head == NULL)
        MS_->tail = temp;
    MS_->head = temp;
}

int pop(my_stack* ms) {
    if(ms->head == NULL) {
        cout << "Stack overflow" << endl;
        return 0;
    } else {
        node* temp = ms->head;
        ms->head = ms->head->next;
        int popped = temp->data;
        delete temp;
        return popped;
    }
}

// making the next pointer of tail of one stack point to other stack
void merge_(my_stack* ms_1, my_stack* ms_2) {
    if(ms_1->head == NULL) {
        ms_1->head = ms_2->head;
        ms_1->tail = ms_2->tail;
        return;
    }
    ms_1->tail->next = ms_2->head;
    ms_1->tail = ms_2->tail;
}

void display(my_stack* ms) {
    node* ptr = ms->head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    my_stack* ms1 = create();
    my_stack* ms2 = create();

    Push(6, ms1);
    Push(5, ms1);
    Push(4, ms1);
    Push(9, ms2);
    Push(8, ms2);
    Push(7, ms2);
    merge_(ms1, ms2);
    display(ms1);



    return 0;
}
