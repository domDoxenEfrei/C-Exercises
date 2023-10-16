#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t childPID;
    int i=5;
    // Create a child process
    childPID = fork();

    if (childPID < 0) {
        perror("Fork failed");
        exit(1);
    } else if (childPID == 0) {
        // This code will be executed by the child process
        printf("I'm the child. My PID is %d, My parent's PID is %d\n", getpid(), getppid());
        printf("I can count with data from my parent: ");
        for (i=0;i<=10;i++) {
            printf("%d ",i);
        }
        printf("\n");
    } else {
        // you need to add a wait here becuase the parent and child are executing at same time

        // This code will be executed by the parent process
        int status; // Store the child process's exit status

        // Wait for the child to finish
        wait(&status);

        printf("I'm the parent. My PID is %d, My child's PID is %d\n", getpid(), childPID);
    }

    return 0;
}
