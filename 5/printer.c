#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t printerControl = 0; // 0b 0000 0000

// Whether the printer is out of ink
#define NO_INK (0x1)        // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)        // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4)  // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)   // 0b 0000 1000
// Start print/scan
#define START (0x10)        // 0b 0001 0000

// 0b10 = 1 * 2 + 0 * 1
//   10 = 1 * 10 + 0 * 1
// 0x10 = 1 * 16 + 0 * 1

void out_of_ink() {
    if ((printerControl & NO_INK) != 0 ) {
        puts("Out of ink!");
    }
}

void set_colour_scan() {
    printerControl |= (COLOUR | SELECT_SCAN);
}

void toggle_print_scan() {
    // printerControl ^= SELECT_SCAN;
    // printerControl ^= SELECT_PRINT;

    printerControl ^= (SELECT_SCAN | SELECT_PRINT);
}

int main(int argc, char **argv) {
    out_of_ink();
    printerControl |= NO_INK;
    out_of_ink();

    printf("0x%04x\n", printerControl);
    set_colour_scan();
    printf("0x%04x\n", printerControl);
    toggle_print_scan();
    printf("0x%04x\n", printerControl);

    return EXIT_SUCCESS;
}

