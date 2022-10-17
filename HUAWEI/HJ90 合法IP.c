#include <stdio.h>
#include <string.h>

int main() {
    char ip[50];
    scanf("%s", ip);
    int i = 0, len = strlen(ip), j = 0;
    int num[4] = {0};

    if(ip[0] == '.' || ip[len - 1] == '.'){
        printf("NO\n");
        return 0;
    }

    while(i < len){
        if(ip[i] == '.'){
            if(ip[i + 1] == '.'){
                printf("NO\n");
                return 0;
            }
            j++;
            i++;
            continue;
        }
        if(ip[i] == '0' && (ip[i + 1] >= '0' && ip[i + 1] <= '9') && (ip[i - 1] == '.' || i == 0)){
            printf("NO\n");
            return 0;
        }
        num[j] *= 10;
        num[j] += ip[i] - '0';
        i++;

    }
    if(j != 3){
        printf("NO\n");
        return 0;
    }

    for(int i = 0; i < 4; i++){
        if(num[i] >= 0 && num[i] <= 255) continue;
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}