#include <stdio.h>

int add(int a, int b);
int substract(int a, int b);
int divide(int a, int b);
int multiply(int a, int b);
int do_op_advanced(int a, int b, int (*fun)(int, int));
struct s_op{
    char op;
    int (*fun)(int, int);
};

int main()
{
    struct s_op ops[] = {
        {'+', &add},
        {'-', &substract},
        {'/', &divide},
        {'*', &multiply},
    };
    
    int i = 0;
    int a = 1;
    int b = 2;
    char op = '/';
    int res = 0;
    
    while(i < sizeof(ops) / sizeof(ops[0])){
        if(op == ops[i].op){
            res = ops[i].fun(a, b);
            printf("res = %d\n", res);
            break;
        }
        i++;
    }
    

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

int do_op_advanced(int a, int b, int (*fun)(int, int)){
    int res = fun(a, b);
    return res;
}
