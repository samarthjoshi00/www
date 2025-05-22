#include <conio.h>
#include <stdio.h>

void main() {
  int i, a[20], n, sum = 0, count = 0;
  clrscr();

  count += 1;
  printf("\nEnter the size of the array: ");
  scanf("%d", &n);
  count += 1;

  printf("\nEnter the array elements: ");
  for (i = 0; i < n; i++) {
    count += 1;
    scanf("%d", &a[i]);
  }
  count += 1;
  for (i = 0; i < n; i++) {
    count += 1;
    sum += a[i];
    count += 1;
  }
  count += 1;
  printf("\nSum of the array elements is %d and count value is %d", sum, count);
  getch();
}
