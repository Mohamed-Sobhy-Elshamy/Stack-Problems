#include <bits/stdc++.h>
using namespace std;
/*
## Amazon ##
Give an algorithm for reversing a queue Q. Only the following standard operations are allowed on queue.

enqueue(x): Add an item x to the rear of the queue.
dequeue(): Remove an item from the front of the queue.
empty(): Checks if a queue is empty or not.
The task is to reverse the queue.

Examples:

Input: Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
Output: Q = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10]
*/

// Function to reverse the queue
void reverse_queue(queue<int>& Queue) {
    stack<int> stack_;
    while(!Queue.empty()) {
        stack_.push(Queue.front());
        Queue.pop();
    }
    while(!stack_.empty()) {
        Queue.push(stack_.top());
        stack_.pop();
    }
}

// Utility function to print the queue
void print(queue<int>& Queue) {
    while(!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}


int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    reverse_queue(Queue);
    print(Queue);

    // Time Complexity: O(N)
    // Space Complexity: O(N)

    return 0;
}
/*
Reversing a Queue using stack:
For reversing the queue one approach could be to store the elements of the queue in a temporary
data structure in a manner such that if we re-insert the elements in the queue they would get inserted in reverse order.
So now our task is to choose such a data structure that can serve the purpose. According to the approach,
the data structure should have the property of ‘LIFO’ as the last element to be inserted in the
data structure should actually be the first element of the reversed queue.

Follow the below steps to implement the idea:

- Pop the elements from the queue and insert into the stack now topmost element of the stack is the last element of the queue.
- Pop the elements of the stack to insert back into the queue the last element is the first one to be inserted into the queue.
*/
