#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int *arr;
    int n, num;
    fp = fopen("input.txt", "r");
    fscanf(fp,"%d",&n);
    arr= (int*)malloc(n * sizeof(int));
    int min = INT_MAX, second_min = INT_MAX;
    int max = INT_MIN, second_max = INT_MIN;

    
    if (fp == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }
    while (fscanf(fp, "%d", &num) == 1) {
        arr[n++] = num;
    }
    fclose(fp);

    if (n < 2) {
        printf("Not enough elements.\n");
        return 1;
    }

    // Find min, second min, max, second max
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            second_min = min;
            min = arr[i];
        } else if (arr[i] > min && arr[i] < second_min) {
            second_min = arr[i];
        }

        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] < max && arr[i] > second_max) {
            second_max = arr[i];
        }
    }

    if (second_min == INT_MAX)
        printf("No second shortest (all elements equal or only one unique value).\n");
    else
        printf("Second shortest: %d\n", second_min);

    if (second_max == INT_MIN)
        printf("No second largest (all elements equal or only one unique value).\n");
    else
        printf("Second largest: %d\n", second_max);

    return 0;
}