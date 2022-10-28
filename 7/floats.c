#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    float f = 1.5;
    uint32_t u = 0b00110111010100000101000001010000;
    printf("%x %x", f, u);
    return EXIT_SUCCESS;
}

