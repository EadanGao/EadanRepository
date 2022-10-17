#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    char destination[101];

    scanf("%s", str);
    scanf("%s", destination);

    int len1 = strlen(str);
    int len2 = strlen(destination);

    for(int k = 0; k < len1; k++){
        if(str[k] >= 'a' && str[k] <= 'z') str[k] -= 32;
    }
    for(int k = 0; k < len2; k++){
        if(destination[k] >= 'a' && destination[k] <= 'z') destination[k] -= 32;
    }

    int i = 0, j = 0, star = 0, starpointer = 0;
    while(i < len1 && j < len2){
        if(str[i] == destination[j]){
            i++, j++;
            if(star && i == len1) i--;
            continue;
        }
        if(str[i] == '?'){
            i++;
            j++;
            continue;
        }
        if(str[i] == '*'){
            if(i == len1 -1){
                printf("true\n");
                return 0;
            }
            star = 1;
            i++;
            starpointer = i;
            // continue;
        }
        if(str[i] != destination[j]){
            if(!star) break;
            i = starpointer;
            if(str[i] != destination[j]) j++;
        }

    }
    if(star && i == len1 - 1 && (str[i] == destination[j - 1] || str[i] == '?')) i++;
    if((len1 - i) > 0 || (len2 - j) > 0) printf("false\n");
    else printf("true\n");
    return 0;
}