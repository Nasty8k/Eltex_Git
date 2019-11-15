#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "./tmp/myFIFO"
#define MAXBUFF 64

void my_handler(int nsig){ 
    printf("\nKilled!\n");
    exit(EXIT_SUCCESS);    
}

int main(int argc, char **argv)
{
    int beeN  = atoi(argv[0]);
    int honey = atoi(argv[1]), len = strlen(argv[1]);
    char *buff = malloc(sizeof(char) * MAXBUFF), dif = '-';
    int  fd_FIFO, i;
    if (beeN > 0 && honey > 0) {
        strcpy(buff, argv[1]);
    } else {
        beeN  = atoi(argv[1]);
        honey = atoi(argv[2]);
        len = strlen(argv[2]);
        strcpy(buff, argv[2]);
        if (beeN <= 0 || honey <= 0) {
            exit(EXIT_FAILURE);
        } 
    }
    if ((len + 1) >= MAXBUFF) {
        printf("writeToFIFO: Error MAXBUFF\n");
        exit(EXIT_FAILURE);
    }
    buff[len] = dif;
    len += 1;
//    buff[len+1] = '\0';
    
    printf("\nWrite ARGS [%d][%s](%d)\n", beeN, buff,len);
   
        
    if ((fd_FIFO = open(FIFO, O_WRONLY)) < 0) {
           printf("write: Error open FIFO\n");
           exit(EXIT_FAILURE);    
    }
    
    printf ("Writing str[%s] from Bee[%d] -> FIFO\n", buff, beeN);

    while (1) {
        if (write(fd_FIFO, buff, len) != len) {
            printf("write: Error write\n");
            close(fd_FIFO);
            free(buff);
            exit(EXIT_FAILURE);
        }
        signal(SIGUSR1, my_handler);
        printf ("Writing %d%c -> FIFO\n", beeN, dif);
        sleep((rand() % 5) + 2);
    }

    return 0;
}
