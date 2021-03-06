// 567. Permutation in String

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
 

// Note:

// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

// TEST CASES
// 
// "ab"
// "eidbaooo"
// "ab"
// "eidboaoo"

#include <string>
using namespace std;

// Array Hashmap solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int src[26];
        int dest[26];
        int count = 0;
        int begin = 0;
        int end = 0;
        
        for (int i = 0; i < 26; i++){
            src[i] = 0;
            dest[i] = 0;
        }
        
        for ( char c : s1 ){
            src[c - 'a']++;
        }

        while ( end < s2.size() ){
            dest[s2[end] - 'a']++;
            
            if ( dest[s2[end] - 'a'] == src[s2[end] - 'a'] ){
                count += dest[s2[end] - 'a'];
            }
            
            while ( count == s1.size() ){
                if ( end - begin +1 == s1.size() ){
                    // cout << "end=" << end << " begin=" << begin << endl; 
                    return true;
                }
                if ( dest[s2[begin] - 'a'] == src[s2[begin] - 'a'] )
                    count -= dest[s2[begin] - 'a'];
                dest[s2[begin] - 'a']--;
                begin++;
            }
            end++;
        }
        return false;
    }
};

// // A hashmap implementation
// #include <map>
// #include <string>
// using namespace std;


// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         map<char, int> src, dest;
//         int count = 0;
//         int begin = 0;
//         int end = 0;
        
//         for ( char c : s1 ){
//             src[c]++;
//         }

//         while ( end < s2.size() ){
//             dest[s2[end]]++;
            
//             if ( dest[s2[end]] == src[s2[end]] ){
//                 count += dest[s2[end]];
//             }
            
//             while ( count == s1.size() ){
//                 if ( end - begin +1 == s1.size() ){
//                     return true;
//                 }
//                 if ( dest[s2[begin]] == src[s2[begin]] )
//                     count -= dest[s2[begin]];
//                 dest[s2[begin]]--;
//                 begin++;
//             }
//             end++;
//         }
//         return false;
//     }
// };