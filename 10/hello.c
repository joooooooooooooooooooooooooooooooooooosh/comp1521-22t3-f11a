#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    printf("Hello from thread!\n");

    return (void *)42;
}

int main(void) {
    pthread_t thread_id;
    pthread_create(
        &thread_id,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    void *retval;
    if (pthread_join(thread_id, &retval)) {
        perror("pthread_join");
        return 1;
    }

    printf("thread returned %d\n", (int)retval);

    return 0;
}
