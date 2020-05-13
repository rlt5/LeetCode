// 402. Remove K Digits

// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.

// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Runtime is O(10002^2) if string is comprised of all the same digit and k = num.length
class Solution {
public:

    string removeKdigits(string num, int k) {
        int it;
        while ( num != "" && k ){
            it = 0;
            while ( it+1 < num.size() && num[it] <= num[it + 1] ){
                it++;
            }
            num.erase(it,1);
            k--;
            
            while ( num != "" && num[0] == '0' ){
                num.erase(0,1);
            }
        }
        if ( num == "" ){
            return "0";
        }
        return num;
    }
};


////// Current Solution does not work for very large strings.//////
// Runtime is O(10002^2)

// class Solution {
// public:

//     int stoi(string num){
//         int result = 0;
//         for (int i = 0; i < num.size(); i++){
//             // cout << result << "<-";
//             result = result*10 + num[i]-48;
//         }
//         // cout << endl;
//         return result;
//     }
    

//     string removeKdigits(string num, int k) {
//         string result = num;
//         string resultIt = num;
//         string temp = num;
//         while ( k ){
//             for ( int i = 0; i < result.size(); i++ ){
//                 temp = result;
//                 // cout << temp << endl;
//                 if ( stoi(temp.erase(i,1)) < stoi(resultIt) ){
//                     resultIt = temp;
//                 }
//             }
//             result = resultIt;
//             k--;
//         }
        
//         // cout << stoi(result) << endl;
//         int r = stoi(result);
//         stringstream ss;
//         ss << r;
//         return ss.str();
//     }
// };