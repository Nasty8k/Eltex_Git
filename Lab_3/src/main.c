#include "v5.h"

void inputShopReceipt(ShopReceipt *p);

int main(int argc, char **argv) {
    static ShopReceipt arr[3];
    static ShopReceipt *p = arr;
  
    int i;
    for (i = 0; i < 1; ++i) {
        inputShopReceipt(p);
        p++;
    }
    
    for (i = 0; i < 1; ++i) {
        printf("\n> Num %d ------\n", i+1);
        printf("  Name[%s]\n", arr[i].name);
        printf("  Number = %u\n", arr[i].number);
        printf("  Price = %u\n", arr[i].price);
        printf("  Data = %2u - %2u - %u\n", arr[i].date.day, arr[i].date.month, arr[i].date.year + YEAR0);
    }
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
