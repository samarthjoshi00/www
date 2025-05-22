#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main() {
    int i, j, k, n;
    int a[10][10], p[10][10];  // Matrices: 'a' = input, 'p' = result (path matrix)
    clrscr();	

    // Read number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Read the adjacency matrix
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);  // 1 = edge exists, 0 = no edge
        }
    }

    // Initialize the path matrix with the input matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = a[i][j];
        }
    }

    // Warshall's algorithm: compute transitive closure
    for (k = 0; k < n; k++) {              // For each intermediate node
        for (i = 0; i < n; i++) {          // For each source node
            for (j = 0; j < n; j++) {      // For each destination node
                // If a path exists from i to j through k, mark it as reachable
                if (p[i][j] == 1 || (p[i][k] == 1 && p[k][j] == 1)) {
                    p[i][j] = 1;
                }
            }
        }
    }

    // Print the transitive closure (path matrix)
    printf("The path matrix shown below:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
   getch();
}
