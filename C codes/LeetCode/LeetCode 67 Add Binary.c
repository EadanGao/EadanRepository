#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a , b) (a > b ? a : b)


char * addBinary(char * a, char * b){
    int alen = strlen(a), blen = strlen(b);
    int rlen = 1 + max(alen, blen); 
    int carry = 0;
    char * rst = (char *) calloc((rlen + 1), sizeof(char));
    int l = sizeof(rst);
    rst[rlen] = '\0';

    while(alen > 0 || blen > 0 || carry != 0){
        alen--;
        blen--;
        rlen--;

        carry += alen < 0 ? 0 : a[alen] - '0';
        carry += blen < 0 ? 0 : b[blen] - '0';

        rst[rlen] = carry % 2+ '0'; 
        carry /= 2;      
    }
    if(!rst[0]) return (rst + 1);
    return rst;
}

int main(){
    char *a = "10";
    char *b = "10";
    // printf("a: %s b: %s\n", a, b);
    printf("result = %s\n", addBinary(a, b));
    return 0;
}