#include "sort.h"

int replace = 0;
int nspace = 0;

int inp_str(char* string, int maxlen) {
    int i;
    char c;
    for (i = 0; (c = getc(stdin)) != '\n'; ++i) {
        string[i] = c;
        if (i == (maxlen - 1)) {
            maxlen *= 2;
            string = (char*) realloc(string, maxlen * sizeof(char));
            if (string == NULL) return 0;
        }
    }
    string[i] = '\0';
    return i;
}

void out_str(char* string, int length, int number) {
    printf("%d) %s \n", number, string);
}

int schr(const char * str, const char ch) {
    int i, idx = -1;
    for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
    if (str[i] == ch) idx = i;
    return idx;
}

//var1
int var1(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    qsort(p_arr_str, c_str, sizeof(char *), cmp1);
    output->first = replace;
    
    int i, min = strlen(p_arr_str[0]);
    for (i = 1; i < c_str; ++i) {
        if (strlen(p_arr_str[i]) < min)
            min = strlen(p_arr_str[i]);
    }
    output->second = min;
    return 0;
}
int cmp1(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;
	if (strlen(s1) - strlen(s2)) replace += 1;
	return (strlen(s1) - strlen(s2));
}

//var2
int var2(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    qsort(p_arr_str, c_str, sizeof(char *), cmp2);
    output->first = replace;
    
    int i, max = strlen(p_arr_str[0]);
    for (i = 1; i < c_str; ++i) {
        if (strlen(p_arr_str[i]) > max)
            max = strlen(p_arr_str[i]);
    }
    output->second = max;
    return 0;
}
int cmp2(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;
	if (strlen(s1) - strlen(s2)) replace += 1;

	return (strlen(s1) - strlen(s2)) * (-1);
}
//var 3
int var3(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    qsort(p_arr_str, c_str, sizeof(char *), cmp3);
    output->first = replace;
    output->second = p_arr_str[0][0];
    return 0;
}
int cmp3(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;
	if (strcmp(s1, s2)) replace += 1;

	return strcmp(s1, s2); 
}

//var 4
int var4(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    qsort(p_arr_str, c_str, sizeof(char *), cmp4);
    output->first = replace;
    output->second = strlen(p_arr_str[0]);
    return 0;
}
int cmp4(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;
	if (strcmp(s1, s2)) replace += 1;

	return strcmp(s1, s2) * (-1);
}

//var 5
int var5(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    qsort(p_arr_str, c_str, sizeof(char *), cmp5);
    output->first = replace;
    output->second = p_arr_str[c_str-1][0];
    return 0;
}
int cmp5(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;
	
	int sp1 = 0, sp2 = 0;
	int start = 0, delta = 0;

	delta = schr(&s1[start], ' ');
	while (delta != -1) {
		++sp1;
		start += delta + 1;
		delta = schr(&s1[start+1], ' '); 
	}

    start = 0;
    delta = schr(&s2[start], ' ');
    while (delta != -1) {
	    ++sp2;
        start += delta + 1;
        delta = schr(&s2[start+1], ' '); 
    }
    
	if (sp1 != sp2) replace += 1;

	return sp1 - sp2;
}

//var 6
int var6(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    nspace = 0;
    qsort(p_arr_str, c_str, sizeof(char *), cmp6);
    output->first = replace;
    output->second = nspace + 1;
    return 0;
}
int cmp6(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;
	
	int sp1 = 0, sp2 = 0;
	int start = 0, delta = 0;

	delta = schr(&s1[start], ' ');
	while (delta != -1) {
		++sp1;
		start += delta + 1;
		delta = schr(&s1[start+1], ' '); 
	}

    start = 0;
    delta = schr(&s2[start], ' ');
    while (delta != -1) {
	    ++sp2;
        start += delta + 1;
        delta = schr(&s2[start+1], ' '); 
    }
    
	if (sp1 != sp2) replace += 1;
    if (sp1 > nspace) nspace = sp1;
    if (sp2 > nspace) nspace = sp2;
    
	return (sp1 - sp2) * (-1);
}

//var 7
int var7(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    int i, j, k;
    char n;
    
    qsort(p_arr_str, c_str, sizeof(char *), cmp7);
    output->first = replace;
    
    for (i = 0; i < c_str; ++i) {
        for (j = 0, k = 0;(j < strlen(p_arr_str[i])) && (k != 2); ++j) {
            if (p_arr_str[i][j] >= '0' && p_arr_str[i][j] <= '9') {
                n = p_arr_str[i][j];
                k += 1;
            }
        }
        (k == 2) ? (output->string[i] = n) : (output->string[i] = '-');
    }
    return 0;
}
int cmp7(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;	
	int c1 = 0, c2 = 0, i;
	
	for (i = 0; i < strlen(s1); ++i)
		if (s1[i] >= '0' && s1[i] <= '9') ++c1;
		
	for (i = 0; i < strlen(s2); ++i)
		if (s2[i] >= '0' && s2[i] <= '9') ++c2;

	if (c1 != c2) replace += 1;  
	return (c1 - c2);
}

//var 8
int var8(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    nspace = 0;
    int i, j, k;
    char n;
    
    qsort(p_arr_str, c_str, sizeof(char *), cmp8);
    output->first = replace;
    
    for (i = 0; i < c_str; ++i) {
        for (j = 0; j < strlen(p_arr_str[i]);  ++j)
            if (p_arr_str[i][j] >= '0' && p_arr_str[i][j] <= '9') 
                nspace += 1;
    }
    output->second = nspace;
    return 0;
}
int cmp8(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;	
	int c1 = 0, c2 = 0, i;
	
	for (i = 0; i < strlen(s1); ++i)
		if (s1[i] >= '0' && s1[i] <= '9') ++c1;
		
	for (i = 0; i < strlen(s2); ++i)
		if (s2[i] >= '0' && s2[i] <= '9') ++c2;

	if (c1 != c2) replace += 1;  
	return (c1 - c2) * (-1);
}

//var 9
int var9(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    nspace = 0;
    int i, j, k, max, start;
    
    qsort(p_arr_str, c_str, sizeof(char *), cmp9);
    output->first = replace;
    //TODO recount word's length in every string after space
    for (i = 0; i < c_str; ++i) {
        start = 0;
        for (j = 0; j < strlen(p_arr_str[i]);  ++j) {

            if (p_arr_str[i][j] == ' ') {
                max = j - start;
                if (max > nspace) {
                    nspace = max;
                    for(k = 0; k < max; ++k)
                        output->string[k] = p_arr_str[i][k + start];
                }
                start = j + 1;
            }
        }
    }
    output->second = nspace;
    return 0;
}
int cmp9(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;	
	int l1 = 0, l2 = 0;
	
	l1 = schr(s1, ' ');
	(l1 == -1) ? l1 = strlen(s1) : (l1 += 1);
	
    l2 = schr(s2, ' ');
	(l2 == -1) ? l2 = strlen(s2) : (l2 += 1);

	if (l1 != l2) replace += 1;  
	return (l1 - l2);
}

//var 10
int var10(char **p_arr_str, int c_str, OUT *output) {
    replace = 0;
    nspace = 0;
    int i, j, k, min, start, delta;
    
    qsort(p_arr_str, c_str, sizeof(char *), cmp10);
    
    start = 0, delta = 0, k = 0;
	delta = schr(&p_arr_str[0][start], ' ');
	while (delta != -1) {
		++k;
		start += delta + 1;
		delta = schr(&p_arr_str[0][start+1], ' '); 
	}
    output->second = k;
    
    //TODO recount word's length in every string after space
   
    output->first = nspace;
    return 0;
}
int cmp10(const void *p1, const void *p2) {
	char *s1 = *(char **) p1;
	char *s2 = *(char **) p2;	
	int l1 = 0, l2 = 0;
	
	l1 = schr(s1, ' ');
	(l1 == -1) ? l1 = strlen(s1) : (l1 += 1);
	
    l2 = schr(s2, ' ');
	(l2 == -1) ? l2 = strlen(s2) : (l2 += 1);
	  
	return (l1 - l2) * (-1);
}
