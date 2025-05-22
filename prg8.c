#include <conio.h>
#include <stdio.h>
#include <time.h>

int max, min;
int a[100];

void maxmin(int i, int j) {
  int max1, min1, mid;
  if (i == j)
    max = min = a[i];
  else {
    if (i == j - 1) {
      if (a[i] < a[j]) {
        max = a[j];
        min = a[i];
      } else {
        max = a[i];
        min = a[j];
      }
    } else {
      mid = (i + j) / 2;
      maxmin(i, mid);
      max1 = max;
      min1 = min;
      maxmin(mid + 1, j);
      if (max < max1)
        max = max1;
      if (min > min1)
        min = min1;
    }
  }
}

void main() {
  int i, num;
  clock_t start, end;
  double time_taken;
  clrscr();

  start = clock();
  printf("\nArray size: ");
  scanf("%d", &num);

  printf("\nEnter the numbers: ");
  for (i = 1; i <= num; i++)
    scanf("%d", &a[i]);

  max = a[1];
  min = a[1];

  maxmin(1, num);

  printf("\nminimum element in the array: %d", min);
  printf("\nMaximum element in the array: %d", max);

  end = clock();

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("\nTime taken: %f seconds", time_taken);

  getch();
}
