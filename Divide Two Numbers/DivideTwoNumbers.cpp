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

    int divide(int dividend, int divisor) {
        u_int32_t unsignedDividend = (u_int32_t)dividend;
        u_int32_t unsignedDivisor = (u_int32_t)divisor;
        if ( divisor == 0 ) {
            std::cout << "ERROR: Divide By Zero" << std::endl;
            return 0;

        }
        if ( dividend == -2147483648 && divisor == -1 ) return 2147483647;
        if ( dividend == -2147483648 && divisor == 1 ) return -2147483648;
        u_int32_t quotient = 0, remainder = 0;
        
        if ( 0 < dividend  && divisor < 0 ){
            if ( divisor == -2147483648 ){
                unsignedDivisor = 2147483648;
            } else {
                unsignedDivisor = (u_int32_t)-divisor;
            }
            for(int i = 31 ; i >= 0 ; i--)
            {
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (unsignedDividend & (1 << i)) >> i;

                if(remainder >= unsignedDivisor)
                {
                    remainder = binSubtraction(remainder,unsignedDivisor);
                    quotient |= 1;
                }
            }
            return (int)-quotient;
        } else if ( dividend < 0 && divisor < 0 ) {
            if ( dividend == -2147483648 ){
                unsignedDividend = 2147483648;
            } else {
                unsignedDividend = (u_int32_t)-dividend;
            }
            if ( divisor == -2147483648 ){
                unsignedDivisor = 2147483648;
            } else {
                unsignedDivisor = (u_int32_t)-divisor;
            }
            for(int i = 31 ; i >= 0 ; i--)
            {
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (unsignedDividend & (1 << i)) >> i;
                if(remainder >= unsignedDivisor)
                {
                    remainder = binSubtraction(remainder,unsignedDivisor);
                    quotient |= 1;
                }
            }
            return quotient;
        } else if ( dividend < 0 &&  0 < divisor ){
            
            if ( dividend == -2147483648 ){
                unsignedDividend = 2147483648;
            } else {
                unsignedDividend = (u_int32_t)-dividend;
            }
            for(int i = 31 ; i >= 0 ; i--)
            {
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (unsignedDividend & (1 << i)) >> i;

                if(remainder >= unsignedDivisor)
                {
                    remainder = binSubtraction(remainder,unsignedDivisor);
                    quotient |= 1;
                }
            }

            return -quotient;
        } else {
            for(int i = 31 ; i >= 0 ; i--){
                quotient <<= 1;
                remainder <<= 1;
                remainder |= (unsignedDividend & (1 << i)) >> i;

                if(remainder >= unsignedDivisor)
                {
                    remainder = binSubtraction(remainder,unsignedDivisor);
                    quotient |= 1;
                }

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
    list.push_back({2147483647,1});
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
        dividend = testCase[0];
        divisor = testCase[1];
        int result = sol->divide(dividend,divisor);
        if ( result != dividend/divisor ){
            std::cout << "Dividend: " << std::setw(11) << std::right << dividend << ", Divisor: " << std::setw(10) << std::right << divisor << ", Output: " << std::setw(11) << std::right << result << ", Expected: " << std::setw(11) << std::right << dividend/divisor << " FAILED <---" <<std::endl;
            return 0;
        } else {
            std::cout << "Dividend: " << std::setw(11) << std::right << dividend << ", Divisor: " << std::setw(10) << std::right << divisor << ", Output: " << std::setw(11) << std::right << result << ", Expected: " << std::setw(11) << std::right << dividend/divisor <<  " PASSED" << std::endl;
        }
    }

}