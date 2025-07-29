#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main() {
    FILE *fp;
    int *arr, *prefixSum;
    int n, num;
    fp = fopen("input2.txt", "r");
    if (fp == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }
    fscanf(fp, "%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    prefixSum = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    printf("Prefix Sum Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    free(arr);
    free(prefixSum);
    return 0;
}