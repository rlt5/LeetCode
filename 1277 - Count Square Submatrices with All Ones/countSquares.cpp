// 1277. Count Square Submatrices with All Ones

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.
 
// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1

// TEST CASES
// [[0,1,1,1],[1,1,1,1],[0,1,1,1]]

#include <vector>
#include <algorithm>
using namespace std;

// DP solution
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int total = 0;
        for ( int r = 0; r < rows; r++ ){
            for ( int c = 0; c < cols; c++ ){
                if ( matrix[r][c] && r && c ){
                    matrix[r][c] += min({matrix[r-1][c], matrix[r][c-1], matrix[r-1][c-1]});
                }
                total += matrix[r][c];
            }
        }
        return total;
    }
};        



// // O(n^4 solution) SLOW!!!
// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         // Largest Square will be based on the smallest value m or n
//         int rows = matrix.size();
//         int cols = matrix[0].size();
        
//         int n = min(rows,cols);
//         int total = 0;
//         int square;
//         while ( n > 0 ){
//             square = n*n;
//             for ( int r = 0; r <= rows-n ; r++ ){
//                 for ( int c = 0; c <= cols-n; c++ ){
//                     total++;
//                     for ( int x = r; x < r + n; x++ ){
//                         for ( int y = c; y < c + n; y++){
//                             if ( matrix[x][y] == 0){
//                                 total--;
//                                 x = rows;
//                                 y = cols;
//                             }
//                         }
//                     }
//                 }
//             }
//             n--;
//         }
//         return total;
//     }
// };