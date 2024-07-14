#include <bits/stdc++.h>
using namespace std;
/*
##Google | Meta | Amazon | Microsoft##

The stock span problem is a financial problem where we have a series of N daily price quotes
for a stock and we need to calculate the span of the stock’s price for all N days.
The span Si of the stock’s price on a given day i is defined as the maximum number
of consecutive days just before the given day, for which the price of the stock on
the current day is less than or equal to its price on the given day.

Examples:

Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1,
80 is smaller than 100 so the span is 1,
60 is smaller than 80 so the span is 1,
70 is greater than 60 so the span is 2 and so on.
Hence the output will be 1 1 1 2 1 4 6.

Input: N = 6, price[] = [10 4 5 90 120 80]
Output:1 1 2 4 5 1
Explanation: Traversing the given input span for 10 will be 1,
4 is smaller than 10 so the span will be 1,
5 is greater than 4 so the span will be 2 and so on.
Hence, the output will be 1 1 2 4 5 1.
*/

void calculate_span(int price[], int Size, int span[]) {
    // create a stack and push index of first element to it
    stack<int> st;
    st.push(0);

    // span value of first element is always 1
    span[0] = 1;

    // calculate span values for rest of the elements
    for(int i = 1; i < Size; i++) {
        // pop elements from stack while stack is not empty
            // and top of stack is smaller than price[i]
        while(!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
            // if stack becomes empty, then price[i] is greater the all elements
                // on left of it, price[0], price[1], ..price[i - 1]
                // else price[i] is greater than elements after top of stack
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }
    }
}

void print_arr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}


int main()
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int N = sizeof(price) / sizeof(price[0]);
    int span[N];

    // Fill the span values in array
    calculate_span(price, N, span);

    print_arr(span, N);

    // Time and Space Complexity: O(n)

    return 0;
}
/*
Follow the below steps to solve the problem:

Create a stack of type int and push 0 in it
Set the answer of day 1 as 1 and run a for loop to traverse the days
While the stack is not empty and the price of st.top is less than or equal to the price of the current day,
    pop out the top value
Set the answer of the current day as i+1 if the stack is empty else equal to i – st.top
Push the current day into the stack
Print the answer using the answer array
*/
