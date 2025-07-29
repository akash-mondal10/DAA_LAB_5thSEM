#include <stdio.h>
#include <stdlib.h>
void decToBin(int n, FILE *out) {
    if (n > 1)
        decToBin(n / 2, out);
    fprintf(out, "%d", n % 2);
}

int main() {
    FILE *fin, *fout;
    int n, count = 0, num;

    fin = fopen("input1.txt", "r");
    if (!fin) {
        printf("Cannot open input file.\n");
        return 1;
    }
    fout = fopen("output1.txt", "w");
    if (!fout) {
        printf("Cannot open output file.\n");
        fclose(fin);
        return 1;
    }
    
    fscanf(fin,"%d", &n);

    while (count < n && fscanf(fin, "%d", &num) == 1) {
        decToBin(num, fout);
        fprintf(fout, "\n");
        count++;
    }

    fclose(fin);
    fclose(fout);

    printf("Conversion complete. Check output.txt for results.\n");
    return 0;
}