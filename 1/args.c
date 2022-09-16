#include <stdio.h>

#define ZERO 0

int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);
    printf("&argv=%p\n", &argv);
    printf("argv=%p\n", argv);
    for (int i = ZERO; i < argc; i++) {
        printf("argv[%d]=%p\n", i, argv[i]);
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}
