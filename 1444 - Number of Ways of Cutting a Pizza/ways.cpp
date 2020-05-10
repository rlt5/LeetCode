// 1444. Number of Ways of Cutting a Pizza

// Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

// For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

// Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

// Example 1:
// Input: pizza = ["A..","AAA","..."], k = 3
// Output: 3 
// Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

// Example 2:
// Input: pizza = ["A..","AA.","..."], k = 3
// Output: 1

// Example 3:
// Input: pizza = ["A..","A..","..."], k = 1
// Output: 1
 
// Constraints:
// 1 <= rows, cols <= 50
// rows == pizza.length
// cols == pizza[i].length
// 1 <= k <= 10
// pizza consists of characters 'A' and '.' only.

class Solution {

    // DP Solution
    public:
    long long modulo = 1000000007;
    long long memoized[51][51][11];
    int slice[101][101];
    
    long long helper(int rows, int cols, int k){
        if ( memoized[rows][cols][k] >= 0 ){
            return memoized[rows][cols][k];
        }
        
        if ( k == 1 ){
            return slice[rows][cols] > 0;
        }
        
        long long result = 0;
        
        for ( int row = 1; row < rows; row++ ){
            if ( slice[row][cols] > 0 && slice[rows][cols] - slice[row][cols] > 0 ){
                result += helper(row, cols, k-1);
            }
        }        
        
        for ( int col = 1; col < cols; col++ ){
            if ( slice[rows][col] > 0 && slice[rows][cols] - slice[rows][col] > 0 ){
                result += helper(rows, col, k-1);
            }
        }
                
        return memoized[rows][cols][k] = result % modulo;
    }
    
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();
        for ( auto& p : pizza ){
            reverse(p.begin(), p.end());
        }
        reverse(pizza.begin(), pizza.end());
        

        
        for ( int col = 0; col < cols; col++ ){
            for ( int row = 0; row < rows; row++ ){
                slice[row][col] = 0;
            }            
        }
        
        for ( int col = 0; col < cols; col++ ){
            for ( int row = 0; row < rows; row++ ){
                slice[row+1][col+1] = slice[row][col+1] + slice[row+1][col] - slice[row][col] + (pizza[row][col] == 'A');
            }
        }
        
        for ( int i = 0; i < 51; i++ ){
            for ( int j = 0; j < 51; j++ ){
                for ( int k = 0; k < 11; k++ ){
                    memoized[i][j][k] = -1;
                }
            }
        }
        
        return helper(rows,cols,k);
    }
};