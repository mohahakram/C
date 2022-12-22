#include <stdio.h>

void my_swap(int *a, int *b);
void my_putstr(char *s);
int my_strlen(char *s);
char* my_revstr(char *s);
void test();

int main()
{
    //test();
    return 0;
}

void my_putchar(char c){
    write(1, &c, 1);
}

void my_swap(int *a, int *b){
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
}

void my_putstr(char *s){
    int i;
    
    i = 0;
    while(s[i] != '\0'){
        my_putchar(s[i]);
        i++;
    }
    my_putchar('\n');
}

int my_strlen(char *s){
    int i;
    int length;
    
    i = 0;
    length = 0;
    while(s[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

char* my_revstr(char *s){
    int i;
    int j;
    char a;
    int len;
    
    i = 0;
    len = my_strlen(s);
    j = len - 1;
    while(i <= len / 2){
        a = s[i];
        s[i] = s[j];
        s[j]= a;
        i++;
        j--;
    }
    return s;
    
}

/*
void test(){
    /////my_length//////
    {
        int i;
        int len;
        i = 0;
        int test[] = {0, 1, 456, 1000, 2147483647};
        int expected[] = {1, 1, 3, 4, 10};
        
        while(i < 5){
        len = my_length(test[i]);
            if(len != expected[i]){
                printf("my_length() / Expected : %d got : %d\n", expected[i], len);
            }
            i++;
        }
    }
    
    /////my_pwr_int/////
    {
        int i;
        int pwr;
        i = 0;
        int test[] = {0, 1, 4, 7};
        int expected[] = {1, 10, 10000, 10000000};
    
        while(i < 4){
            pwr = my_pwr_int(10, test[i]);
            if(pwr != expected[i]){
                printf("my_pwr_int() / Expected : %d got : %d\n", expected[i], pwr);
            }
            i++;
        }
    }
}*/
