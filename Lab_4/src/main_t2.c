#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int schr(const char * str, const char ch);

int main(int argc, char *argv[]){
    FILE *fin = NULL, *fout = NULL;
    
    if (argc != 3) {
        fprintf(stderr, "\n!!! Используйте: %s <file.txt> <count num>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        fprintf(stderr, "Не удается открыть %s файл.\n", argv[1]);
        exit(EXIT_FAILURE);
	}
	
	/* Create file output .t2 */
	int i = schr(argv[1], '.');
    char *newfile = malloc(sizeof(char) * strlen(argv[1]));
    strcpy(newfile, argv[1]);
    strcpy((newfile + i), ".t2\0");

    fout = fopen(newfile, "w+");
    if (fout == NULL) {
        fprintf(stderr, "Не удается открыть %s файл.\n", newfile);
        exit(EXIT_FAILURE);
	}
	
	/* Search spaces */
    int countArg = atoi(argv[2]) + 1;
	char ch = ' ';
	
	while ((ch = fgetc(fin)) != EOF) {
	    if ((ch == ' ') && countArg) {
	        countArg -= 1;
	        fputc(' ', fout);
	    }
	    fputc(ch, fout);
	}
	(countArg == 0) ? printf("\nAll %d spaces added\n", atoi(argv[2])) : printf("\nEndOfFile %d spaces did't add\n", countArg);
    fclose(fin);
    fclose(fout);
	exit(EXIT_SUCCESS);
}

int schr(const char * str, const char ch) {
    int i, idx = -1;
    for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
    if (str[i] == ch) idx = i;
    return idx;
}
