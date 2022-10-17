#include <stdio.h>
#include <string.h>

int screen[4];
int n;

int cursorControl(char operator, int cursor){
    if(n <= 4){
        int last = n < 4 ? n : 4;
        if(operator == 'U'){
            if(cursor == 0) return 3;
            return cursor - 1;
        }
        if(operator == 'D'){
            if(cursor == last - 1) return 0;
            return cursor + 1;
        }
    }
    else{

        if(operator == 'U'){
            if(screen[cursor] == 1){
                for(int i = 0; i < 4; i++) screen[i] = n - 3 + i;
                return 3;
            }
            if(cursor == 0){
                int temp = screen[cursor];
                for(int i = 0; i < 4; i++) screen[i] = temp + i - 1;
                return cursor;
            }
            else return cursor - 1;
            
        }
        if(operator == 'D'){
            if(screen[cursor] == n){
                for(int i = 0; i < 4; i++) screen[i] = i + 1;
                return 0;
            }
            if(cursor == 3){
                int temp = screen[cursor];
                for(int i = 0; i < 4; i++) screen[i] = i + temp - 2;
                return cursor;
            }
            else return cursor + 1;
            
        }
    }
    return cursor;
}

int main() {
    // n = 43;
    scanf("%d", &n);
    // char operator[101] = "DUUUUUUUUUUDDDUDUDUUUDU";
    char operator[101];
    scanf("%s", operator);
    int length = strlen(operator);

    //filling screen
    if(n < 4){
        for(int i = 0; i < n; i++) screen[i] = i + 1;
    }
    else{
        for(int i = 0; i < 4; i++) screen[i] = i + 1;
    }

    int cursor = 0;
    for(int i = 0; i < length; i++){
        cursor = cursorControl(operator[i], cursor);
        // printf("%c ", operator[i]);
        // for(int i = 0; i < 4; i++) printf("%d ", screen[i]);
        // printf(" |%d\n", screen[cursor]);
    }


    for(int i = 0; i < 4; i++) printf("%d ", screen[i]);
    printf("\n%d\n", screen[cursor]);
    return 0;
}