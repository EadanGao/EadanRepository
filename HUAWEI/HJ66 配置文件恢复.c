#include <stdio.h>
#include <string.h>

char str1[6][10] = {"reset", "reset", "board", "board", "reboot", "backplane"};
char str2[6][10] = {"", "board", "add", "delete", "backplane", "abort"};

void command_out(int val){
    switch(val){
        case 1: printf("board fault\n"); break;
        case 2: printf("where to add\n"); break;
        case 3: printf("no board at all\n"); break;
        case 4: printf("impossible\n"); break;
        case 5: printf("install first\n"); break;
        default: printf("unknown command\n"); break;
    }
    return ;
}


int main() {
    char str[21];
    while(scanf("%[^\n]%*c", str) != EOF){
        int len = strlen(str);
        if(len > 16){
            printf("unknown command\n");
            continue;
        }
        int pointer = 0, space = 0;
        for(int i = 0; i < len; i++){
            if(str[i] == ' '){
                space++;
                pointer = i + 1;
            }
        }
        if(space > 1){
            printf("unknown command\n");
            continue;
        }
        if(!space){
            if(!strncmp(str, str1[0], len)){
                printf("reset what\n");
                continue;
            }
            else{
                printf("unknown command\n");
                continue;
            }
        }
        else{
            int cnt  = 0, j = 0;
            for(int i = 1; i < 6; i++){
                if(!strncmp(str, str1[i], pointer - 1) && ! strncmp(str + pointer, str2[i], len - pointer)){
                    cnt++;
                    j = i;
                }
            }
            if(cnt == 1)  command_out(j);
            else printf("unknown command\n");
        }
        
    }
    return 0;
}