// 231. Power of Two
// Given an integer, write a function to determine if it is a power of two.

// Example 1:
// Input: 1
// Output: true 
// Explanation: 20 = 1

// Example 2:
// Input: 16
// Output: true
// Explanation: 24 = 16

// Example 3:
// Input: 218
// Output: false

// TEST CASES 
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 218
// 256

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n == 0 ) return false;
        while ( n > 1 ){
            if ( n & 1)
                break;
            n >>= 1;
        }
        n >>= 1;

        return n ? false : true;
    }
};