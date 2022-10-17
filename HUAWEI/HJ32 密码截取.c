#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int Palindrome(char * string){
    int len = strlen(string);

    if(len == 1) return 1;
    int i = 0, j = len - 1, same = 0;

    while(j > 0){

        while((string[i] != string[j]) && j > 0) j--;
        while((string[i + same] == string[j - same]) && (i + same <= j - same)) same++;

        if(i + same > j - same) return j + 1;

        same = 0;
        j--;
    }
    return 0;

}

int main() {
    char * string =  (char *) malloc(2501 * sizeof(char));
    scanf("%s", string);
    int len = strlen(string);

    int longest = 0;

    for(int i = 0; i <len; i++){
        int temp =Palindrome(string + i);
        longest = max(longest, temp);
    }

    printf("%d\n", longest);  

    free(string);
    return 0;
}