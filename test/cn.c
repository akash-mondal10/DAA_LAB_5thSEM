/*
write a c program to find to check whether the host machine is in little endian or big endian. Enter a number, print the content of each byte location and convert the Endianess of the same i.e. Little to big endian and vice versa  */
#include <stdio.h>

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    // Check endianness
    if (*(unsigned char *)&num == (num & 0xFF)) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    // Print byte content
    unsigned char *bytePtr = (unsigned char *)&num;
    printf("Byte content:\n");
    for (int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: %02X\n", i, bytePtr[i]);
    }

    // Convert endianness
    unsigned int converted = ((num & 0xFF000000) >> 24) |
                              ((num & 0x00FF0000) >> 8)  |
                              ((num & 0x0000FF00) << 8)  |
                              ((num & 0x000000FF) << 24);
    printf("Converted Endianness:\n");
    for (int i = 0; i < sizeof(converted); i++) {
        printf("Byte %d: %02X\n", i, ((unsigned char *)&converted)[i]);
    }

    return 0;
}