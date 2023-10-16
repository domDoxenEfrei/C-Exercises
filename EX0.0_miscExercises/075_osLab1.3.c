#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t childPID;

    // Create a child process
    childPID = fork();

    if (childPID < 0) {
        perror("Fork failed");
        exit(1);
    } else if (childPID == 0) {
        // This code will be executed by the child process
        printf("I'm the child. My PID is %d, My parent's PID is %d\n", getpid(), getppid());
    } else {
        // This code will be executed by the parent process
        int status; // Store the child process's exit status

        // Wait for the child to finish
        wait(&status);

        printf("I'm the parent. My PID is %d, My child's PID is %d\n", getpid(), childPID);
    }

    return 0;
}
