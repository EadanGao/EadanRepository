#include <stdio.h>

int main() {
    int dec;
    scanf("%d", &dec);
    int count = 0;
    while(dec >= 2){
        if(dec % 2) count++;
        dec /= 2;
    }
    if(dec % 2) count++;
    printf("%d\n", count);
    return 0;
}