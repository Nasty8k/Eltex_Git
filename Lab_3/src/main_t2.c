#include "v5.h"
void inputShopReceipt(ShopReceipt *p);
void outputShopReceipt(ShopReceipt *p);

int main(int argc, char **argv) {
    ShopReceipt *sp;
    sp = malloc(sizeof(ShopReceipt) * 3);
    ShopReceipt *p;
    int i;
    for (i = 0, p = sp; i < 3; ++i, ++p)
        inputShopReceipt(p);
    
    for (i = 0, p = sp; i < 3; ++i, ++p)
        outputShopReceipt(p);

	exit(EXIT_SUCCESS);
}

void inputShopReceipt(ShopReceipt *p) {
    printf("Name = ");
    scanf("%s", p->name);
    while(getc(stdin) != '\n');
    
    int x, y, z;
    printf("Number = ");
    scanf("%hhu", &x);
    (x >= 1 && x <= MAX_NUMBER) ? p->number = x : (p->number = 0);
    
    printf("Price = ");
    scanf("%hhu", &x);
    (x >= 1 && x <= MAX_PRICE) ? p->price = x : (p->price = 0);
    
    printf("Data = ");
    scanf("%hhu%*c%hhu%*c%hhu", &x, &y, &z);
    p->date.day = x;
    p->date.month = y;
    p->date.year = z - YEAR0;
}
void outputShopReceipt(ShopReceipt *p) {
    printf("  Name[%s]\n", p->name);
    printf("  Number = %u\n", p->number);
    printf("  Price = %u\n", p->price);
    printf("  Data = %2u - %2u - %u\n",  p->date.day,  p->date.month,  p->date.year + YEAR0);
    printf("--------\n");
}
