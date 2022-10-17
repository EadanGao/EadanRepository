#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char coord[10001];
    scanf("%[^\n]%*c", coord);
    int dot[2] = {0};
    int i = 0, length = strlen(coord);

    while(i < length){
        int pointer = i;
        while(coord[pointer] != ';') pointer++;
        if(pointer - i > 3 || pointer - i < 2){
            i = pointer + 1;
            continue;
        }
        if(coord[i + 1] > 57 || coord[i + 1] < 48){
            while(coord[i++] != ';');
            continue;
        }
        if(pointer - i == 3){
            if(coord[i + 2] > 57 || coord[i + 2] < 48){
                i = pointer + 1;
                continue;
            }
            
        }

        char direction  = coord[i++];
        int distance = 0;
        while(coord[pointer] != ';') pointer++;

        while(i < pointer){
            distance += (coord[i] - 48) * pow(10, pointer - i - 1);
            i++;
        }
        i++;

        switch(direction){
            case 'A': dot[0] -= distance; continue;
            case 'D': dot[0] += distance; continue;
            case 'W': dot[1] += distance; continue;
            case 'S': dot[1] -= distance; continue;
        }
    }

    printf("%d,%d\n", dot[0], dot[1]);

    return 0;
}