#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
    printf("Hello world!! (pid: %d) \n", (int) getpid());
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if(rc == 0){
        printf("Child Process: %d %d\n", (int) getpid(), rc);
    } else{
        printf("Parent process first time: %d %d\n", (int) getpid(), rc);
        int w = wait(NULL);
        printf("%d %d", rc, w);
        printf("Parent process second time: %d \n", (int) getpid());
    }
}