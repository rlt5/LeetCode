#include <iostream>
// #include <stack>
#include <bits/stdc++.h> 
#include <string>
#include <stack>
#include <list>

using namespace std;

////////////////////////////////////////////////////////////////
//// BRUTE FORCE O(n^3)
// bool validParentheses(string s){
//     int count = 0;
//     for (char c : s){
//         if ( c == '('){
//             count++;
//         } else {
//             if (count){
//                 count--;
//             } else {
//                 return false;
//             }
//         }
//     }
//     if ( count == 0 ){
//         return true;
//     } else 
//         return false;
// }
// 
// 
// int longestValidParentheses(string s){
//     int length = s.length();
//     // int maxLength[length];
//     // for ( int i = 0; i < length; i++ ){
//     //     maxLength[i] = 0;
//     // }
//     int maxLength = 0;
//     for (int i = 0; i < length; i++ ){
//         for ( int j = i + 1; j < length; j++ ){
//             if ( j - i + 1 > maxLength){
//                 if ( validParentheses(s.substr(i, j-i+1)) ){
//                         maxLength = j - i + 1;
//                 }
//             }
//         }
//     }
//     return maxLength;
// }
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// O(n^2) dp solution
// int longestValidParentheses(string s){
//     int length = s.length();
//     if (length == 0) return 0; 

//     int maxLength[length];
//     for ( int i = 0; i < length; i++ ){
//         maxLength[i] = 0;
//     }  

//     int count = 0, currentMax = 0, countL = 0;
//     for ( int i = 0; i < length; i++ ){
//         currentMax = 0;
//         count = 0;
//         for ( int j = i; j < length; j++){

//             if ( s[j] == '('){
//                 count++;
//             } else {
//                 if ( count ){
//                     count--;
//                     currentMax++;
//                 } else {
//                     currentMax = 0;
//                 }
//             }
// 
//             if ( count == 0 ){
//                 if (maxLength[j] < currentMax ){
//                     maxLength[j] = currentMax;
//                 }
//             }
//         }
//     }
// 
//     int maxReturn = 0;
//     for ( int i = 0; i < length; i++ ){
//         if ( maxReturn < maxLength[i] ){
//             maxReturn = maxLength[i];
//         }
//     }
//     return maxReturn*2;
// }
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
// O(n) dp solution
// int longestValidParentheses(string s){
//     int length = s.length();
//     if (length == 0) return 0; 
//     int maxLength[length];
//     int maxReturn = 0;
//     for ( int i = 0; i < length; i++ ){
//         maxLength[i] = 0;
//     }  
//     for ( int i = 1; i < length; i++ ){
//         if ( s[i] == ')' ){
//             if ( s[i-1] == '(' ){
//                 maxLength[i] = (i >= 2 ? maxLength[i-2] : 0) + 2;
//             } else if ( i - maxLength[i-1] > 0 && s[i-maxLength[i-1]-1] == '(' ){
//                 maxLength[i] = maxLength[i - 1] + ((i - maxLength[i - 1]) >= 2 ? maxLength[i - maxLength[i - 1] - 2] : 0) + 2;
//             }
//             if ( maxReturn < maxLength[i] )
//                 maxReturn = maxLength[i];
//         }
//     }
//     return maxReturn;
// }
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// O(n) STACK Solution
int longestValidParentheses(string s) {
    int maxReturn = 0;
    stack<int> stack;
    stack.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            } else {
                maxReturn = max(maxReturn, i - stack.top());
            }
        }
    }
    return maxReturn;
}
////////////////////////////////////////////////////////////////



int main(){

    list<string> list;
    list.push_back("(()");
    list.push_back("()(()");
    list.push_back(")()())");
    list.push_back("()()()");
    list.push_back("))))())()()(()");
    list.push_back(")(((((())))(((())()))()(()(()())())()))((())()(()))))()))))))(()()))((()))()(()()))()())))(()()))())()()(()(((()))))))((((()())))((()))))()()())");
    list.push_back("((())())(()))(()()(()(()))(()((((()))))))((()())()))()()(()(((((()()()())))()())(()()))((((((())))((()))()()))))(()))())))()))()())((()()))))(()(((((())))))()((()(()(())((((())(())((()()(()())))())(()(())()()))())(()()()))()(((()())(((()()())))(((()()()))(()()))()))()))))))())()()((()(())(()))()((()()()((())))()(((()())(()))())())))(((()))))())))()(())))()())))())()((()))((()))()))(((())((()()()(()((()((())))((()()))())(()()(()))))())((())))(()))()))))))()(()))())(()())))))(()))((())(()((())(((((()()()(()()())))(()())()((()(()()))(()(())((()((()))))))))(()(())()())()(()(()(()))()()()(()()())))(())(()((((()()))())))(())((()(())())))))())()()))(((())))())((()(()))(()()))((())(())))))(()(()((()((()()))))))(()()()(()()()(()(())()))()))(((()(())()())(()))())))(((()))())(()((()))(()((()()()(())()(()())()(())(()(()((((())()))(((()()(((()())(()()()(())()())())(()(()()((()))))()(()))))(((())))()()))(()))((()))))()()))))((((()(())()()()((()))((()))())())(()((()()())))))))()))(((()))))))(()())))(((()))((()))())))(((()(((())))())(()))))(((()(((((((((((((())(((()))((((())())()))())((((())(((())))())(((()))))()())()(())())(()))))()))()()()))(((((())()()((()))())(()))()()(()()))(())(()()))()))))(((())))))((()()(()()()()((())((((())())))))((((((()((()((())())(()((()))(()())())())(()(())(())(()((())((())))(())())))(()()())((((()))))((()(())(()(()())))))))))((()())()()))((()(((()((()))(((((()()()()()(()(()((()(()))(()(()((()()))))()(()()((((((()((()())()))((())()()(((((()(()))))()()((()())((()())()(())((()))()()(()))");
    while ( !list.empty() ){
        // cout << boolalpha << validParentheses( list.front() ) << endl;
        cout << "String: " << list.front() << "\t" << longestValidParentheses(list.front()) << endl;
        list.pop_front();
    }


}