#include <bits/stdc++.h>
using namespace std;
/*
Given an array, for each element find the value of the nearest element to the right
which is having a frequency greater than that of the current element.
If there does not exist an answer for a position, then make the value ‘-1’.

Examples:

Input : a[] = [1, 1, 2, 3, 4, 2, 1]
Output : [-1, -1, 1, 2, 2, 1, -1]

Explanation:
Given array a[] = [1, 1, 2, 3, 4, 2, 1]
Frequency of each element is: 3, 3, 2, 1, 1, 2, 3

Lets calls Next Greater Frequency element as NGF
1. For element a[0] = 1 which has a frequency = 3,
   As it has frequency of 3 and no other next element
   has frequency more than 3 so  '-1'
2. For element a[1] = 1 it will be -1 same logic
   like a[0]
3. For element a[2] = 2 which has frequency = 2,
   NGF element is 1 at position = 6  with frequency
   of 3 > 2
4. For element a[3] = 3 which has frequency = 1,
   NGF element is 2 at position = 5 with frequency
   of 2 > 1
5. For element a[4] = 4 which has frequency = 1,
   NGF element is 2 at position = 5 with frequency
   of 2 > 1
6. For element a[5] = 2 which has frequency = 2,
   NGF element is 1 at position = 6 with frequency
   of 3 > 2
7. For element a[6] = 1 there is no element to its
   right, hence -1
*/
// Using Hashing and Stack

// Function to find the NGF element for each element in array
void NGF(int arr[], int SizeArr, int freq[])
{
    // stack DS to store the position of array
    stack<int> s;
    s.push(0);

    // res to store the value of NGF for each element
    int res[SizeArr] = { 0 };
    for(int i = 1; i < SizeArr; i++) {
        // if freq of element is pointed by the top of stack is greater than freq of current element
            // then push the current position i in stack
        if(freq[arr[s.top()]] > freq[arr[i]])
            s.push(i);
        else {
            // if the freq of element which is pointed by the top is less freq of the current
                // than pop the stack and continuing popping until the above condition is true while the stack is not empty
            while(!s.empty() && freq[arr[s.top()]] < freq[arr[i]]) {
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }

    }
    while(!s.empty()) {
        res[s.top()] = -1;
        s.pop();
    }
    for(int i = 0; i < SizeArr; i++) {
        cout << res[i] << " ";
    }
}

int main() {
    int a[] = { 1, 1, 2, 3, 4, 2, 1 };
    int len = sizeof(a) / sizeof(a[0]);
    int max_ = INT_MIN;
    for(int i = 0; i < len; i++) {
        // Getting the max element of the array
        if(a[i] > max_)
            max_ = a[i];
    }
    int freq[max_ + 1] = { 0 };

    // Calculating freq
    for(int i = 0; i < len; i++)
        freq[a[i]]++;
    // Function Call
    NGF(a, len, freq);

    // -1 -1 1 2 2 1 -1

    return 0;
}
/*
Create a list to use values as index to store frequency of each element.
Push the position of first element to stack.
Pick rest of the position of elements one by one and follow following steps in loop.
    - Mark the position of current element as ‘i’ .
    - If the frequency of the element which is pointed by the top of stack is greater than frequency
        of the current element, push the current position i to the stack
    - If the frequency of the element which is pointed by the top of stack is less than frequency of the current element and the stack is not empty then follow these steps:
        - continue popping the stack
        - if the condition in step c fails then push the current position i to the stack
After the loop in step 3 is over, pop all the elements from stack and print -1 as next greater frequency element for them does not exist.
*/
