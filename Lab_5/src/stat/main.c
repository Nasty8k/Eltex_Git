#include <stdio.h>

extern double power3(double);
extern double power4(double);

int main(int argc, char **argv) {
    printf("Operation:\n power x^3, power x^4; (double)\nInput x: ");
    double x = 0, q3 = 0, q4 = 0;
    
    scanf("%lf", &x);
    q3 = power3(x);
    q4 = power4(x);
    
    printf("%lf ^3=%.2lf, %lf ^4=%.2lf\n", x, q3, x, q4);
    return 0;
}
