// 476. Number Complement

// Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.
 
// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
// Constraints:

// The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
// num >= 1
// You could assume no leading zero bit in the integer’s binary representation.
// This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

#include <iostream>
#include <limits.h>
#include <math.h>

void itob(int x, char *buf)
{
unsigned char *ptr = (unsigned char *)&x;
int pos = 0;
for (int i = sizeof(int) - 1; i >= 0; i--)
    for (int j = CHAR_BIT - 1; j >= 0; j--)
    buf[pos++] = '0' + !!(ptr[i] & 1U << j);
buf[pos] = '\0';
}

int findComplement(int num) {
    if ( num == 0 ){
        return 1;
    }
    int count = 0;
    while ( count < 32 && num > 0 ) {
        num = num << 1;
        count++;
    }
    uint32_t num2 = num;
    num2 = ~num2;
    num2 = num2 >> count;
    return num2;
}

int main(){
    int numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1111};
    for ( int number:numbers){
        char x[32];
        itob(number,x);
        std::cout << "input:  " << number << "\t" << x << std::endl;
        itob(findComplement(number),x);
        std::cout << "output: " << findComplement(number) << "\t" << x << std::endl << std::endl;
    }

}