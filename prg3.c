#include <conio.h>
#include <stdio.h>
#include <time.h>

int binarySearch(int nums[], int low, int high, int target) {
  int mid;

  if (low > high)
    return -1;
  mid = (low + high) / 2;
  if (nums[mid] == target)
    return mid;
  else if (target > nums[mid])
    return binarySearch(nums, mid + 1, high, target);
  return binarySearch(nums, low, mid - 1, target);
}

void main() {
  int n, arr[10], ind, target, i;

  clock_t start, end;
  double time_taken;

  clrscr();

  printf("\nEnter the array size (max 10): ");
  scanf("%d", &n);

  printf("\nEnter the sorted array elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("\nEnter the element to search: ");
  scanf("%d", &target);

  start = clock();
  ind = binarySearch(arr, 0, n, target);
  end = clock();

  if (ind == -1)
    printf("\nTarget %d is not found in the array.", target);
  else
    printf("\nTarget %d is found at position %d", target, ind);

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\nTime taken: %f seconds", time_taken);

  getch();
}
