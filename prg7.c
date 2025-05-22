#include <conio.h>
#include <stdio.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {
  int temp[10], i;
  int left = low;      // starting index of left half of arr
  int right = mid + 1; // starting index of right half of arr
  int k = 0;           // index for temporary array

  // storing elements in the temporary array in a sorted manner
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp[k++] = arr[left++];
    } else {
      temp[k++] = arr[right++];
    }
  }

  // if elements on the left half are still left
  while (left <= mid) {
    temp[k++] = arr[left++];
  }
  // if elements on the right half are still left
  while (right <= high) {
    temp[k++] = arr[right++];
  }

  // transferring all elements from temporary to arr
  for (i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void mergeSort(int arr[], int low, int high) {
  int mid;
  if (low >= high)
    return;

  mid = (low + high) / 2;

  mergeSort(arr, low, mid);      // left half
  mergeSort(arr, mid + 1, high); // right half
  merge(arr, low, mid, high);    // merging sorted halves
}

void main() {
  int n, arr[10], i;
  clock_t start, end;
  double time_taken;

  clrscr();
  printf("Array Size (max 10): ");
  scanf("%d", &n);

  printf("\nEnter Array Elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nBefore Sorting Array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // calculate the computation time.
  start = clock();
  mergeSort(arr, 0, n - 1);
  end = clock();

  printf("\nAfter Sorting Array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\nTime Taken: %f seconds", time_taken);

  getch();
}
