#include <stdio.h>

int minTrace;
int trace[100][2];
int maze[10][10];

void nextStep(int x, int y, int m, int n, int currentStep){
    if(x == m - 1 && y == n - 1){
        trace[currentStep][0] = x;
        trace[currentStep][1] = y;
        for(int i = 0; i <= currentStep; i++){
            printf("(%d,%d)\n", trace[i][0], trace[i][1]);
        }
        return ;

    }
    if(x >= 0 && x < m && y >= 0 && y < n && !maze[x][y]){
        trace[currentStep][0] = x;
        trace[currentStep][1] = y;
        currentStep++;
        maze[x][y] = -1;

        nextStep(x + 1, y, m, n, currentStep);
        nextStep(x - 1, y, m, n, currentStep);
        nextStep(x, y + 1, m, n, currentStep);
        nextStep(x, y - 1, m, n, currentStep);
    }
    return ;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) scanf("%d", &maze[i][j]);
    }

    int x = 0, y = 0, currentStep = 0;

   nextStep(x, y, m, n, currentStep);


    return 0;
}