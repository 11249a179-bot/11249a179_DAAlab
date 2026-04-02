#include <stdio.h>

#define N 3

void floyds(int b[N][N]) {
    int i, j, k;

    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (b[i][k] != 0 && b[k][j] != 0 && i != j) {
                    if (b[i][j] == 0 || b[i][k] + b[k][j] < b[i][j]) {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }

    // Print result
    printf("Shortest Path Matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");  // ? important fix
    }
}

int main() {
    int b[N][N] = {
        {0, 10, 0},
        {0, 0, 15},
        {12, 0, 0}
    };

    floyds(b);
    return 0;
}
