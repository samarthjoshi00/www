#include <conio.h>
#include <stdio.h>
#include <time.h>

int findgcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return findgcd(b, a % b);
}

void main() {
  int n1, n2, gcd;
  clock_t start, end;
  double time_taken;
  clrscr();

  start = clock();
  printf("\nRECURSION: FIND GCD OF TWO NUMBER");
  printf("\nEnter the 1st number: ");
  scanf("%d", &n1);

  printf("\nEnter the 2st number: ");
  scanf("%d", &n2);
  gcd = findgcd(n1, n2);

  printf("\nThe gcd of %d and %d is %d", n1, n2, gcd);
  end = clock();

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\nTime taken: %f seconds", time_taken);

  getch();
}
