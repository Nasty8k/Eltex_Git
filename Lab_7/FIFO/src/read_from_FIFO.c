#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h> 
#include <fcntl.h>

#define DEATH printf("Винни, Винни что с тобой???")
#define FIFO "tmp/myFIFO"
#define MAXBUFF 64

int main(int argc, char **argv) {
    int bEat     = atoi(argv[0]);//медведь - количество поедания меда
    double bTime = atof(argv[1]);//медведь - время поедания или ожидания меда
    
    if (bEat <= 0 || bTime <= 0) {
        bEat  = atoi(argv[1]);
        bTime = atoi(argv[2]);
    } 
    if (bEat <= 0 || bTime <= 0) exit(EXIT_FAILURE);
    printf("\nRead ARGS [%d][%f]\n", bEat, bTime);
    
    int  fd_FIFO, n, indx = 0, foundNum = 0;
    char number[MAXBUFF] = {'0'}, *p = number;
    char chGet[2] = {'\n'};
    clock_t start, end;
    double seconds = 0.0;
    
        if ((fd_FIFO = open(FIFO, O_RDONLY)) < 0) {
        if (mknod(FIFO, S_IFIFO | 0666, 0) < 0) {
           printf("write: Error mknod FIFO\n");
           exit(EXIT_FAILURE);
        }    
    }
    sleep(2);
    indx = 0; //Перевод символов в полученное количество меда
    printf("Я начал поиски!\n", foundNum/bEat);
    start = clock();
    while ((n = read(fd_FIFO, chGet, 1)) > 0) { 
        if (chGet[0] != '-') {
            *(p+indx) = chGet[0];
            indx++; 
            if (indx >= MAXBUFF) {exit(-1);}
        } else {
            end = clock();//Проверка времени
            seconds = (double)(end - start) / CLOCKS_PER_SEC;
            if (seconds >  bTime) {
                DEATH;
                exit(EXIT_SUCCESS);
            }
            indx = 0; //Сброс для следующей порции меда
            //Суммирование взятых чисел
            foundNum += atoi(p);
            if (foundNum < bEat) {
                printf("[Мало! %d/%d]\n", foundNum, bEat);
                continue;
            } else {
                printf("Я кушаю x %d порцию!\n", foundNum/bEat);
                sleep(bTime);
                foundNum = 0;
                start = clock();
            }
        }
    }
    printf("\nТут нет никого\n");

    close(fd_FIFO);
    if (unlink(FIFO) < 0) {
        printf("read: Error unlink(FIFO)\n");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
