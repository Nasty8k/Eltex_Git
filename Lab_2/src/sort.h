#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Parametrs {
    int first;
    int second;
} OUT;

int inp_str(char* string, int maxlen);
void out_str(char* string, int length, int number);
int schr(const char * str, const char ch);

int cmp1(const void *p1, const void *p2);
int cmp2(const void *p1, const void *p2);
int cmp3(const void *p1, const void *p2);
int cmp4(const void *p1, const void *p2);
int cmp5(const void *p1, const void *p2);
int cmp6(const void *p1, const void *p2);
//int cmp7(const void *p1, const void *p2);
//int cmp8(const void *p1, const void *p2);
//int cmp9(const void *p1, const void *p2);
//int cmp10(const void *p1, const void *p2);



int var1(char **p_arr_str, int size, OUT *output);
int var2(char **p_arr_str, int size, OUT *output);
int var3(char **p_arr_str, int size, OUT *output);
int var4(char **p_arr_str, int size, OUT *output);
int var5(char **p_arr_str, int size, OUT *output);
int var6(char **p_arr_str, int size, OUT *output);
//int var7(char **p_arr_str, int size, OUT *output);
//int var8(char **p_arr_str, int size, OUT *output);
//int var9(char **p_arr_str, int size, OUT *output);
//int var10(char **p_arr_str, int size, OUT *output);

#endif
