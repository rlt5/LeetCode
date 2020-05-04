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
