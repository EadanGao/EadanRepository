#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%s", str);
    char letter[26] = {0};
    int len = strlen(str);
    for(int i = 0; i < len; i++) letter[str[i] - 'a']++;

    for(int i = 0; i < len; i++){
        if(letter[str[i] - 'a'] == 1){
            printf("%c\n", str[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;

}