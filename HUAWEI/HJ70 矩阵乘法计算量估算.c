#include <stdio.h>
#include <string.h>

int pointer = 0;
int matrix[26][2] = {0};

int compute(char *equation, int rc[][2], int index){
    int len = strlen(equation);
    int cnt = 0;
    
    int i = pointer;
    
    int j = index;
    
    while(i < len){
        if(equation[i] == '('){
            pointer = i + 1;
            cnt += compute(equation, rc, j);
            i = pointer;
            j++;
        }
        if(equation[i] >= 'A' && equation[i] <= 'Z'){
            matrix[j][0] = rc[equation[i] - 'A'][0];
            matrix[j][1] = rc[equation[i] - 'A'][1];
            j++;
            i++;
        }
        if(equation[i] == ')'){
            pointer = i + 1;
            break;
        }
    }

    for(int k = index; k < j - 1; k++){
        cnt += matrix[k][0] * matrix[k][1] * matrix[k + 1][1];
        matrix[k + 1][0] = matrix[k][0];
    }
    
    matrix[index][0] = matrix[j - 1][0], matrix[index][1] = matrix[j - 1][1];

    for(int k = index + 1; k < j ; k++){
        matrix[k][0] = 0;
        matrix[k][1] = 0;
    }
    return cnt;

}

int main() {
    int n;
    scanf("%d", &n);
    int rc[n][2]; // 0 row, 1 column
    for(int i = 0; i < n; i++) scanf("%d%d", &rc[i][0], &rc[i][1]);
    char equation[10];
    scanf("%s", equation);

    int cnt = compute(equation, rc, 0);
    printf("%d", cnt);


    return 0;
}