#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void DectoBin_32(char *bin, int long dec){ // 32 bits
    int i = 31;
    while(dec > 0){
        bin[i--] = dec % 2;
        dec /= 2;
    }
    return ;
}

void DectoBin_8(char *bin, int long dec){ // 8 bits
    int i = 7;
    while(dec > 0){
        bin[i--] = dec % 2;
        dec /= 2;
    }
    return ;
}

void BintoDec(char *bin, int long *dec, int bits){
    *dec = 0;
    int i = bits - 1;
    while(i> -1){
        *dec += bin[i] * pow(2, bits - 1 - i);
        i--;
    }
    return ;
}

int main() {
    int long a1, a2, a3, a4;
    int long a5;
    scanf("%ld.%ld.%ld.%ld", &a1, &a2, &a3, &a4);
    scanf("%ld", &a5);

    char * bin = (char *) malloc(32 * sizeof(char));
    memset(bin, 0, 32 * sizeof(char));
    
    DectoBin_8(bin, a1);
    DectoBin_8(bin + 8, a2);
    DectoBin_8(bin + 16, a3);
    DectoBin_8(bin + 24, a4);

    BintoDec(bin, &a1, 32);
    printf("%ld\n", a1);

    memset(bin, 0, 32 * sizeof(char));
    DectoBin_32(bin, a5);

    BintoDec(bin, &a1, 8);
    BintoDec(bin + 8, &a2, 8);
    BintoDec(bin + 16, &a3, 8);
    BintoDec(bin + 24, &a4, 8);

    printf("%ld.%ld.%ld.%ld\n", a1, a2, a3, a4);

    free(bin);

    return 0;
}