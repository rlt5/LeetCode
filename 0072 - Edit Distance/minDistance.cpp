// 72. Edit Distance
// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

#include <string>
#include <iostream>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;


// DP solution O ( word1.size() * word2.size() )
class Solution {
public:
    
    int minDistance(string word1, string word2) {
        
        int dp[word1.size()+1][word2.size()+1];
        for (int i = 0; i <= word1.size(); i++ ){
            for (int j = 0; j <= word2.size(); j++ ){
                dp[i][j] = 0;
            }
        }
         
        for (int i = 0; i <= word1.size(); i++ ){
            for (int j = 0; j <= word2.size(); j++ ){
                
                if ( i == 0 ){
                    dp[i][j] = j;
                } else if ( j == 0 ){
                    dp[i][j] = i;
                } else if ( word1[i-1] == word2[j-1] ){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int myInts[] = {dp[i][j-1], dp[i-1][j], dp[i-1][j-1]};
                    dp[i][j] = 1 + *min_element(myInts, myInts+3);
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};

// // Recursive solution O( 3 ^ word1.size() )
// class Solution {
// public:
    
//     int minDistance(string word1, string word2) {
//         // cout << word1 << " "  << word2 << endl;
//         int m = word1.size();
//         int n = word2.size();

//         if ( m == 0 ) return n;
//         if ( n == 0 ) return m;


//         // Algorithm for comparing the last letters of the string
//         if ( word1[m-1] == word2[n-1] ) return minDistance(word1.substr(0,m-1),word2.substr(0,n-1)); // If equal, don't need to add 1 to final count;
//         int myInts[] = {    minDistance(word1.substr(0,m-1),word2.substr(0,n)), // Remove 
//                             minDistance(word1.substr(0,m),word2.substr(0,n-1)), // Insert
//                             minDistance(word1.substr(0,m-1),word2.substr(0,n-1))// Replace
//                         };

//         // // Algorithm for comparing the first letters of the string
//         // if ( word1[0] == word2[0] ) return minDistance(word1.substr(1,m-1),word2.substr(1,n-1));
//         // int myInts[] = {    minDistance(word1.substr(1,m-1),word2.substr(0,n)), //
//         //                     minDistance(word1.substr(0,m),word2.substr(1,n-1)), 
//         //                     minDistance(word1.substr(1,m-1),word2.substr(1,n-1))
//         //                 };
        
//         return 1 + *min_element(myInts, myInts+3);
//     }
// };

int main(){
    Solution s;
    string word1 = "horse";
    string word2 = "ros";
    cout << "word1: " << word1 << " word2: " << word2 << " minDistance: " <<  s.minDistance(word1,word2) << endl;

    // word1 = "intention";
    // word2 = "execution";
    // cout << "word1: " << word1 << " word2: " << word2 << " minDistance: " <<  s.minDistance(word1,word2) << endl;
}