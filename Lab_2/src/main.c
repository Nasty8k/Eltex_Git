#include "sort.h"

int main(int argc, char *argv[]){
    int i, j;
    int c_str = 0;
    char **p_arr_str, *string = malloc(MAXLEN * sizeof(char));
	OUT* output = malloc(sizeof(OUT));
	
	printf("Count of strings: ");
	scanf("%d", &c_str);
	p_arr_str =(char**) malloc(c_str * sizeof(char*));
	
	printf("\nInput strings:\n");
	while(getc(stdin) != '\n');
    
	for (i = 0; i < c_str; ++i) {    	    
 	    j =  inp_str(string, MAXLEN);
      	p_arr_str[i] =(char*) malloc(j * sizeof(char));
      	strcpy(p_arr_str[i], string);
      	printf("%d)[%s] len(%ld)\n", i+1, p_arr_str[i], strlen(p_arr_str[i]));
    }
    
    printf("\nChoose sort var:\n");
    scanf("%d", &j);
    switch(j) {
      case 1:
          printf("\nSort--(Length raise)--Var 1\n>> OUT:\n");
          var1(p_arr_str, c_str, output);
          printf("Replaces %d, minlen %d\n", output->first, output->second);
          break;
      case 2:
          printf("\nSort--(Length decrease)--Var 2\n>> OUT:\n");
          var2(p_arr_str, c_str, output);
          printf("Replaces %d, maxlen %d\n", output->first, output->second);
          break;
      case 3:
          printf("\nSort--(ABC raise)--Var 3\n>> OUT:\n");
          var3(p_arr_str, c_str, output);
          printf("Replaces %d, char %c\n", output->first, output->second);
          break;
      case 4:
          printf("\nSort--(ABC decrease)--Var 4\n>> OUT:\n");
          var4(p_arr_str, c_str, output);
          printf("Replaces %d, len 1 str %d\n", output->first, output->second);
          break;
      case 5:
          printf("\nSort--(Space raise)--Var 5\n>> OUT:\n");
          var5(p_arr_str, c_str, output);
          printf("Replaces %d, last str start %c\n", output->first, output->second);
          break;
      case 6:
          printf("\nSort--(Space decrease)--Var 6\n>> OUT:\n");
          var6(p_arr_str, c_str, output);
          printf("Replaces %d, max words %d\n", output->first, output->second);
          break;
      case 7:
          printf("\nSort--(Numeric raise)--Var 7\n>> OUT:\n");
          var7(p_arr_str, c_str, output);
          printf("Replaces %d, second num in [%s]\n", output->first, output->string);
          break;
      case 8:
          printf("\nSort--(Numeric decrease)--Var 8\n>> OUT:\n");
          var8(p_arr_str, c_str, output);
          printf("Replaces %d, nums total %d\n", output->first, output->second);
          break;
      case 9:
          printf("\nSort--(First word raise)--Var 9\n>> OUT:\n");
          var9(p_arr_str, c_str, output);
          printf("Replaces %d, max word length [%s][%d]\n", output->first, output->string, output->second);
          break;
      case 10:
          printf("\nSort--(First word decrease)--Var 10\n>> OUT:\n");
          var10(p_arr_str, c_str, output);
          printf("Min length word %d, count words in first str [%d]\n", output->first, output->second);
          break;
      default:
          printf("No exist\n");
          return 0;
    }
    
    for (i = 0; i < c_str; ++i) {
        out_str(p_arr_str[i], strlen(p_arr_str[i]), i+1);
    }
    
	exit(EXIT_SUCCESS);
}
