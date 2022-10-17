#include <stdio.h>
#include <string.h>
char a[1001], b[1001];
int map[1001][1001];

int levenshtein(int i, int j){
    if(a[i -1] == b[j - 1]) return map[i - 1][j - 1];
    int temp = map[i - 1][j - 1];
    temp = temp < map[i - 1][j] ? temp : map[i - 1][j];
    temp = temp < map[i][j - 1] ? temp : map[i][j - 1];
    return temp + 1;
}


int main(){
    scanf("%s", a);
    scanf("%s", b);
    int length1 = strlen(a);
    int length2 = strlen(b);

    for(int i = 0; i <= length1; i++) map[i][0] = i;
    for(int i = 0; i <= length2; i++) map[0][i] = i;

    for(int i = 1; i <= length1; i++){
        for(int j = 1; j <= length2; j++){
            map[i][j] = levenshtein(i, j);
        }
    }

    printf("%d", map[length1][length2]);

    return 0;
}