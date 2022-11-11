#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
    // open file z, create if doesn't exist
    // write stuff to it
    char *file = "z";
    FILE *f = fopen(file, "w");
    if (f == NULL) {
        perror(file);
        return EXIT_FAILURE;
    }

    char *text = "some text";
    if (fwrite(text, strlen(text), 1, f) == 0) {
        perror(file);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

