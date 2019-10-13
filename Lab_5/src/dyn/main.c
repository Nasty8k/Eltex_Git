#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
    double x = 0;
    printf("\n Input x: ");
    scanf("%lf", &x);
    
    void *ext_library;	// хандлер внешней библиотеки
	double (*powerfunc)(double x);	// переменная для хранения адреса функции

    //загрузка библиотеки
	ext_library = dlopen("./libvar5.so",RTLD_LAZY);
	if (!ext_library){
		//если ошибка, то вывести ее на экран
		fprintf(stderr,"dlopen() error: %s\n", dlerror());
		return 1;
	};
    //загружаем из библиотеки требуемую процедуру
	powerfunc = dlsym(ext_library, "power3");	
    printf("Operation:\n (%lf)^3 = %lf\n", x, (*powerfunc)(x));
    powerfunc = dlsym(ext_library, "power4");	
    printf(" (%lf)^4 = %lf\n", x, (*powerfunc)(x));
    dlclose(ext_library);
    return 0;
}
