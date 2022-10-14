#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    uint64_t a = 5;
    size_t b;
    printf("%d\n", sizeof(a));

    printf("%d %d %d %d\n", 42, 0x2a, 052, 0b101010);

    return EXIT_SUCCESS;
}

