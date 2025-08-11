#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Error opening input.txt\n");
        return 1;
    }

    FILE *out = fopen("output_200.txt", "a");
    if (!out) {
        printf("Error opening output.txt\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    int comparisons = 0;
    clock_t start = clock();

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("Sorted array:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // printf("Number of comparisons: %d\n", comparisons);
    // printf("Time taken: %f seconds\n", time_taken);

    fprintf(out, "Sorted array: ");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d ", arr[i]);
    }
    fprintf(out, "n = %d\n", n);
    fprintf(out, "\nComparisons: %d\n", comparisons);
    fprintf(out, "Time taken: %f seconds\n\n", time_taken);

    free(arr);
    return 0;
}