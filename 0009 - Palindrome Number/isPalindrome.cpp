// 9. Palindrome Number

// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Could you solve it without converting the integer to a string?

#include <limits.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Example 2 case
        if ( x < 0 )
            return false;
        int maxINT_10 = INT_MAX/10;
        int minINT_10 = INT_MIN/10;
        // Method 1. Reverse the int and check if its equal to original
        //  O(n)
        // Method 2. Pop first and last and check if equal until not satisfying invariant
        // O(n/2) ~ O(n)
        int result = 0;
        int tempX = x;
        while (tempX){
            if ( result > maxINT_10 || result == maxINT_10 && tempX % 10 > 2  )return false;
            result = result * 10 + tempX % 10;
            tempX /= 10;
        }
        if ( result == x )
            return true;
        else
            return false;
    }
};