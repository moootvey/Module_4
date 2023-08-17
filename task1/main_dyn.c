#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(){
    void* ext_lib;
    int (*powerfunc)(int a, int b);
    ext_lib = dlopen("/home/dude/task5.1/libfuncdyn.so",RTLD_LAZY);
    if (!ext_lib){
        fprintf(stderr, "dlopen() error: %s\n", dlerror());
        return 1;
    }

    int ch;
    int a, b;
    printf("1) Multiply\n2) Division\nEnter another number to exit the program\n");
    printf("Enter num of func: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            printf("\nEnter first number: ");
            scanf("%d", &a);
            printf("Enter second number: ");
            scanf("%d", &b);
            powerfunc = dlsym(ext_lib, "multiply");
            printf("Multiplication result: %d\n", (*powerfunc)(a, b));
            dlclose(ext_lib);
            exit(EXIT_SUCCESS);
        case 2:
            printf("\nEnter first number: ");
            scanf("%d", &a);
            printf("Enter second number: ");
            scanf("%d", &b);
            powerfunc = dlsym(ext_lib, "division");
            printf("Division result: %d\n", (*powerfunc)(a, b));
            dlclose(ext_lib);
            exit(EXIT_SUCCESS);
        default:
            printf("Exiting...");
            dlclose(ext_lib);
            exit(EXIT_SUCCESS);
    }
}