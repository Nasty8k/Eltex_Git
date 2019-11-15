#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LEN 15
#define FIFO "./tmp/myFIFO"
int main(int argc, char **argv) {
    
    if (argc < 2) {
        printf("Нужно: ./main  <к-во пчел> <добыча меда> <поедание меда> <время жизни сек>\n");
        exit(EXIT_FAILURE);
    }

    int    bee   = atoi(argv[1]);//пчелы - количество пчел
    int    honey = atoi(argv[2]);//пчелы - порция добычи меда
    //int    bEat  = atoi(argv[3]);//медведь - количество поедания меда
    //double bTime = atof(argv[4]);//медведь - время поедания или ожидания меда  

    printf(" Kол-во   пчел: %d  Доставка меда: %d\n", bee, honey);
    //printf(" Поедание меда: %d  Время медведя: %f\n", bEat, bTime);

    pid_t pid[bee];
    int i;
    
    if (mknod(FIFO, S_IFIFO | 0666, 0) < 0) {
           printf("write: Error mknod FIFO\n");
           exit(EXIT_FAILURE);
    }
    if (unlink(FIFO) < 0) {
        printf("read: Error unlink(FIFO)\n");
        exit(EXIT_FAILURE);
    }
     
    for (i = 0; i < bee; ++i) {
        pid[i] = fork();
        
        switch (pid[i]) {
          case -1:
            perror("fork");
            exit(EXIT_FAILURE);
          case 0:
             printf("%d) BEE ID: %d\n", i+1, getpid());
             char pid_str[LEN];
             snprintf(pid_str, 10,"%d",(int)getpid());
             execl("write_to_FIFO", pid_str, argv[2], NULL);
        }
    }
/* 
    printf("PID[%d] BEAR reading..\n", getpid());
    execl("read_from_FIFO", argv[3], argv[4], NULL);
*/
    return 0;
}
