#include <conio.h>
#include <stdio.h>
int i, j, a, b, v, u, n, ne = 1;
int min, mincost = 0, c[10][10], vis[10] = {0};

void main() {
  clrscr();

  printf("Enter number of nodes: \n");
  scanf("%d", &n);

  printf("Enter the adjacency matrix: \n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &c[i][j]);
      if (c[i][j] == 0) {
        c[i][j] = 999; // Treat 0 as no edge
      }
    }
  }
  vis[1] = 1; // since we are storing matrix as 1 based index.
  printf("\n");

  while (ne < n) {
    min = 999;
    for (i = 1; i <= n; i++) {
      if (vis[i]) {
        for (j = 1; j <= n; j++) {
          if (c[i][j] < min && !vis[j]) {
            min = c[i][j];
            a = u = i;
            b = v = j;
          }
        }
      }
    }
    if (!vis[u] || !vis[v]) {
      printf("\nEdge %d: (%d %d) cost:%d\n", ne++, a, b, min);
      mincost += min;
      vis[b] = 1;
    }
    c[a][b] = c[b][a] = 999;
  } // end of while

  printf("\nMinimum cost = %d\n", mincost);
  getch();
}
