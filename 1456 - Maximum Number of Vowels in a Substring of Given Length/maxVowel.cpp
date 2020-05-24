// 1456. Maximum Number of Vowels in a Substring of Given Length

// Given a string s and an integer k.
// Return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are (a, e, i, o, u).

// Example 1:
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:
// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:
// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.

// Example 4:
// Input: s = "rhythms", k = 4
// Output: 0
// Explanation: We can see that s doesn't have any vowel letters.

// Example 5:
// Input: s = "tryhard", k = 4
// Output: 1
 
// Constraints:

// 1 <= s.length <= 10^5
// s consists of lowercase English letters.
// 1 <= k <= s.length

#include <string>
using namespace std;

class Solution {
public:
    
    // Solution seems to be sliding window
    int maxVowels(string s, int k) {
        int solution = 0;
        int current = 0;
        int begin = 0;
        int end = 0;
        while ( end < s.size() ){
            if ( s[end] == 'a' || 
                 s[end] == 'e' ||
                 s[end] == 'i' ||
                 s[end] == 'o' ||
                 s[end] == 'u' )
                current++;
            while ( end - begin >= k ){
                if ( s[begin] == 'a' || 
                     s[begin] == 'e' ||
                     s[begin] == 'i' ||
                     s[begin] == 'o' ||
                     s[begin] == 'u' )
                    current--;
                begin++;
            }
            if ( current > solution ){
               solution = current;
            }
            end++;
        } 
        return solution;   
    }
};