// 986. Interval List Intersections
// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 // Example 1:

// Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 
// Note:

// 0 <= A.length < 1000
// 0 <= B.length < 1000
// 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

// TEST CASES
// [[0,2],[5,10],[13,23],[24,25]]
// [[1,5],[8,12],[15,24],[25,26]]
// [[0,100]]
// [[0,0]]
// [[0,0]]
// [[0,100]]


#include <vector>
using namespace std;

// O( size(A) + size(B) )  REFACTORED CODE to remove all pointers and vector iterators. Refactored code is 4ms faster.
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> solution;
        int a = 0;
        int b = 0;
        int a0,a1,b0,b1;
        int aSize = A.size();
        int bSize = B.size();
        while ( a < aSize && b < bSize ){
            a0 = A[a][0];
            a1 = A[a][1];
            b0 = B[b][0];
            b1 = B[b][1];
            if ( a0 > b1 ) {
                b++;
            } else if ( b0 > a1 ){
                a++;
            } else if ( a0 <= b0 && a1 >= b1 ){
                solution.push_back(vector<int> ({b0,b1}));
                b++;
            }else if ( b0 <= a0 && b1 >= a1){
                solution.push_back(vector<int> ({a0,a1}));
                a++;
            }else if ( b0 >= a0 && b1 >= a1 ){
                solution.push_back(vector<int> ({b0,a1}));
                a++;
            }else if ( a0 >= b0 && a1 >= b1 ){
                solution.push_back(vector<int> ({a0,b1}));
                b++;
            }    
        }
        return solution;
    }
};


// // O( size(A) + size(B) ) 
// class Solution {
// public:
//     vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
//         vector<vector<int>> solution;
//         vector<vector<int>>::iterator pairA = A.begin();
//         vector<vector<int>>::iterator pairB = B.begin();
//         while ( pairA != A.end() && pairB != B.end()){
//             if ( (*pairA)[0] > (*pairB)[1] ) {
//                 pairB++;
//             } else if ((*pairB)[0] > (*pairA)[1] ){
//                 pairA++;
//             } else if ( (*pairA)[0] <= (*pairB)[0] && (*pairA)[1] >= (*pairB)[1]){
//                 solution.push_back(vector<int> ({(*pairB)[0],(*pairB)[1]}));
//                 pairB++;
//             }else if ( (*pairB)[0] <= (*pairA)[0] && (*pairB)[1] >= (*pairA)[1]){
//                 solution.push_back(vector<int> ({(*pairA)[0],(*pairA)[1]}));
//                 pairA++;
//             }else if ( (*pairB)[0] >= (*pairA)[0] && (*pairB)[1] >= (*pairA)[1] ){
//                 solution.push_back(vector<int> ({(*pairB)[0],(*pairA)[1]}));
//                 pairA++;
//             }else if ( (*pairA)[0] >= (*pairB)[0] && (*pairA)[1] >= (*pairB)[1] ){
//                 solution.push_back(vector<int> ({(*pairA)[0],(*pairB)[1]}));
//                 pairB++;
//             }    
//         }
//         return solution;
//     }
// };

// // O( size(A) * size(B) ) SLOW AF
// class Solution {
// public:
//     vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
//         vector<vector<int>> solution;
//         for ( vector<int> pairA : A ){
//             for ( vector<int> pairB : B ){
//                 if ( pairA[0] <= pairB[0] && pairA[1] >= pairB[1]){
//                     solution.push_back(vector<int> ({pairB[0],pairB[1]}));
//                 }else if ( pairB[0] <= pairA[0] && pairB[1] >= pairA[1]){
//                     solution.push_back(vector<int> ({pairA[0],pairA[1]}));
//                 }else if ( pairB[0] >= pairA[0] && pairB[0] <= pairA[1] ){
//                     solution.push_back(vector<int> ({pairB[0],pairA[1]}));
//                 }else if ( pairA[0] >= pairB[0] && pairA[0] <= pairB[1] ){
//                     solution.push_back(vector<int> ({pairA[0],pairB[1]}));
//                 }    
//             }
//         }
//         return solution;
//     }
// };