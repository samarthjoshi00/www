#include <conio.h>
#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int n, int target) {
  int low = 0, high = n - 1, mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == target)
      return mid;
    else if (target > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

void main() {
  int n, arr[10], ind, target, i;
  clock_t start, end;
  double time_taken;

  clrscr();

  printf("\nEnter the array size: ");
  scanf("%d", &n);

  printf("\nEnter the array elements (sorted): ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("\nEnter the search element: ");
  scanf("%d", &target);

  start = clock();
  ind = binarySearch(arr, n, target);
  end = clock();

  if (ind == -1)
    printf("\nTarget %d not found in the array", target);
  else
    printf("\nTarget %d is at index %d", target, ind);

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\nTime taken: %f seconds", time_taken);

  getch();
}

