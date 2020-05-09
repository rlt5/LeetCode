class Solution {
public:

    // Runtime is O(sqrt(n))
    bool isPerfectSquare(int num) {
        if (num < 1)
            return false;
        int i = 0;
        while ( i*i < num && i < 46340 ){
            i++;
        }
        if ( i*i == num ){
            return true;
        }
        return false;
    }

    
    // // Math implementation
    // // Runtime is O(sqrt(n))
    // bool isPerfectSquare(int num) {
    //     int i = 1;
    //     while (num > 0) {
    //         num -= i;
    //         i += 2;
    //     }
    //     return num == 0;
    // }
    
    // // Binary Search Algorithm
    // // Runtime is O(log(n))
    // bool isPerfectSquare(int num) {
    //     int low = 1, high = num;
    //     while (low <= high) {
    //         long mid = (low + high) >>> 1;
    //         if (mid * mid == num) {
    //             return true;
    //         } else if (mid * mid < num) {
    //             low = (int) mid + 1;
    //         } else {
    //             high = (int) mid - 1;
    //         }
    //     }
    //     return false;
    // }

    
    // ONLY WORKS IF ITS POWERS OF 2
    // bool isPerfectSquare(int num) {
    //     if (num == 2 || num < 1)
    //         return false;
    //     while ( num % 2 == 0 ){
    //         num /= 2;
    //     }
    //     if ( num == 1 )
    //         return true;
    //     return false;
    // }
};