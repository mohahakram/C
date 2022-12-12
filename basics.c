#include <stdio.h>

void my_putchar(char c);
void my_aff_alpha();
void my_aff_nb();
void my_isneg(int n);
void my_aff_comb();

int main()
{
   my_aff_alpha();
   my_aff_nb();
   my_isneg(9);
   my_aff_comb();
   
    return 0;
}

void my_putchar(char c){
    write(1, &c, 1);
}

void my_aff_alpha(){
    char i;
    i = 'a';
    
    while(i <= 'z'){
        my_putchar(i);
        i++;
    }
}

void my_aff_nb(){
    int i;
    i = '0';
    
    while(i <= '9'){
        my_putchar(i);
        i++;
    }
}

void my_isneg(int n){
    char result;
    result = n >= 0 ? 'p' : 'n';
    
    my_putchar(result);
}

void my_aff_comb(){
    char i;
    char j;
    char k;
    
    i = '1';
    j = '2';
    k = '3';
    
    while(i <= '9'){
        
        j = '0';
        while(j <= '9'){
            
            k = '0';
            while(k <= '9'){
                
                if(i < j && j < k){
                    my_putchar(i);
                    my_putchar(j);
                    my_putchar(k);
                    
                    if(i == '7' && j == '8' && k == '9'){
                        my_putchar(' ');
                    } else{
                        my_putchar(',');
                        my_putchar(' ');
                    }
                }
                k++;
            }
            j++;
        }
        i++;
    }
}
