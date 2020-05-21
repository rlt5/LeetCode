// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.

// Vertical Scan
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() )
            return "";
        if ( strs.size() == 1 )
            return strs[0];
        string result = strs[0];
        int size = result.size();
        for ( int i = 0; i < size; i++ ) {
            for ( int j = 1; j < strs.size(); j++ ){
                if ( strs[j][i] != result[i] ){
                    size == i;
                    result = result.substr(0,i);
                }
                    
                if ( result.empty() )
                    return "";
            }
        }
        return result;
    }
};

// // Horizontal Scan
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if ( strs.empty() )
//             return "";
        
//         string result = strs[0];
//         for ( string s : strs ){
//             for ( int i = 0; i < result.size(); i++ ) {
//                 if ( s[i] != result[i] ){
//                     result = result.substr(0,i);
//                 }
//                 if ( result.empty() )
//                     return "";
//             }
//         }
//         return result;
//     }
// };