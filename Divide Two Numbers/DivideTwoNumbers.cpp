#include <iostream>
#include <bits/stdc++.h> 
#include <list>

// Original Solution was using division by repeated subtraction. This passed all my own tests but failed LEETCODE tests due to Time Limit Exceeded.

class Solution {
public:

    //function for Binary Addition
    u_int32_t binAddition(u_int32_t a,u_int32_t b){
        u_int32_t c; //carry
        while (b != 0) {
            //find carry and shift it left
            c = (a & b) << 1;
            //find the sum
            a=a^b;
            b=c;
        }
        return a; 
    }

    //function for Binary Subtraction
    u_int32_t binSubtraction(u_int32_t a, u_int32_t b){
        u_int32_t carry;
        //get 2's compliment of b and add in a
        b = binAddition(~b, 1); 
        while (b != 0) {
            //find carry and shift it left    
            carry = (a & b) << 1;
            //find the sum
            a = a ^ b;
            b = carry;
        }
        return a;
    }

    int divide(int dividend2, int divisor) {
        u_int32_t dividend = (u_int32_t)dividend2;
        u_int32_t divisor2 = (u_int32_t)divisor;
        if ( divisor == 0 ) {
            std::cout << "ERROR: Divide By Zero" << std::endl;
            return 0;

        }
        if ( dividend2 == -2147483648 && divisor == -1 ) return 2147483647;
        if ( dividend2 == -2147483648 && divisor == 1 ) return -2147483648;

        // int diff;
        // int sum = 0, result = 0;
        u_int32_t quotient = 0, remainder = 0;
        // for(int i = 31 ; i >= 0 ; i--)
        // {
        //     quotient <<= 1;
        //     remainder <<= 1;
        //     remainder |= (dividend & (1 << i)) >> i;

        //     if(remainder >= divisor2)
        //     {
        //         remainder = binSubtraction(remainder,divisor2);
        //         quotient |= 1;
        //     }
        //     // std::cout << "quotient = " << quotient << std::endl;
        // }
        
        if ( 0 < dividend2  && divisor < 0 ){
            if ( divisor == -2147483648 ){
                divisor2 = 2147483648;
            } else {
                divisor2 = (u_int32_t)-divisor;
            }
            
            // std::cout << "dividend = " << dividend << std::endl;
            // std::cout << "divisor2 = " << divisor2 << std::endl;
            // diff = INT_MIN - divisor;
            // while ( sum >= -dividend2 ){
            //     result++;
                
            //     if ( sum <= diff ){
            //         return 2147483647;
            //     }
            //     sum += divisor;
            // }            
            // return -result+1;
            for(int i = 31 ; i >= 0 ; i--)
            {
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (dividend & (1 << i)) >> i;

                if(remainder >= divisor2)
                {
                    remainder = binSubtraction(remainder,divisor2);
                    quotient |= 1;
                }
                // std::cout << "quotient = " << quotient << std::endl;
            }


            return (int)-quotient;
        } else if ( dividend2 < 0 && divisor < 0 ) {
            if ( dividend2 == -2147483648 ){
                dividend = 2147483648;
            } else {
                dividend = (u_int32_t)-dividend2;
            }
            if ( divisor == -2147483648 ){
                divisor2 = 2147483648;
            } else {
                divisor2 = (u_int32_t)-divisor;
            }
            // diff = INT_MAX + divisor;
            // sum = dividend;
            // while ( sum <= 0 ){
            //     result++;
            //     // std::cout << "sum = " << sum << std::endl;
            //     if ( sum > diff ){
            //         return result-1;
            //     }
            //     sum -= divisor;
            // }  
            // return result-1;
            // 
            for(int i = 31 ; i >= 0 ; i--)
            {
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (dividend & (1 << i)) >> i;

                if(remainder >= divisor2)
                {
                    remainder = binSubtraction(remainder,divisor2);
                    quotient |= 1;
                }
                // std::cout << "quotient = " << quotient << std::endl;
            }
            return quotient;
        } else if ( dividend2 < 0 &&  0 < divisor ){
            
            if ( dividend2 == -2147483648 ){
                dividend = 2147483648;
            } else {
                dividend = (u_int32_t)-dividend2;
            }
            // diff = INT_MIN + divisor;
            // while ( sum >= dividend ){
            //     if ( sum < diff ){
            //         return -result;
            //     }
            //     result++;
            //     sum -= divisor;
            // } 
            // return -result+1;

            for(int i = 31 ; i >= 0 ; i--)
            {
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (dividend & (1 << i)) >> i;

                if(remainder >= divisor2)
                {
                    remainder = binSubtraction(remainder,divisor2);
                    quotient |= 1;
                }
                // std::cout << "quotient = " << quotient << std::endl;
            }

            return -quotient;
            // diff = INT_MIN + divisor;
            //     if ( sum < diff ){
            //         return -result;
            //     }
            // while


        } else {
            // diff = INT_MAX - divisor;            
            // while ( sum <= dividend ){
            //     if ( sum > diff ){
            //         return result;
            //     }           
            //     result++;
            //     sum += divisor;
            // }
            // return result - 1;

            // std::cout << "dividend = " << dividend << std::endl;
            // std::cout << "divisor2 = " << divisor2 << std::endl;

            for(int i = 31 ; i >= 0 ; i--){
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (dividend & (1 << i)) >> i;

                if(remainder >= divisor2)
                {
                    remainder = binSubtraction(remainder,divisor2);
                    quotient |= 1;
                }
                // std::cout << "quotient = " << quotient << std::endl;
                // std::cout << "remainder = " << remainder << std::endl;
            }
            return quotient;
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