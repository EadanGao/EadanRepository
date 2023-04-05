#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char * s){
    int length = strlen(s);
    int i = length - 1;
    while(s[i] == ' ') i--, length--;
    while(i >0 && s[i - 1] != ' ') i--;
    return length - i;
}

int main(){
    char *s = "fly me  to  the moon";
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}