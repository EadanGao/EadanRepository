#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int v[4] = {0};
int n[4];
int num[4];

int ConverttoNumber(char a);
int game24point(int *a, int sum, char *operator, int operator_pointer);
void printCard(int n);

int main() {
    char a[4][6];
    scanf("%s%s%s%s", a[0], a[1], a[2], a[3]);
    for(int i = 0; i < 4; i++){
        if(a[i][1] == 'o' || a[i][1] == 'O'){
            printf("ERROR\n");
            return 0;
        }
    }

    
    for(int i = 0; i < 4; i++) n[i] = ConverttoNumber(a[i][0]);
    char operator[4];

    if(game24point(n, 0, operator, -1)) return 0;
    printf("NONE\n");

    return 0;
}


int ConverttoNumber(char a){
    switch(a){
        case 'A': return 1;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case '1': return 10;
        default: return a - '0';
    }
    return 0;
}

void printCard(int n){
    switch(n){
        case 1: printf("A"); return ;
        case 11: printf("J"); return ;
        case 12: printf("Q"); return ;
        case 13: printf("K"); return ;
        default: printf("%d", n); return;
    }
    return ;
}



int game24point(int *a, int sum, char *operator, int pointer){
    int operator_pointer = pointer;
    if(sum == 24 && operator_pointer == 3){
        for(int k = 0; k < 3; k++){
            printCard(num[k]);
            printf("%c", operator[k]);
        }
        printCard(num[3]);
        return 1;
    } 
    for(int i = 0; i < 4; i++){
        if(!v[i]){
            v[i] = 1;
            if(operator_pointer == -1){
                num[operator_pointer + 1] = a[i];
                if(game24point(a, sum + a[i], operator, operator_pointer + 1)) return 1;
            }
            else{
                num[operator_pointer + 1] = a[i];
                operator[operator_pointer] = '+';
                if(game24point(a, sum + a[i], operator, operator_pointer + 1)) return 1;
                operator[operator_pointer] = '-';
                if(game24point(a, sum - a[i], operator, operator_pointer + 1)) return 1;
                operator[operator_pointer] = '*';
                if(game24point(a, sum * a[i], operator, operator_pointer + 1)) return 1;
                operator[operator_pointer] = '/';
                if(game24point(a, sum / a[i], operator, operator_pointer + 1)) return 1;
            }
            v[i] = 0;
        }
        
    }
    return 0;
}


