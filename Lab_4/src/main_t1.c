#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int schr(const char * str, const char ch);
void toFileOut(FILE *fin, long int *start, long int *end, FILE *fout, int spaceN) ;

int main(int argc, char *argv[]){
    FILE *fin = NULL, *fout = NULL;
    
    if (argc != 3) {
        fprintf(stderr, "\n!!! Используйте: %s <file.txt> <space count>\n", argv[0]);
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
    strcpy((newfile + i), ".t1\0");

    fout = fopen(newfile, "w+");
    if (fout == NULL) {
        fprintf(stderr, "Не удается открыть %s файл.\n", newfile);
        exit(EXIT_FAILURE);
	}
	
	/* Search spaces */
	long int startStr = ftell(fin);
	long int endStr = 0;
	
	int spaceN = 0;
	char ch = fgetc(fin);
	
	while (ch != EOF) {
	    if (ch == ' ') spaceN += 1;
	    if (ch == '\n' || ch == EOF) {
	        endStr = ftell(fin);
	        if (spaceN != atoi(argv[2]))
	            toFileOut(fin, &startStr, &endStr, fout, spaceN);
    	    startStr = endStr;
    	    spaceN = 0;
    	}
    	ch = fgetc(fin);
	}
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

void toFileOut(FILE *fin, long int *start, long int *end, FILE *fout, int spaceN) {
    fseek(fout , 0, SEEK_END);
    char *buf = malloc(sizeof(char) * (*(end) - *(start)));
    memset(buf, '\0', sizeof(buf));
    fseek(fin, *start, SEEK_SET);
    fread(buf, sizeof(char), (*(end) - *(start)), fin);
    fseek(fin, *end, SEEK_SET);
    fputs(buf, fout);
    fprintf(fout, "[%dspaces]\n", spaceN);
    free(buf);
}
