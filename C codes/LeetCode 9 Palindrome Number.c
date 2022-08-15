#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x){
    printf("x = %d\n", x);
    if(x < 0) return false;
    if(x == 0) return true;
    int length = 0;
    char *str = (char*) malloc(10 * sizeof(char));

    while(x){
        str[length] = x % 10;
        x = x / 10;
        length++;
    }

    for(int i = length-- / 2 - 1; i >= 0; i--){
        if(str[i] != str[length - i]) return false;
    }
    return true;
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", isPalindrome(x));
    return 0;
}