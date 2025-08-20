#include <stdio.h>
void printParens(int i, int j, int split[30][30], char *ch) {
    if (i == j) {
        printf("%c", (*ch)++);
        return;
    }
    printf("(");
    printParens(i, split[i][j], split, ch);
    printParens(split[i][j] + 1, j, split, ch);
    printf(")");
}

int main() {
    int matrices, i, length, j, k;
    int dims[30];
    int cost[30][30];
    int split[30][30];
    int INF = 1000000000;

    printf("Enter number of matrices: ");
    scanf("%d", &matrices);

    printf("Enter dimensions (dims[0] dims[1] ... dims[n]):\n");
    for (i = 0; i <= matrices; i++) {
        scanf("%d", &dims[i]);
    }

    for (i = 1; i <= matrices; i++) {
        cost[i][i] = 0;
    }

    for (length = 2; length <= matrices; length++) {
        for (i = 1; i <= matrices - length + 1; i++) {
            j = i + length - 1;
            cost[i][j] = INF;
            for (k = i; k < j; k++) {
                int q = cost[i][k] + cost[k+1][j] + dims[i-1] * dims[k] * dims[j];
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                    split[i][j] = k;
                }
            }
        }
    }

    char ch = 'A';
    printf("Optimal Parenthesization: ");
    printParens(1, matrices, split, &ch);
    printf("\nMinimum number of multiplications: %d\n", cost[1][matrices]);

    return 0;
}

