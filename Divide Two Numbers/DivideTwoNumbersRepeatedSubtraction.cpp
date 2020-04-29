#include <iostream>
#include <bits/stdc++.h> 
#include <list>

// Original Solution was using division by repeated subtraction. This passed all my own tests but failed LEETCODE tests due to Time Limit Exceeded.

class Solution {
public:

    int divide(int dividend, int divisor) {
        if ( divisor == 0 ) {
            std::cout << "ERROR: Divide By Zero" << std::endl;
            return 0;

        }
        if ( dividend == -2147483648 && divisor == -1 ) return 2147483647;
        if ( dividend == -2147483648 && divisor == 1 ) return -2147483648;

        int diff;
        int sum = 0, result = 0;

        
        if ( 0 < dividend  && divisor < 0 ){
            
            diff = INT_MIN - divisor;
            while ( sum >= -dividend ){
                result++;
                
                if ( sum <= diff ){
                    return 2147483647;
                }
                sum += divisor;
            }            
            return -result+1;

        } else if ( dividend < 0 && divisor < 0 ) {
            if ( dividend == -2147483648 ){
                dividend = 2147483648;
            } else {
                dividend = (u_int32_t)-dividend;
            }
            if ( divisor == -2147483648 ){
                divisor = 2147483648;
            } else {
                divisor = (u_int32_t)-divisor;
            }
            diff = INT_MAX + divisor;
            sum = dividend;
            while ( sum <= 0 ){
                result++;
                // std::cout << "sum = " << sum << std::endl;
                if ( sum > diff ){
                    return result-1;
                }
                sum -= divisor;
            }  
            return -result+1;

        } else if ( dividend < 0 &&  0 < divisor ){
            
            if ( dividend == -2147483648 ){
                dividend = 2147483648;
            } else {
                dividend = (u_int32_t)-dividend;
            }
            diff = INT_MIN + divisor;
            while ( sum >= dividend ){
                if ( sum < diff ){
                    return -result;
                }
                result++;
                sum -= divisor;
            } 
            return result-1;

        } else {
            diff = INT_MAX - divisor;            
            while ( sum <= dividend ){
                if ( sum > diff ){
                    return result;
                }           
                result++;
                sum += divisor;
            }
            return result - 1;

        }
    }
};

int main(){
    Solution* sol = new Solution();
    std::list< std::vector< int > > list;
    list.push_back({2147483647,2147483647});
    list.push_back({1,2147483647});
    // list.push_back({2147483647,1});
    list.push_back({10,3});
    list.push_back({7,-3});
    list.push_back({-2147483648,1});
    list.push_back({-2147483648,2});
    list.push_back({-1,1});
    list.push_back({-1,-1});
    list.push_back({1040040164,163207087});

    
    int dividend;
    int divisor;
    int x[] = {0, 0};
    for (auto &testCase : list ){
        // std::cout << "dividened = " << testCase[0] << std::endl;
        // std::cout << "divisor = " << testCase[1] << std::endl << std::endl;
        dividend = testCase[0];
        divisor = testCase[1];
        int result = sol->divide(dividend,divisor);
        if ( result != dividend/divisor ){
            std::cout << "Dividend: " << std::setw(11) << std::right << dividend << ", Divisor: " << std::setw(10) << std::right << divisor << ", Output: " << std::setw(11) << std::right << result << ", Expected: " << std::setw(11) << std::right << dividend/divisor << " FAILED <---" <<std::endl;
            // std::cout << "FAILED: Divided: " << std::setw(10) << std::right << dividend << ", Divisor: " << std::setw(10) << std::right << divisor << std::endl;
            // std::cout << "Output: " << result << std::endl;
            // std::cout << "Expected: " << dividend/divisor << std::endl;
            return 0;
        } else {
            std::cout << "Dividend: " << std::setw(11) << std::right << dividend << ", Divisor: " << std::setw(10) << std::right << divisor << ", Output: " << std::setw(11) << std::right << result << ", Expected: " << std::setw(11) << std::right << dividend/divisor <<  " PASSED" << std::endl;
        }
    }

    // int y = -1;
    // std::cout <<"y = " << (u_int32_t)y-4294967294 << std::endl;
    // for (int i = 0; i < 10; i++ ){
    //     y = y >> i;
    //     std::cout << i << ": y = " << y << std::endl;
    // }

    // int result = sol->divide(dividend,divisor);
    // if ( sol->divide(dividend,divisor) != dividend/divisor ){
    // std::cout << "FAILED: Divided = " << dividend << ", Divisor = " << divisor << std::endl;
    // std::cout << "Output: " << result << std::endl;
    // std::cout << "Expected: " << dividend/divisor << std::endl;
    // } else {
    //     std::cout << "PASSED: Divided = " << dividend << ", Divisor = " << divisor << ", Output: " << result << ", Expected: " << dividend/divisor << std::endl;
    // }

    // for ( int dividend = INT_MIN; dividend <= INT_MAX; dividend++ ){
    //     std::cout << "Dividend: " << dividend << std::endl;
    //     for ( int divisor = INT_MIN; divisor < 0 ; divisor++){
    //         if ( divisor % 1000000 == 0 ) std::cout << "divisor: " << divisor << std::endl;
    //         int result = sol->divide(dividend,divisor);
    //         if ( sol->divide(dividend,divisor) != dividend/divisor ){
    //             std::cout << "FAILED: Divided = " << dividend << ", Divisor = " << divisor << std::endl;
    //             std::cout << "Output: " << result << std::endl;
    //             std::cout << "Expected: " << dividend/divisor << std::endl;
    //             return 0;
    //         } else {
    //             // std::cout << "PASSED: Divided = " << dividend << ", Divisor = " << divisor << ", Output: " << result << ", Expected: " << dividend/divisor << std::endl;
    //         }
    //     }
    //     for ( int divisor = 1; divisor <= INT_MAX; divisor++){
    //         int result = sol->divide(dividend,divisor);
    //         if ( result != dividend/divisor ){
    //             std::cout << "FAILED: Divided = " << dividend << ", Divisor = " << divisor << std::endl;
    //             std::cout << "Output: " << result << std::endl;
    //             std::cout << "Expected: " << dividend/divisor << std::endl;
    //             return 0;
    //         } else {
    //             std::cout << "PASSED: Divided = " << dividend << ", Divisor = " << divisor << ", Output: " << result << ", Expected: " << dividend/divisor << std::endl;
    //         }
    //     }
    // }


}