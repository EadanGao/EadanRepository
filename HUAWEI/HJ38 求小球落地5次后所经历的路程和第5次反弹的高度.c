#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float height = (float) n, path = 0;
    for(int i = 0; i < 5; i++){
        path += height;
        height /= 2;
        path += height;
    }

    printf("%g\n%g", path - height, height);
    return 0;
}