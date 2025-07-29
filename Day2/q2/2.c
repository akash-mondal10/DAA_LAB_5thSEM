#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    FILE *fin, *fout;
    int a, b, result;

    fin = fopen("input2.txt", "r");
    fout = fopen("output2.txt", "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fin, "%d %d", &a, &b) == 2) {
        result = gcd(a, b);
        fprintf(fout, "GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
