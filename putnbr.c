#include <stdio.h>

void my_putchar(char c);
int my_length(int nbr);
int my_pwr_int(int nbr, int pwr);
void my_putnbr(int nbr);
void test();

int main()
{
    test();
    return 0;
}

void my_putchar(char c){
    write(1, &c, 1);
}

int my_length(int nbr){
    int length;
    length = 0;
    
    if(nbr == 0){
        length = 1;
        return length;
    }
    while(nbr != 0){
        length++;
        nbr /= 10;
    }
    return length;
}

int my_pwr_int(int nbr, int pwr){
    int i;
    int result;
    i = 0;
    result = 1;
    
    while(i < pwr){
        result *= nbr;
        i++;
    }
    return result;
}

void my_putnbr(int nbr){
    int i;
    int temp_nbr;
    int num;
    int length;
    int pwr;
    int pwr_int;
    i = 0;
    length = my_length(nbr);
    pwr = length - 1;
    pwr_int = my_pwr_int(10, pwr);
    
    if(nbr < 0){
        my_putchar('-');
        if(nbr == -2147483648){
            num = nbr / pwr_int;
            num = num * -1 + 48;
            my_putchar(num);
            temp_nbr = 147483648;
            length--;
            pwr--;
            pwr_int = my_pwr_int(10, pwr);
        }
        nbr = nbr == -2147483648 ? temp_nbr : nbr * -1;
    }
    while(i < length){
        num = nbr / pwr_int;
        num = num % 10 + 48;
        my_putchar(num);
        pwr--;
        pwr_int = my_pwr_int(10, pwr);
        i++;
    }
}

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
}
