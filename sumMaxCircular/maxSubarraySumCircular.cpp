// 918. Maximum Sum Circular Subarray
// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

// Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

// Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

// Example 1:

// Input: [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3
// Example 2:

// Input: [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
// Example 3:

// Input: [3,-1,2,-1]
// Output: 4
// Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
// Example 4:

// Input: [3,-2,2,-3]
// Output: 3
// Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
// Example 5:

// Input: [-2,-3,-1]
// Output: -1
// Explanation: Subarray [-1] has maximum sum -1

// Note:

// -30000 <= A[i] <= 30000
// 1 <= A.length <= 30000

////////////////////// TEST CASES //////////////////////
// [1,-2,3,-2]
// [5,-3,5]
// [3,-1,2,-1]
// [3,-2,2,-3]
// [-2,-3,-1]
// [1,-1,-1,2,3,4]
// [0]
// [-1]
// [-3,-5,-2,-5,-6]
// [2,-2,2,7,8,0]

#include <vector>
using namespace std;

class Solution {
public:
    
    // Kadane
    int kadane(vector<int>& A){
        int max = -30001;
        int tempMax = max;
        for ( int i = 0; i < A.size(); i++ ){
            tempMax = tempMax + A[i];
            if ( tempMax > max ){
                max = tempMax;
            }
            if ( tempMax < 0 ){
                tempMax = 0;
            }
        }
        return max;
    }

    int maxSubarraySumCircular(vector<int>& A) {
        
        // Case 1
        // Kadane
        int max = kadane(A);

        // Case 2 - We invert everything and get everything that we dont want. We then add everything that we dont want to the sum of the entire array. Since we inverted, this is essentially subtracting everything we dont want from the total of the array. Then we return the max of both cases.
        int max2 = 0;
        for ( int i = 0; i < A.size(); i++ ){
            max2 += A[i];
            A[i] *= -1;
        }
        
        int max3 = kadane(A);
        max2 += max3;

        return (max2 > max) ? max2 : max;
    }
};


// // Brute Force Solution. Works but too slow. Time exceeded
// class Solution {
// public:
    
//     int maxSubarraySumCircular(vector<int>& A) {
//         int startMax = 0;
//         int finishMax = 0;
//         int max = A[0];
        
//         for ( int j = 0; j < A.size(); j++ ){
//             int tempStartMax = 0;
//             int tempMax = 0;
//             for ( int i = 0; i < A.size(); i++ ){
//                 tempMax = tempMax + A[(i+j) % A.size()];
//                 if ( tempMax > max ){
//                     max = tempMax;
//                     startMax = tempStartMax;
//                     finishMax = i;
//                 }

//                 if ( tempMax < 0 ){
//                     tempMax = 0;
//                     tempStartMax = i+1;
//                 }
//             }            
//         }

        
//         return max;
//     }
// };

// Original Solution -- Doesnt work.
// class Solution {
// public:
    
//     // Kadane's Algorithm
//     int maxSubarraySumCircular(vector<int>& A) {
//         int startMax = 0;
//         int finishMax = 0;
//         int tempStartMax = 0;
//         int max = A[0];
//         int tempMax = 0;
//         for ( int i = 0; i < A.size(); i++ ){
//             tempMax = tempMax + A[i];
//             if ( tempMax > max ){
//                 max = tempMax;
//                 startMax = tempStartMax;
//                 finishMax = i;
//             }

//             if ( tempMax < 0 ){
//                 tempMax = 0;
//                 tempStartMax = i+1;
//             }
//         }
        
        
//         if ( startMax == 0 && finishMax != A.size()-1 ){
//             int i = A.size()-1;
//             tempMax = max;
//             while ( i > finishMax){
//                 tempMax = tempMax + A[i];
//                 if ( tempMax >= max ){
//                     max = tempMax;
//                 }
//                 i--;
//             }
//         } else if ( startMax != 0 && finishMax == A.size()-1 ){
//             int i = 0;
//             tempMax = max;
//             while ( i < startMax ){
//                 tempMax = tempMax + A[i];
//                 if ( tempMax >= max ){
//                     max = tempMax;
//                 }
//                 i++;
//             }
//         } 
//         else if ( startMax == 0 && finishMax == A.size()-1 ){
//             if ( (int)A.size() - 2 > 0 && A[A.size()-2] < 0  ){
//                 int i = A.size()-2;
//                 while ( i > startMax && A[i] < 0){
//                     max -= A[i];
//                     i--;
//                 }  
//             } 
//                 else if ( 1 < A.size()-1 && A[1] < 0 ){
//                 int i = 1;
//                 while ( i < A.size()-1 && A[i] < 0){
//                     max -= A[i];
//                     i++;
//                 }
//             }

//         }
        
//         return max;
//     }
// };

// Record the beginning of the max sum
// we keep the max of the current subarray or the current subarray + next item
// if current subarray > current sub + next item, we will start a new counter at the next next item.