#include <conio.h>
#include <stdio.h>

#define MAX_ITEMS 50

void main() {
  float weight[MAX_ITEMS], profit[MAX_ITEMS], ratio[MAX_ITEMS], totalValue = 0;
  float temp, capacity;
  int n, i, j;
  clrscr();

  printf("Enter the number of items (up to %d): ", MAX_ITEMS);
  scanf("%d", &n);

  if (n <= 0 || n > MAX_ITEMS) {
    printf("Invalid number of items.\n");
    return;
  }

  printf("Enter weight and profit for each item:\n");
  for (i = 0; i < n; i++) {
    printf("Item %d: ", i + 1);
    scanf("%f %f", &weight[i], &profit[i]);
    if (weight[i] <= 0 || profit[i] < 0) {
      printf("Invalid input. Weight must be positive and profit must be "
             "non-negative.\n");
      return;
    }
    ratio[i] = profit[i] / weight[i];
  }

  printf("Enter the capacity of Knapsack: ");
  scanf("%f", &capacity);

  if (capacity <= 0) {
    printf("Invalid capacity. Capacity must be positive.\n");
    return;
  }

  for (i = 0; i < n; i++) {
    if (weight[i] <= capacity) {
      totalValue += profit[i];
      capacity -= weight[i];
    } else {
      totalValue += (ratio[i] * capacity);
      break;
    }
  }

  printf("The maximum profit is %f\n", totalValue);
  getch();
}
