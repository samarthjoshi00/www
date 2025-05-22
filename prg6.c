#include <conio.h>
#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high) {
  int pivot = arr[low], temp;
  int i = low, j = high;

  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }

    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;
  return j;
}

void quickSort(int arr[], int low, int high) {
  int pIndex;
  if (low < high) {
    pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
  }
}

void main() {
  int n, i, arr[10];
  clock_t start, end;
  double time_taken;
  clrscr();

  printf("Array Size (max 10): ");
  scanf("%d", &n);

  printf("Array Elements: \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Before Sorting Array: \n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  start = clock();
  quickSort(arr, 0, n - 1);
  end = clock();

  printf("After Sorting Array: \n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time Taken: %f seconds\n", time_taken);

  getch();
}
