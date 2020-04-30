#include <iostream>
// #include <stack>
#include <bits/stdc++.h> 
#include <string>
#include <list>

using namespace std;

// bool validParentheses(string s){
//     stack<char>* stk = new stack<char>();
//     for (char c : s){
//         if ( c == '('){
//             stk->push(c);
//         } else {
//             if (!stk->empty()){
//                 stk->pop();
//             } else {
//                 return false;
//             }
//         }
//     }
//     if ( stk->empty() ){
//         return true;
//     } else 
//         return false;
// }

bool validParentheses(string s){
    int count = 0;
    for (char c : s){
        if ( c == '('){
            count++;
        } else {
            if (count){
                count--;
            } else {
                return false;
            }
        }
    }
    if ( count == 0 ){
        return true;
    } else 
        return false;
}

int longestValidParentheses(string s){
    int length = s.length();
    if (length == 0) return 0; 
    // int maxLength = 0;
    int maxLength[length];
    for ( int i = 0; i < length; i++ ){
        maxLength[i] = 0;
    }  

    int count = 0, currentMax = 0, countL = 0;
    for ( int i = 0; i < length; i++ ){
        currentMax = 0;
        count = 0;
        for ( int j = i; j < length; j++){

            if ( s[j] == '('){
                count++;
            } else {
                if ( count ){
                    count--;
                    currentMax++;
                } else {
                    currentMax = 0;
                }
            }

            if ( count == 0 ){
                if (maxLength[j] < currentMax ){
                    maxLength[j] = currentMax;
                }
            }
        }
    }

    int maxReturn = 0;
    for ( int i = 0; i < length; i++ ){
        // cout << maxLength[i] << ",";
        if ( maxReturn < maxLength[i] ){
            maxReturn = maxLength[i];
        }
    }
    // cout << "---";

    return maxReturn*2;

}


//// OLD CODE THAT IS N^3.
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