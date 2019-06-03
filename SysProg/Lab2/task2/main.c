#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void closeAllDescriptors(void);
void redirectStdStreamsToNull(void);
void writeToFileProcessInfo(FILE *file);

int main(int argc, char **argv)
{
    FILE *logFile = fopen("log.txt", "a+t");
    if (logFile == NULL)
    {
        fprintf(stderr, "Cannot open file. Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(logFile, "Program started\n");
    fflush(logFile);

    const pid_t childPid = fork();
    if (childPid < 0)
    {
        fprintf(logFile, "Error while forking: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (childPid > 0)
    {
        fprintf(logFile, "Forked child process with ID %d\n", childPid);
        fflush(logFile);
        exit(EXIT_SUCCESS);
    }

    const pid_t sid = setsid();
    if (sid < 0)
    {
        fprintf(stderr, "Error while set sid: %d\n", sid);
        exit(EXIT_FAILURE);
    }

    if (chdir("/") < 0)
    {
        fprintf(stderr, "Error while chdir to \"/\"\n");
        exit(EXIT_FAILURE);
    }

    closeAllDescriptors();
    redirectStdStreamsToNull();

    logFile = fopen("log.txt", "a+t");

    if (logFile == NULL)
    {
        fprintf(stderr, "Cannot open file. Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(logFile, "Daemon started\n");

    writeToFileProcessInfo(logFile);

    while (1)
    {
        sleep(1);
        fprintf(logFile, "Logging info...\n");
        fflush(logFile);
    }

    fclose(logFile);
    exit(EXIT_SUCCESS);
}

void closeAllDescriptors()
{
    int max = getdtablesize();
    for (int i = 0; i < max; i++) {
        close(i);
    }
}

void redirectStdStreamsToNull()
{
    freopen("/dev/null", "r", stdin);
    freopen("/dev/null", "w", stdout);
    freopen("/dev/null", "w", stderr);
}

void writeToFileProcessInfo(FILE *file)
{
    fprintf(file, "Process ID: %d\n", getpid());
    fprintf(file, "Process parent ID: %d\n", getppid());
    fprintf(file, "Process session ID: %d\n", getsid(0));
    fprintf(file, "Process group ID: %d\n", getpgrp());
    fprintf(file, "Process user ID: %d\n", getuid());
}

