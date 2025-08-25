#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0; // Global variable to count comparisons

// Merge function
void merge(int arr[], int left, int mid, int right, int ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (ascending ? (L[i] <= R[j]) : (L[i] >= R[j]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge sort function
void mergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

// Generate random numbers into input.txt
void generateRandomNumbers(int n) {
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
}

// Sort numbers from file
void sortFromFile(int ascending) {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error: Cannot open input.txt\n");
        return;
    }

    int *arr = NULL, n = 0, num;
    while (fscanf(fin, "%d", &num) == 1) {
        arr = realloc(arr, (n + 1) * sizeof(int));
        arr[n++] = num;
    }
    fclose(fin);

    if (n == 0) {
        printf("No numbers found in input.txt\n");
        free(arr);
        return;
    }

    comparisons = 0; // reset comparison counter
    clock_t start = clock();

    mergeSort(arr, 0, n - 1, ascending);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (ascending) {
        FILE *fasc = fopen("ascending.txt", "w");
        for (int i = 0; i < n; i++) fprintf(fasc, "%d ", arr[i]);
        fclose(fasc);
        printf("Ascending order stored in ascending.txt\n");
        fprintf("caomparisons made: %lld\n", comparisons);
        frpintf("Time taken: %.6f seconds\n", time_taken);
    } else {
        FILE *fdesc = fopen("desc.txt", "w");
        for (int i = 0; i < n; i++) fprintf(fdesc, "%d ", arr[i]);
        fclose(fdesc);
        printf("Descending order stored in desc.txt\n");
    }

    printf("Comparisons made: %lld\n", comparisons);
    printf("Time taken: %.6f seconds\n", time_taken);

    free(arr);
}

int main() {
    int n, choice;

    printf("Enter the number of random elements: ");
    scanf("%d", &n);
    generateRandomNumbers(n);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Sort in Ascending order\n");
        printf("2. Sort in Descending order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortFromFile(1); // ascending
                break;
            case 2:
                sortFromFile(0); // descending
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
