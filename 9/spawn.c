#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    char *dcc = "/usr/local/bin/dcc";
    // char buf[1000];
    // snprintf(buf, 1000, "%s %s", dcc, argv[1]);

    // /usr/local/bin/dcc diary.c;sh
    // system(buf);
    
    pid_t pid;
    extern char **environ;
    char *my_argv[] = {dcc, argv[1], NULL};

    if (posix_spawn(&pid, dcc, NULL, NULL, my_argv, environ)) {
        perror(dcc);
        return EXIT_FAILURE;
    }

    // do other stuff

    int exit_status;
    if (waitpid(pid, &exit_status, 0) == -1) {
        perror("waitpid");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

