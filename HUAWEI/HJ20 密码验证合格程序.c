#include <stdio.h>
#include <string.h>

int commonSubString(char password[], int length){
        for(int i = 0; i < length - 3; i++){
                for(int j = i + 3; j < length; j++){
                    if(password[i] == password[j] && password[i + 1] == password[j + 1] && password[i + 2] == password[j + 2]) return 0;
            }
    }
    return 1;
}

int main() {
    char password[102];

    while(scanf("%s", password) != EOF){

        int length = strlen(password);
        if(length <= 8){
            printf("NG\n");
            continue;
        }

        int dig = 0, cap = 0, low = 0, sym = 0;
        for(int i = 0; i < length; i++){
            if(password[i] <= 'z' && password[i] >= 'a') low = 1;
            else if(password[i] <= 'Z' && password[i] >= 'A') cap = 1;
            else if(password[i] <= '9' && password[i] >= '0') dig = 1;
            else sym = 1;
        }

        if(low + cap + dig + sym < 3){
            printf("NG\n");
            continue;
        }


        if(!commonSubString(password, length)){
            
            printf("NG\n");
            continue;
        }
        printf("OK\n");
        
    }
    return 0;
}