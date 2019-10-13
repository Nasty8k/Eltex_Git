#ifndef V5_H
#define V5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NAME 27
#define MAX_PRICE 65535
#define MAX_NUMBER 255
#define YEAR0 2000

struct Date
{
	unsigned short day   :5;//0-31
	unsigned short month :4;//0-15
	unsigned short year  :7;//0-127
};// 2 byte
typedef struct Date PurchaseDate;

struct Shopping
{
    char           name[LEN_NAME];//       27 byte
    unsigned short number :8; //0-255   1 byte
    unsigned short price  :16;//0-65535 2 byte
    PurchaseDate   date;      //        2 byte
};//32 byte
typedef struct Shopping ShopReceipt;
#endif
