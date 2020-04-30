#include <iostream>
// #include <stack>
#include <bits/stdc++.h> 
#include <string>
#include <list>

using namespace std;

bool validParentheses(string s){
    stack<char>* stk = new stack<char>();
    for (char c : s){
        if ( c == '('){
            stk->push(c);
        } else {
            if (!stk->empty()){
                stk->pop();
            } else {
                return false;
            }
        }
    }
    if ( stk->empty() ){
        return true;
    } else 
        return false;
}

int longestValidParentheses(string s){
    int length = s.length();
    int maxLength = 0;
    for (int i = 0; i < length; i++ ){
        for ( int j = i + 1; j < length; j++ ){
            if ( validParentheses(s.substr(i, j-i+1)) ){
                if ( j - i + 1 > maxLength ){
                    maxLength = j - i + 1;
                }
            }
        }
    }
    return maxLength;
}

int main(){

    list<string> list;
    list.push_back("(()");
    list.push_back(")()())");
    list.push_back("()()()");
    while ( !list.empty() ){
        // cout << boolalpha << validParentheses( list.front() ) << endl;
        cout << "String: " << list.front() << "\t" << longestValidParentheses(list.front()) << endl;
        list.pop_front();
    }


}