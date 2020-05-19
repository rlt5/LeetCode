// 901. Online Stock Span

// Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

// The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

// For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 // Example 1:

// Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
// Output: [null,1,1,1,2,1,4,6]
// Explanation: 
// First, S = StockSpanner() is initialized.  Then:
// S.next(100) is called and returns 1,
// S.next(80) is called and returns 1,
// S.next(60) is called and returns 1,
// S.next(70) is called and returns 2,
// S.next(60) is called and returns 1,
// S.next(75) is called and returns 4,
// S.next(85) is called and returns 6.

// Note that (for example) S.next(75) returned 4, because the last 4 prices
// (including today's price of 75) were less than or equal to today's price.
 

// Note:

// Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
// There will be at most 10000 calls to StockSpanner.next per test case.
// There will be at most 150000 calls to StockSpanner.next across all test cases.
// The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.

// Test Cases
// ["StockSpanner","next","next","next","next","next","next","next"]
// [[],[100],[80],[60],[70],[60],[75],[85]]



#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int> span;
    vector<int> prev;
    int i;
    
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        
        // Edge Case. First Entry.
        if ( prev.empty() ){
            prev.push_back(price);
            span.push_back(1);
            i++;
            return 1;
        }
        
        int j = i;
        int count = 1;
        while ( j > 0 && price >= prev[j-1]){
            count += span[j-1];
            j -= span[j-1];
        }
        
        i++;
        prev.push_back(price);
        span.push_back(count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// #include <stack>
// using namepsace std;

// // Stack Implementation
// class StockSpanner {
// public:
//     stack<int> span;
//     stack<int> prev;
    
//     StockSpanner() {}
    
//     int next(int price) {
        
//         // Edge Case. First Entry.
//         int count = 1;
//         while ( !prev.empty() && prev.top() <= price ){
//             prev.pop();
//             count += span.top();
//             span.pop();
//         }
        
//         prev.push(price);
//         span.push(count);
//         return count;
//     }
// };