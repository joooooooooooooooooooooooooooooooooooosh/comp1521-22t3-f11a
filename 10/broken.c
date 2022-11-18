#include <stdio.h>
#include <pthread.h>

int global_total = 0;

void *add_5000000_to_counter(void *data) {
    for (int i = 0; i < 5000000; i++) {
        // increment the global total by 1
        global_total++;
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}
