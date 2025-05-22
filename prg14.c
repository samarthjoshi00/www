#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 10  

int s[MAX_SIZE], x[MAX_SIZE],d; 

// Recursive function to generate subsets whose sum is equal to 'd'
void sumofSub(int m, int k, int r) {
    int i;
    x[k] = 1;  // Include s[k] in the subset

    if (m + s[k] == d) {
        // Subset sum matches target, print it
        printf("Subset: ");
        for (i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", s[i]);
        }
        printf("\n");
    } else {
        if (m + s[k] + s[k + 1] <= d) {
            sumofSub(m + s[k], k + 1, r - s[k]);
        }

        // Explore alternative path with s[k] excluded
        if ((m + r - s[k] >= d) && (m + s[k + 1] <= d)) {
            x[k] = 0;  // Exclude s[k] from the subset
            sumofSub(m, k + 1, r - s[k]);
        }
    }
}

void main() {
    int n, sum = 0;  // n = number of elements, sum = total sum of set
    int i;
    clrscr();

    printf("Enter the size of the set (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the set in increasing order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        sum += s[i];  // Compute total sum
    }

    printf("Enter the value of d: ");
    scanf("%d", &d);

    // Check feasibility before starting
    if (sum < d || s[0] > d) {
        printf("No subset possible.\n");
    } else {
        sumofSub(0, 0, sum);  // Begin backtracking from index 0
    }
 getch();
}
