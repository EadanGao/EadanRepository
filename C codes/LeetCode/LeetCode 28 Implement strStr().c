#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    if(needle == NULL) return 0;

    int length_h = strlen(haystack);
    int length_n = strlen(needle);
    int i_h = 0, i_n = 0;

    while(i_h < length_h - length_n + 1){
        if(haystack[i_h] == needle[i_n]){
            while(i_n < length_n && haystack[i_h + i_n] == needle[i_n]) i_n++;
            if(i_n == length_n) return i_h;
            i_n = 0;
        }
        i_h++;
    }
    return -1;
}

int main(){
    char * haystack = "mississippi";
    char * needle = "issip";
    printf("%d\n", strStr(haystack, needle));
    return 0;
}
