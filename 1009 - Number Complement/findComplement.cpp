#include <iostream>
#include <limits.h>
#include <math.h>

int bitwiseComplement(int N) {
    int i = 1;
    while (N > i) {
        i = i * 2 + 1;   
    }
    return i - N;
}
