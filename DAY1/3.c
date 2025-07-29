#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE], freq[MAX_SIZE] = {0};
    int n = 0, i, j, count = 0, maxCount = 0, mostRepeating;
    char filename[100];

    printf("Enter the filename to read integers from: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read integers from file
    while (fscanf(fp, "%d", &arr[n]) == 1 && n < MAX_SIZE) {
        n++;
    }
    fclose(fp);

    for (i = 0; i < n; i++) {
        if (freq[i] == -1)
            continue;
        int dup = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                dup++;
                freq[j] = -1; // Mark as counted
            }
        }
        freq[i] = dup;
        if (dup > 1)
            count++;
        if (dup > maxCount) {
            maxCount = dup;
            mostRepeating = arr[i];
        }
    }

    printf("Total number of duplicate elements: %d\n", count);
    printf("Most repeating element: %d (repeats %d times)\n", mostRepeating, maxCount);

    return 0;
}