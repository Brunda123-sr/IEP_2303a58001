#include <stdio.h>
#define MAX 30

struct Edge {
    int start, end, weight;
};

int parent[MAX];

int findSet(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = findSet(i);
    int b = findSet(j);
    parent[a] = b;
}

int main() {
    int vertices, edgesCount;
    struct Edge edgeList[MAX], temp;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edgesCount);

    // L=1, H=2, C=3, B=4, A=5
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < edgesCount; i++) {
        char uChar, vChar;
        int w;
        scanf(" %c %c %d", &uChar, &vChar, &w);

        int uNode, vNode;
        if(uChar == 'L') uNode = 1;
        if(uChar == 'H') uNode = 2;
        if(uChar == 'C') uNode = 3;
        if(uChar == 'B') uNode = 4;
        if(uChar == 'A') uNode = 5;

        if(vChar == 'L') vNode = 1;
        if(vChar == 'H') vNode = 2;
        if(vChar == 'C') vNode = 3;
        if(vChar == 'B') vNode = 4;
        if(vChar == 'A') vNode = 5;

        edgeList[i].start = uNode;
        edgeList[i].end = vNode;
        edgeList[i].weight = w;
    }

    for (i = 0; i < edgesCount - 1; i++) {
        for (j = 0; j < edgesCount - i - 1; j++) {
            if (edgeList[j].weight > edgeList[j + 1].weight) {
                temp = edgeList[j];
                edgeList[j] = edgeList[j + 1];
                edgeList[j + 1] = temp;
            }
        }
    }

    for (i = 1; i <= vertices; i++)
        parent[i] = i;

    int totalWeight = 0;
    printf("\nSelected Edges in the MST:\n");

    for (i = 0; i < edgesCount; i++) {
        int u = edgeList[i].start;
        int v = edgeList[i].end;

        if (findSet(u) != findSet(v)) {
            unionSets(u, v);
            totalWeight += edgeList[i].weight;

            char uChar, vChar;
            if (u == 1) uChar = 'L';
            if (u == 2) uChar = 'H';
            if (u == 3) uChar = 'C';
            if (u == 4) uChar = 'B';
            if (u == 5) uChar = 'A';

            if (v == 1) vChar = 'L';
            if (v == 2) vChar = 'H';
            if (v == 3) vChar = 'C';
            if (v == 4) vChar = 'B';
            if (v == 5) vChar = 'A';

            printf("%c - %c : %d\n", uChar, vChar, edgeList[i].weight);
        }
    }

    printf("\nTotal Minimum Cost = %d\n", totalWeight);
    return 0;
}

