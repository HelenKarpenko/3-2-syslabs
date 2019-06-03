#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void printProcessInfo(char *processType);

int main(int argc, char const *argv[])
{
    const pid_t childPid = fork();

    if (childPid == 0)  // if in child process
    {
        printProcessInfo("👶 child");
        sleep(2);
        printf("[👶 child] Exiting\n");
        return 0;
    }
    else                // if in parent process
    {
        printProcessInfo("🧔 parent");

        if(childPid == -1)
        {
            printf("[🧔 parent] Error while forking: %s\n", strerror(errno));
            return -1;
        }
        else
        {
            printf("[🧔 parent] Forked child ID: %d\n", childPid);
            printf("[🧔 parent] Waiting for child process\n");

            int status;
            if (wait(&status) == -1)
            {
                printf("[🧔 parent] Error while waiting for child process: %s\n", strerror(errno));
                return -1;
            }
            else
            {
                if (WIFEXITED(status))
                {
                    printf("[🧔 parent] Child process exited with status %d\n", WEXITSTATUS(status));
                }
                else
                {
                    printf("[🧔 parent] Child process was stopped by unknown reason\n");
                }
            }
        }
    }

    return 0;
}



void printProcessInfo(char *processType)
{
    printf("[%s] Process ID: %d\n", processType, getpid());
    printf("[%s] Process parent ID: %d\n", processType, getppid());
    printf("[%s] Process session ID: %d\n", processType, getsid(0));
    printf("[%s] Process group ID: %d\n", processType, getpgrp());
    printf("[%s] Process user ID: %d\n", processType, getuid());
}

