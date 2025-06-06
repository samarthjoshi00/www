
#include <conio.h>
#include <stdio.h>

int i, j, k, a, b, v, u, n, ne = 0;
int min, mincost = 0, cost[10][10], parent[10];

int find(int i) {
  while (parent[i]) {
    i = parent[i];
  }
  return i;
}

void uni(int i, int j) {
  if (i != j) {
    parent[j] = i;
  }
}

void main() {
  clrscr();

  printf("Enter number of vertices: \n");
  scanf("%d", &n);

  printf("Enter the cost matrix: \n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = 999;
    }
  }

  for (i = 1; i <= n; i++) {
    parent[i] = 0;
  }

  printf("Edges of spanning tree are: \n");
  while (ne < n - 1) {
    min = 999;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (cost[i][j] < min) {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }

    u = find(u);
    v = find(v);
    if (u != v) {
      printf("%d. edge(%d,%d) = %d\n", ++ne, a, b, min);
      mincost += min;
      uni(u, v);
    }
    cost[a][b] = cost[b][a] = 999;
  }

  printf("Minimum Cost = %d\n", mincost);
  getch();
}

