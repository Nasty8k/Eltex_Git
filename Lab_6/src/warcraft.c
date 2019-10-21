#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //fork

#define RESET "\033[0m"
#define CYAN  "\033[1;36m"
#define YELLOW "\033[1;33m"

#define BAG 1  /*Это максимальное число вместимости багажа юнита*/

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("\nЗапуск: ./warcraft <Число юнитов> <Золото в шахте>\n");
        exit(-1);
    }
    
    int i, status, stat, time, bag, restart;
    int units = atoi(argv[1]), gold = atoi(argv[2]);
    int *pid, *res;
    
    pid = malloc(sizeof(int) * units);
    res = malloc(sizeof(int) * units);
    if (pid == NULL || res == NULL) { 
        fprintf(stderr, "Malloc\n");
        exit(-1);
    }
    /*расчет минимального количества повторов*/
    restart = gold / (units * BAG) + 1;
    printf("Необходимое число походов = %s%d%s\n", CYAN, restart-1, RESET);
    while (--restart) {
        /*работа юнитов*/
        for (i = 0; i < units; ++i) {
            pid[i] = fork();
            srand(getpid());

            switch (pid[i]) {
                case -1:
                    perror("fork");
                    exit(1);
                case 0:          
                    bag = BAG;
                    time =(rand() % 5) + 2;
                    sleep(time);
                    printf(" %s%d%s: я взял[%d], шел(%d). ВЕРНУЛСЯ в лагерь!\n", CYAN, i, RESET, bag, time);
                    exit(bag);
            }
        }
        /*лагерь*/
        for (i = 0; i < units; ++i) {
            status = waitpid(pid[i], &stat, 0);
            if (pid[i] == status) {
                bag = WEXITSTATUS(stat);
                printf("%sЛагерь%s: С возращением, %d, [%d]\n", CYAN, RESET, i, bag);
                gold -= bag;
                res[i] += bag;
            }
        }
        printf("%sGOLD%s остаток: %d\n*Походов осталось %d\n", YELLOW, RESET, gold, restart-1);
    }
    /*обработка случая что золота мало, а юнитов много*/
    if (gold) {
        int need = 1;
        while (gold > need * BAG) need += 1;
        printf("Лагерь: В поход отправляются только %s%d из %d%s юнитов\n", CYAN, need, units, RESET);
        for (i = 0; i < need; ++i) {
            pid[i] = fork();
            srand(getpid());

            switch (pid[i]) {
                case -1:
                    perror("fork");
                    exit(1);
                case 0:          
                    (i == 0) ? (bag = gold - ((need-1) * BAG)) : (bag = BAG);
                    time =(rand() % 5) + 2;
                    sleep(time);
                    printf(" %s%d%s: я взял[%d] шел(%d), ВЕРНУЛСЯ в лагерь!\n", CYAN, i, RESET, bag, time);
                    exit(bag);
            }
              
            status = waitpid(pid[i], &stat, 0);
            bag = WEXITSTATUS(stat);
            printf("%sЛагерь:%s Это была последния добыча [%d] у юнита {%d}\n", CYAN, RESET, bag, i);
            res[i] += bag;
            gold -= bag;
        }
    }
    printf("\n%sGOLD = %d%s\n", YELLOW, gold, RESET);
    for (i = 0; i < units; ++i)
        printf("> Result%s{%d}%s[%d]%s\n", CYAN, i, YELLOW, res[i], RESET);

    free(pid);
    free(res);
    return 0;
}
