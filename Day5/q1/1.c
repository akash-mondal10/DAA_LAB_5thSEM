#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int comparisons = 0; // Global variable to count comparisons

void merge (int arr[],int left , int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i=0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j=0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i<n1 && j<n2){
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Generate random numbers into input.txt
/*void generateRandomNumbers(int n) {
    FILE *f = fopen("input.txt", "w");
    if (!f) {
        printf("Error: Cannot open input.txt for writing\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 1000; // random number 0-999
        fprintf(f, "%d ", num);
    }
    fclose(f);
    printf("Generated %d random numbers in input.txt\n", n);
}*/

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //generateRandomNumbers(n); // Create and write to input.txt first
    FILE *fp = fopen("input.txt", "r"); // Now open the file to read
    if (!fp) {
        printf("Error opening input.txt\n");
        return 1;
    }
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
    clock_t start = clock();
    // Merge Sort
    mergeSort(arr, 0, n - 1); // Sort in ascending order
     clock_t end = clock();
     double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Sorted array:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    // printf("Number of comparisons: %d\n", comparisons);
    // printf("Time taken: %f seconds\n", time_taken);
    FILE *out = fopen("output.txt", "a");
    if (!out) {
        printf("Error opening output.txt\n");
        free(arr);
        return 1;
    }
    fprintf(out,"/n");
    fprintf (out, "number of elements: %d\n", n);
    fprintf(out, "\nNumber of comparisons for sorted array: %d\n", comparisons);
    fprintf(out, "Time taken: %f seconds\n", time_taken);
    fprintf(out, "\n");
    fclose(out);
    free(arr);
    return 0;
}