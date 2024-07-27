#include <stdio.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void breakAffineCipher(int C1, int C2, int P1, int P2) {
    int a_inv, a, b;

    
    a = ((C1 - C2) * modInverse(P1 - P2, 26)) % 26;
    if (a < 0) a += 26;
    b = (C1 - a * P1) % 26;
    if (b < 0) b += 26;

    printf("a = %d, b = %d\n", a, b);
}

int main() {
    int C1 = 1; 
    int C2 = 20; 
    int P1 = 4; 
    int P2 = 19; 

    breakAffineCipher(C1, C2, P1, P2);

    return 0;
}

