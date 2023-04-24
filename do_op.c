#include <stdio.h>

int add(int a, int b);
int substract(int a, int b);
int divide(int a, int b);
int multiply(int a, int b);
int do_op(int a, int b, int (*fun)(int, int));

int main()
{
    int res;
    
    res = do_op(1, 2, &divide);
    printf("res = %d\n", res);

    return 0;
}

int add(int a, int b){
    return a + b;
}

int substract(int a, int b){
    return a - b;
}

int divide(int a, int b){
    return a / b;
}

int multiply(int a, int b){
    return a * b;
}

int do_op(int a, int b, int (*fun)(int, int)){
    int res = fun(a, b);
    return res;
}
