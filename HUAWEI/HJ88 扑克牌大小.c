#include <stdio.h>
#include <string.h>

char convert(char a){
    switch(a){
        case '1': return '9' + 1;
        case 'J': return '9' + 2;
        case 'Q': return '9' + 3;
        case 'K': return '9' + 4;
        case 'A': return '9' + 5;
        case '2': return '9' + 6;
        case 'j': return '9' + 7;
        // case 'J': return '9' + 8;
        default: return a;
    }
}

int larger(char a, char b){
    a = convert(a);
    b = convert(b);
    if(a > b) return 1;
    else return 0;
}

int main() {
    char a[30], b[30];
    scanf("%[^\n]%*c", a);
    int lena = strlen(a), lenb;

    int i = 0;
    while(a[i] != '-') i++;
    strcpy(b, a + i + 1);
    lenb = lena - i - 1, lena = i + 1;
    a[i] = '\0';

    //type
    int spacea = 0, spaceb = 0;
    for(int i = 0; i < lena; i++){
        if(a[i] == ' ') spacea++;
    }
    for(int i = 0; i < lenb; i++){
        if(b[i] == ' ') spaceb++;
    }
    

    // joker?
    if((a[0] == 'j' && spacea == 1) || (b[0] == 'j' && spaceb == 1)){
        printf("joker JOKER\n");
        return 0;
    }

    //bomb
    if(spacea == 3 && spaceb == 3){
        if(larger(a[0], b[0])) printf("%s\n", a);
        else printf("%s", b);
        return 0;
    }
    else if(spacea == 3){
        printf("%s\n", a);
        return 0;
    }
    else if(spaceb == 3){
        printf("%s\n", b);
        return 0;
    }

    //straight
    if(spacea == 4 && spaceb == 4){
        if(larger(a[0], b[0])) printf("%s\n", a);
        else printf("%s", b);
        return 0;
    }

    if(spacea == 2 && spaceb == 2){
        if(larger(a[0], b[0])) printf("%s\n", a);
        else printf("%s", b);
        return 0;
    }

    if(spacea == 1 && spaceb == 1){
        if(larger(a[0], b[0])) printf("%s\n", a);
        else printf("%s", b);
        return 0;
    }

    if(spacea == 0 && spaceb == 0){
        if((a[0] == 'J' && lena > 1) || (b[0] == 'J' && lenb > 1)){
            printf("JOKER\n");
            return 0;
        }
        if(a[0] == 'j' || b[0] == 'j'){
            printf("joker\n");
            return 0;
        }
        if(larger(a[0], b[0])) printf("%s\n", a);
        else printf("%s", b);
        return 0;
    }

    printf("ERROR\n"); 
    return 0;
}