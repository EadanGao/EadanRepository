#include <stdio.h>
#include <math.h>
#include <string.h>

void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

void bubbleSorting(char string[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(string[j] > string[j + 1]) swap(&string[j], &string[j + 1]);
        }
    }
    return ;
}


char HextoBinInvtoHex(char hex){
    int Binary[16][5] = {{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}, 
                         {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, 
                         {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1}, 
                         {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
    int invBin[5];
    int pointer = (int) (hex - 48);
    if(pointer > 9){
        if(pointer < 43) pointer -= 7;
        else pointer -= 39;
    }

    for(int i = 0; i < 4; i++) invBin[i] = Binary[pointer][3 - i];

    //bin to hex
    int dec =  0;
    for(int i = 0; i < 4; i++) dec += pow(2, 3 - i) * invBin[i];

    if(dec > 9) return (char) dec + 55;
    return (char) dec + 48;
}

int main(){

    char hex[101], str[101], even[101], odd[101];
    int odd_n = 0, even_n = 0;
    scanf("%s%s", hex, str);
    strcat(hex, str);

    int length = strlen(hex);
    for(int i = 0; i < length; i++){
        if(i % 2) even[even_n++] = hex[i];
        else odd[odd_n++] = hex[i];
    }

    bubbleSorting(odd, odd_n);
    bubbleSorting(even, even_n);

    even_n = 0, odd_n = 0;

    for(int i = 0; i < length; i++){
        if(i % 2) hex[i] = even[even_n++];
        else hex[i] = odd[odd_n++];
    }

    for(int i = 0; i < length; i++){
        if((hex[i] >= 48 && hex[i] <= 57) || (hex[i] >= 65 && hex[i] <= 70) || (hex[i] >= 97 && hex[i] <= 102)) printf("%c", HextoBinInvtoHex(hex[i]));
        else printf("%c", hex[i]);
        
    }

    // printf("%c", HextoBinInvtoHex('U'));

    return 0;
}