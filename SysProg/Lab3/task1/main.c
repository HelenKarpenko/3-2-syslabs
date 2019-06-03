//1. Описує глобальний дескриптор файла логу.
//2. Описує функцію-обробник сигналів, прототипу
//void signal_handler( int signo, siginfo_t *si, void *
//ucontext );
//3. У функції-обробнику виконати запис у файлі логу з докладним розкриттям структури siginfo_t, яка подана на вхід.
//4. Відкриває файл логу на запис.
//5. Відмічає в ньому факт власного запуску та свій pid.
//6. Описує структуру sigaction, у якій вказує на функцію обробник.
//7. Реєструє обробник для сигналу SIGHUP із збереженням попереднього
//обробника.
//8. Переходить до нескінченного циклу із засинанням на кілька секунд та
//відмітками у файлі логу.
//9. Протестувати отриману програму, посилаючи до неї сигнали утілітою kill, та
//спостерігаючи результат у файлі логу.
//10.Пояснити отримані результати

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include <signal.h>

FILE *LOG_FILE_DESC;

void openLogFile(void);
void signalHandler(int signo, siginfo_t *si, void *ucontext);

int main()
{
    openLogFile();

    fprintf(LOG_FILE_DESC, "Process started with ID: %d\n", getpid());

    struct sigaction act = {.sa_sigaction = &signalHandler, .sa_flags = SA_SIGINFO};
    struct sigaction old_act;

    if (sigaction(SIGHUP, &act, &old_act) == -1)
    {
        fprintf(LOG_FILE_DESC, "Error while creating handler: %s\n", strerror(errno));
        fflush(LOG_FILE_DESC);
        exit(errno);
    }

    while (1)
    {
        fprintf(LOG_FILE_DESC, "Waiting...\n");
        fflush(LOG_FILE_DESC);
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}

void openLogFile()
{
    LOG_FILE_DESC = fopen("log.txt", "a+");

    if (LOG_FILE_DESC == NULL)
    {
        fprintf(stderr, "Cannot open file. Error: %s\n", strerror(errno));
        fflush(LOG_FILE_DESC);
        exit(EXIT_FAILURE);
    }
}

void signalHandler(int signo, siginfo_t *si, void *ucontext)
{
    fprintf(LOG_FILE_DESC, "Signal catched: \n");
    fprintf(LOG_FILE_DESC, "\tNumber: %d\n", si->si_signo);
    fprintf(LOG_FILE_DESC, "\tErrno: %d\n", si->si_errno);
    fprintf(LOG_FILE_DESC, "\tCode: %d\n", si->si_code);
    fprintf(LOG_FILE_DESC, "\tSender ID: %d\n", si->si_pid);
    fflush(LOG_FILE_DESC);
}