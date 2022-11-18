#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_work(void *data) {
    char *string = (char *)data;
    
    while (1) {
        printf("%s", string);
    }
}

int main(int argc, char **argv) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_work, "Hello\n");

    while (1) {
        printf("there!\n");
    }

    return EXIT_SUCCESS;
}
