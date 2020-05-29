// 338. Counting Bits
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example 1:
// Input: 2
// Output: [0,1,1]

// Example 2:
// Input: 5
// Output: [0,1,1,2,1,2]
// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

#include <vector>
using namespace std;

class Solution {
public:

    // Fastest solution O(n)
    vector<int> countBits(int num){
        vector<int> solution(num+1,0);
        for ( int i = 1; i <= num; i++ ){
            solution[i] = solution[i>>1] + i%2;
        }
        return solution;
    }



    // // O(n) solution.
    // // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetTable
    // vector<int> countBits(int num){
    //     static const int S[5] = {1, 2, 4, 8, 16};
    //     static const int B[5] = {0x55555555,0x33333333,0x0F0F0F0F,0x00FF00FF,0x0000FFFF};
    //     vector<int> solution;
    //     int v,c;
    //     for ( int i = 0; i <= num; i++ ){
    //         v = i;
    //         c = v - ((v >> 1) & B[0]);
    //         c = ((c >> S[1]) & B[1]) + (c & B[1]);
    //         c = ((c >> S[2]) + c) & B[2];
    //         c = ((c >> S[3]) + c) & B[3];
    //         c = ((c >> S[4]) + c) & B[4];
    //         solution.push_back(c);
    //     }
    //     return solution;    
    // }
    
    // // CHEATING USING POPCOUNT
    // vector<int> countBits(int num) {
    //     vector<int> solution;
    //     for ( int i = 0; i <= num; i++ ){
    //         solution.push_back( __builtin_popcount(i) );
    //     }
    //     return solution;
    // }
    
    
//     // O(n*sizeof(INT))
//     vector<int> countBits(int num) {
        
//         vector<int> solution;
//         for (int i = 0; i <= num; i++){
            
//             int n = i;
//             int count = 0;
//             while ( n ){
//                 count += n & 1;
//                 n >>= 1;
//             }
//             solution.push_back(count);
//         }
//         return solution;
//     }
    
    
};