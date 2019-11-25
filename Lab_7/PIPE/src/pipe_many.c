#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
 
#define MAXLEN 16
int flag = 1;
void my_handler(int nsig){ 
    printf("\nKilled!\n");
    flag = 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
         printf("Нужно: ./prog <к-во пчел> <добыча меда> <поедание меда> <время сек>\n");
        exit(-1);
    }
    char honey[MAXLEN] = {0};
    char div = '-', buf, number[MAXLEN]={0};//number index!
    char *p = number;
    int indx = 0, found = 0, len = 0;
    
    int bee   = atoi(argv[1]);//пчелы - количество пчел
    strcpy(honey, argv[2]);   //пчелы - порция добычи меда
    len = strlen(honey);
    honey[len] = div; honey[len + 1] = '\0';

    int bEat  = atoi(argv[3]);//медведь - количество поедания меда
    double bTime = atof(argv[4]);//медведь - время поедания или ожидания меда  

    int pid[bee], fd[bee][2], i, k = 0; //работа с потоками
    clock_t start, end;
    double seconds = 0.0;
    
    for (i = 0; i < bee; ++i) {
        pipe(fd[i]);
        pid[i] = fork();
        srand(getpid());
		
        if (-1 == pid[i]) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (0 == pid[i]) {
			/* процесс-потомок закрывает доступный для чтения конец канала 0*/
            close(fd[i][0]);
            while (flag) {
                signal(SIGUSR1, my_handler);
    			write(fd[i][1], honey, strlen(honey));
    			printf("[%d]Пчела[%d] спит\n", getpid(), i);
                sleep((rand() % 5) + 2);
      			printf("[%d]Пчела[%d] проснулась\n", getpid(), i);
            }
            close(fd[i][1]);
            printf("\nВЫХОД [%d]\n", i);
            exit(EXIT_SUCCESS);
        }
    }

    printf("Медведь: поиск меда \n");
    start = clock();
    k = 0; // первый номер пчелы
    found = 0;
    
    while (seconds < bTime){
        close(fd[k][1]);    
        while ((read(fd[k][0], &buf, 1) > 0) && buf != div) { /* Чтение успешно */
            *(p+indx) = buf; indx++;                        
        }
        indx = 0;
        found += atoi(p);
        if (found < bEat) {
            printf("  Мало!(%d/%d)[From Bee %d]\n", found, bEat, k);
            end = clock();//Проверка времени
            seconds += (double)(end - start) / CLOCKS_PER_SEC;
        } else {
            printf("  Я кушаю! от [%d]\n", k);
            sleep(bTime); 
            seconds = 0.0;
            found = 0;
            start = clock();
        }
        end = clock();//Проверка времени
        seconds += (double)(end - start) / CLOCKS_PER_SEC;
        
        if (seconds > bTime) {
           printf("  Винни пух ушел\n");
           flag = 0;
           exit(EXIT_SUCCESS);
        }
        printf("Время прошло %f/%f", seconds, bTime);
        k += 1;
        if (k == bee) k = 0;
        
    }
   
    return 0;
}

