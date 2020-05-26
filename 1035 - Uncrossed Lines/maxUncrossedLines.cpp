// 1035. Uncrossed Lines
// We write the integers of A and B (in the order they are given) on two separate horizontal lines.

// Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

// A[i] == B[j];
// The line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

// Return the maximum number of connecting lines we can draw in this way.

// Example 1:
// Input: A = [1,4,2], B = [1,2,4]
// Output: 2
// Explanation: We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.

// Example 2:
// Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
// Output: 3

// Example 3:
// Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
// Output: 2

// Note:

// 1 <= A.length <= 500
// 1 <= B.length <= 500
// 1 <= A[i], B[i] <= 2000

// TEST CASES
// [2,5,1,2,5]
// [10,5,2,1,5,2]
// [1,1,2,1,2]
// [1,3,2,3,1]
// [1,4,2]
// [1,2,4]
// [1,2,2]
// [3]
// [3,1,4,1,1,3,5,1,2,2]
// [4,1,5,2,1,1,1,5,3,1,1,1,2,3,1,4,3,5,5,3,1,2,3,2,4,1,1,1,5,3]
// [2,3,4,3,1,4,2,5,3,2,5,1,4,3,3]
// [5,1,2,1,3,2,3,4,5,3]
// [5,5,4,1,5,5,3,4,2,2,1,1,2,2,5]
// [5,5,5,2,1,4,1,5,3,3,2,2,4,4,1]

#include <vector>
using namespace std;
class Solution {
public:
    int maxL( vector<int>& A, vector<int>& B, vector<vector<int>> dp, int i, int j){
        int aSize = A.size();
        int bSize = B.size();
        if ( i == aSize || j == bSize )
            return 0;
        if ( dp[i][j] >= 0 )
            return dp[i][j];
        int max = 0;
        if ( A[i] == B[j] )
            max = maxL(A,B,dp,i+1,j+1) + 1 > max ? maxL(A,B,dp,i+1,j+1) + 1 : max;
        max = maxL(A,B,dp,i+1,j) > max ? maxL(A,B,dp,i+1,j) : max;
        max = maxL(A,B,dp,i,j+1) > max ? maxL(A,B,dp,i,j+1) : max;
        dp[i][j] = max;
        return max;
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size());
        for ( int i = 0; i < A.size(); i++ ){
            dp[i].resize(B.size());
            for ( int j = 0; j < B.size(); j++ ){
                dp[i][j] = -1;
            }
        }
        return maxL(A,B,dp,0,0);
    }
};

