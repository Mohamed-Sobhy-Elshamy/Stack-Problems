#include <bits/stdc++.h>
using namespace std;
/*
##Amazon | Microsoft | Adobe##

Given an array, print the Next Greater Element (NGE) for every element.

The Next greater Element for an element x is the first greater element on the right side of x in the array.
Elements for which no greater element exist, consider the next greater element as -1.

Example:

Input: arr[] = [ 4 , 5 , 2 , 25 ]
Output:  4      –>   5
         5      –>   25
         2      –>   25
         25     –>   -1
Explanation: except 25 every element has an element greater than them present on the right side
*/

// print element and NGE pair for all elements of arr[] of size
void printNGE(int arr[], int SIZE) {
    stack<int> s;

    // push the first element to stack
    s.push(arr[0]);

    // iterate for rest of the element
    for(int i = 1; i < SIZE; i++) {
        if(s.empty()) {
            s.push(arr[i]);
            continue;
        }

        // if is not empty, then pop an element from stack
            /*
                if the popped element is smaller than next, then
                    a. print the pair
                    b. keep popping while elements are smaller and stack is not empty
            */
        while(s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    // The remaining elements in stack do not have next greater element, so print -1 for them
    while(s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }

}

int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, size_arr);
    /*
    Output
        11 --> 13
        13 --> 21
        3 --> -1
        21 --> -1
    */
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    return 0;
}
