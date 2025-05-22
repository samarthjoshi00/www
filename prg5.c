#include <conio.h>
#include <stdio.h>
#include <string.h>

void main() {
    char t[20], p[20];
    int i, j, k, flag = 0, m, n;
    clrscr();

    // Input text and pattern using fgets to avoid buffer overflow
    printf("\nEnter the text: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';  // Remove newline character from fgets input

    printf("\nEnter the pattern: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = '\0';  // Remove newline character from fgets input

    n = strlen(t);
    m = strlen(p);

    // Loop to search for the pattern in the text
    for (i = 0; i <= n - m; i++) {  // Fix loop to check the last possible position
        j = 0;
        while (j < m && p[j] == t[i + j])  // Compare the characters
            j += 1;

        if (j == m) {  // Pattern is found
            flag = 1;
            k = i + 1;
            break;  // No need to continue searching once the pattern is found
        }
    }

    // Output result
    if (flag == 1)
        printf("\nPattern found at position %d\n", k);
    else
        printf("\nPattern not found in the string\n");

    getch();
}
