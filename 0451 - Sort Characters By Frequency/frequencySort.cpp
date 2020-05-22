// 451. Sort Characters By Frequency
// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

#include <iostream>
#include <map>

using namespace std;

// O(s.size())
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        map<int,string> n;
        string result;
        for ( char c : s ) m[c]++;
        for ( pair<char,int> p : m ){
            n[p.second] += string(p.second,p.first); // Fill constructor of String
        }
        for ( map<int,string>::reverse_iterator it = n.rbegin(); it!=n.rend(); it++ )
            result += it->second;
        return result;
    }
};

int main(){
    string s = "Aabb";
    Solution sol;
    cout << sol.frequencySort(s) <<  endl;
    // string y = s;
    // y[0] = 'f';
    // cout << s << endl;
    // cout << string(10,'1') << endl;

}