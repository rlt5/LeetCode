// 468. Validate IP Address
// Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
// IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
// Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
// IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
// However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
// Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

// Note: You may assume there is no extra space or special characters in the input string.

// Example 1:
// Input: "172.16.254.1"
// Output: "IPv4"
// Explanation: This is a valid IPv4 address, return "IPv4".

// Example 2:
// Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
// Output: "IPv6"
// Explanation: This is a valid IPv6 address, return "IPv6".

// Example 3:
// Input: "256.256.256.256"
// Output: "Neither"
// Explanation: This is neither a IPv4 address nor a IPv6 address.

#include <iostream>
#include <iomanip>
#include <vector>
#include <regex> 
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        regex IPv4( string("((1[0-9][0-9])|([1-9][0-9])|([0-9])|(2[0-4][0-9])|(2[5][0-5])).") +
                    string("((1[0-9][0-9])|([1-9][0-9])|([0-9])|(2[0-4][0-9])|(2[5][0-5])).") +
                    string("((1[0-9][0-9])|([1-9][0-9])|([0-9])|(2[0-4][0-9])|(2[5][0-5])).") +
                    string("((1[0-9][0-9])|([1-9][0-9])|([0-9])|(2[0-4][0-9])|(2[5][0-5]))") );
                    
        if (regex_match(IP,IPv4))
            return "IPv4";
        
        regex IPv6( string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4}):")+
                    string("([0-9a-fA-F]{1,4})"));
        
        if (regex_match(IP,IPv6))
            return "IPv6";
        
        regex test("[0-9]");
        if (regex_match(IP,test))
            return "test passed";
            
        return "Neither";
    }
};

int main(){
    Solution s;
    vector<pair<string,string>> testCasesIPv4;
    testCasesIPv4.push_back(pair<string,string>("172.16.254.1","IPv4"));
    testCasesIPv4.push_back(pair<string,string>("0.0.0.0","IPv4"));
    testCasesIPv4.push_back(pair<string,string>("255.255.255.255","IPv4"));

    testCasesIPv4.push_back(pair<string,string>("019.12.013.1","Neither"));
    testCasesIPv4.push_back(pair<string,string>("19.12.013.01","Neither"));
    testCasesIPv4.push_back(pair<string,string>("19.12.013.256","Neither"));
    testCasesIPv4.push_back(pair<string,string>("19.12.013.","Neither"));
    testCasesIPv4.push_back(pair<string,string>("1.0.1.","Neither"));
    testCasesIPv4.push_back(pair<string,string>("...","Neither"));
    testCasesIPv4.push_back(pair<string,string>("256.256.256.256","Neither"));

    vector<pair<string,string>> testCasesIPv6;
    testCasesIPv6.push_back(pair<string,string>("1234:1234:1234:1234:1234:1234:1234:1234","IPv6"));
    testCasesIPv6.push_back(pair<string,string>("2001:0db8:85a3:0:0:8A2E:0370:7334","IPv6"));
    testCasesIPv6.push_back(pair<string,string>("2001:0db8:85a3::8A2E:0370:7334","Neither"));
    testCasesIPv6.push_back(pair<string,string>("02001:0db8:85a3:0000:0000:8a2e:0370:7334","Neither"));

    cout << "IPv4 TESTS" << endl;
    for ( pair<string,string> testCase : testCasesIPv4 ){
        cout << setw(15) << testCase.first << " " << setw(8) << testCase.second << " " << s.validIPAddress(testCase.first);;
        if ( s.validIPAddress(testCase.first).compare(testCase.second) == 0 ) cout << "     PASSED" << endl;
        else cout << "     FAILED------" << endl;
    }
    
    cout << endl;
    cout << "IPv6 TESTS" << endl;
    for ( pair<string,string> testCase : testCasesIPv6 ){
        cout << setw(40) << testCase.first << " " << setw(8) << testCase.second << " " << s.validIPAddress(testCase.first);;
        if ( s.validIPAddress(testCase.first).compare(testCase.second) == 0 ) cout << "     PASSED" << endl;
        else cout << "     FAILED------" << endl;
    }


}