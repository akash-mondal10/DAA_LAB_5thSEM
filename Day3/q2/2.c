#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(int n) {
    FILE *fp = fopen("input.txt", "w");
    if (!fp) {
        printf("Error creating input.txt\n");
        exit(1);
    }
    fprintf(fp, "%d\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 100; // Random number between 0 and 999
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    generate_random_numbers(n); // Create and write to input.txt first

    FILE *fp = fopen("input.txt", "r"); // Now open the file to read
    if (!fp) {
        printf("Error opening input.txt\n");
        return 1;
    }

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

    // Print to console
    // printf("Sorted array:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // printf("Number of comparisons: %d\n", comparisons);
    // printf("Time taken: %f seconds\n", time_taken);

    // Write to output.txt
    FILE *out = fopen("output_500.txt", "a");
    if (!out) {
        printf("Error opening output.txt\n");
        free(arr);
        return 1;
    }

    fprintf(out, "n = %d\n", n);
    // fprintf(out, "Sorted array: ");
    // for (int i = 0; i < n; i++) {
    //     fprintf(out, "%d ", arr[i]);
    // }
    fprintf(out, "\nComparisons: %d\n", comparisons);
    fprintf(out, "Time taken: %f seconds\n\n", time_taken);

    fclose(out);
    free(arr);
    return 0;
}
