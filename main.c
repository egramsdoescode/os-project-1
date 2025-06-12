#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
The chgDir function changes the user's current working directory to the provided directory

Input: 
        char* path: a string, the path of the directory to change to
        char* currDir: a string, the user's current working directory
    
Output: there is no return value, but changes the user's current working directory to 
        the directory provided in the path argument, then sets currDir to the new directory
*/
void chgDir(char* path, char* currDir){
    if(chdir(path) == -1){
        printf("Errorr: cannot change directory\n");
        return;
    }
    if((getcwd(currDir, 1000)) == NULL){
        perror("getcwd() error");
    }
    setenv("pwd", currDir, 1); 
}

/*
The showpid function prints the last five processes that were ran

Input: 
        int idList[]: a pointer to an array of integers, the process ID's of the last five processes 
    
Output: 
        there is no return value, but prints the last five processes to standard output 
*/
void showpid(int idList[]){
    int i = 0;
    for(i=0; i<5; i++){
        printf("%d\n", idList[i]);
    }
    return;
}

int main() {
    char str[1000];
    char currDir[1000];
    char* tokenArr;
    char* argumentList[10];
    pid_t pid;
    int status;
    char* command;

    int idList[5];
    int a = 0;

    int i;
    for (i = 0; i < 10; i++) {
        argumentList[i] = (char*)malloc(sizeof(char) * 81);
        argumentList[i] = NULL;
    }

    if (getcwd(currDir, 1000) == NULL) {
        perror("getcwd() error");
    }

    while (1) {
        for (i = 0; i < sizeof(argumentList) / sizeof(char*); i++) {
            if (argumentList[i] != NULL) {
                free(argumentList[i]);
                argumentList[i] = NULL;
            }
        }

        printf("\033[38;2;203;166;247m%s$ ", currDir);

        if (fgets(str, 1000, stdin) != NULL) {
            str[strcspn(str, "\n")] = '\0';
        }

        tokenArr = strtok(str, " ");
        i = 0;
        while (tokenArr != NULL) {
            if (i == 0) {
                command = strdup(tokenArr);
            }
            argumentList[i] = strdup(tokenArr);
            tokenArr = strtok(NULL, " ");
            i++;
        }

        if (strncmp(str, "exit", 4) == 0) {
            // exit
            printf("EXITING!\n");
            break;
        } else if (strncmp(str, "cd", 2) == 0) {
            // cd
            if(argumentList[1] != NULL) {
                chgDir(argumentList[1], currDir);
            } else {
                printf("Error: No directory specified\n");
            }
        } else if (strncmp(str, "showpid", 7) == 0) {
            // showpid
            showpid(idList);
        } else {
            if ((pid = fork()) == 0) {
                int execStatus = execvp(command, argumentList);
                if (execStatus == -1) {
                    printf("Error: Command could not be executed\n");
                    exit(1);
                }
                kill(pid, SIGTERM);
            } else {
                if (a == 5) {
                    a = 0;
                }
                idList[a] = pid;
                a++;
                waitpid(pid, &status, 0);
            }
        }
    }
}
