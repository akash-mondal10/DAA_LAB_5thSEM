#include <stdio.h>
#include <stdlib.h>

int findpower(int base, int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent < 0)
        return 0; // Not handling negative exponents here
    int half = findpower(base, exponent / 2);
    if (exponent % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main() {
    int base, exponent;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    int result = findpower(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}