#include <stdio.h>
#include <string.h>

void encoder(char * string){
    int length = strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] >= 48 && string[i] < 57){
            printf("%c", (char) string[i] + 1); 
            continue;
        } 
        if(string[i] == 57){
            printf("0"); 
            continue;
        }  
        if(string[i] >= 65 && string[i] < 90){
            printf("%c", (char) string[i] + 33);  
            continue;
        } 
        if(string[i] == 90){
            printf("a"); 
            continue;
        } 
        if(string[i] >= 97 && string[i] < 122){
            printf("%c", (char) string[i] - 31); 
            continue;
        } 
        if(string[i] == 122){
            printf("A"); 
            continue;
        } 
        printf("%c", string[i]);
    }
    printf("\n");
    return ;
}


void decoder(char * string){
    int length = strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] > 48 && string[i] <= 57){
            printf("%c", (char) string[i] - 1);
            continue;
        } 
        if(string[i] == 48){
            printf("9"); 
            continue;
        }  
        if(string[i] > 65 && string[i] <= 90){
            printf("%c", (char) string[i] + 31);  
            continue;
        } 
        if(string[i] == 65){
            printf("z"); 
            continue;
        } 
        if(string[i] > 97 && string[i] <= 122){
            printf("%c", (char) string[i] - 33); 
            continue;
        } 
        if(string[i] == 97){
            printf("Z"); 
            continue;
        } 
        printf("%c", string[i]);
    }
    printf("\n");
    return ;
}

int main() {
    char string[1001];
    scanf("%s", string);
    encoder(string);

    scanf("%s", string);
    decoder(string);
    // printf("%s\n", string);


    return 0;
}