#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *home = getenv("HOME");
    char *diary = "/.diary";

    int len = strlen(home) + strlen(diary) + 1;
    char *path = malloc(len);

    // option 1
    // strcpy(path, home);
    // strcat(path, diary);
    //
    // option 2
    snprintf(path, len, "%s%s", home, diary);

    printf("%s\n", path);
    return EXIT_SUCCESS;
}
