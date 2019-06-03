//1. Описує структуру датума, яка містить ціле значення для ідентифікатора
//процесу, ціле значення для мітки часу та строку фіксованої довжини.
//2. Реєструє обїект розподіленої пам`яті через виклик shm_open
//3. Приводить його до розміру кратного розміру структури датуму
//4. Відображае отриманий об`єкт у пам`ять через показчик на структуру датуму
//та виклик mmap
//5. Переходить до нескінченного циклу у якому:
//a. Запитуєстрокузклвіатури
//        b. Вичитує та презентує вміст структури датуму
//c. Записуєуструктурунатомістьсвійідентификаторпроцесу,поточний
//        час та отриману строку
//6. Протестувати отриману програму, запустивши два її примірники у різних
//сесїях.

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

const char SHM_NAME[] = "/sharedMemory";

typedef struct datum_s
{
    pid_t pid;
    long s;
    char message[1024];
} datum_t;

int main(int argc, char const *argv[])
{
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, S_IRWXU);
    if (shm_fd < 0)
    {
        printf("Error while opening shared memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, sizeof(datum_t)) < 0)
    {
        printf("Error while resizing shared memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    datum_t *datum = (datum_t *)mmap(NULL, sizeof(datum_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (datum == MAP_FAILED)
    {
        printf("Error while mapping shared memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    const pid_t pid = getpid();
    char str[1024];

    while (1)
    {
        scanf("%s", str);

        printf("Prev datum value:\n");
        printf("\tpid: %d\n", datum->pid);
        printf("\tseconds: %ld\n", datum->s);
        printf("\tmessage: %s\n", datum->message);

        datum->pid = pid;
        datum->s = time(0);
        strcpy(datum->message, str);
        msync(datum, sizeof(datum_t), MS_SYNC);
    }

    exit(EXIT_SUCCESS);
}
