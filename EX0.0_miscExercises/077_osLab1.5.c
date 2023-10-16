#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t childPID1, childPID2;
    int i =0;
    //create the first child
    childPID1 = fork();

    if (childPID1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (childPID1 == 0) {
        //executed by the first child
        printf("I'm the first child. My PID is %d, My parent's PID is %d\n", getpid(), getppid());
        printf("I can count with data from my parent: ");
        for (i=0;i<=10;i++) {
            printf("%d ",i);
        }
        printf("\n..........\n");
        exit(0); //exit the first child
    }

    //create the second child 
    childPID2 = fork();

    if (childPID2 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (childPID2 == 0) {
        //executed by the second child
        sleep(3);
        printf("I'm the second child. My PID is %d, My parent's PID is %d\n", getpid(), getppid());
        printf("I can also count with data from my parent. I count by 5's ");
        for (i=0;i<=30;i+=5) {
            printf("%d ",i);
        }
        printf("\n..........\n");
        exit(0); //exit the first child
        exit(0); //exit the second child
    }
    
    //executed by the parent process
    int status1, status2; //store the exit statuses of the child processes
    waitpid(childPID1, &status1, 0);   //wait for both children to finish and retrieve their exit statuses
    waitpid(childPID2, &status2, 0);
    sleep(2);
    printf("I'm the parent. My PID is %d\n", getpid());
    printf("My first child's PID is %d\n",childPID1);
    printf("My second child's PID is %d\n",childPID2);

    return 0;
}

