#include <stdio.h>

void my_swapint(int *a, int *b);
void my_swapchar(char *a, char *b);
void my_putstr(char *s);
int my_strlen(char *s);
char* my_revstr(char *s);
int my_getnbr(char *nbr);
void test();

int main()
{
    test();
    return 0;
}

void my_putchar(char c){
    write(1, &c, 1);
}

void my_swapint(int *a, int *b){
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
}

void my_swapchar(char *a, char *b){
    char c;
    
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
}

int my_strlen(char *s){
    int i;
    
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

char* my_revstr(char *s){
    int i;
    int j;
    int len;
    
    i = 0;
    len = my_strlen(s);
    j = len - 1;
    while(i <= len / 2){
        my_swapchar(s + i, s + j);
        i++;
        j--;
    }
    return s;
}

int my_getnbr(char *nbr){
	int i;
	int num;
	int negative;

	i = 0;
	num = 0;
	negative = 0;

	while(nbr[i] < 48){
		if(nbr[i] == '-'){
			negative++;
		}
		i++;
	}	

	while(nbr[i] != '\0'){
		if(nbr[i] < 48 || nbr[i] > 57){
		    i++;
			continue;
		}
		num = num * 10;
		num = num + nbr[i];
		num = num - 48;
		if(num < 0){
			return 0;
		}
		i++;
	}
	if(negative % 2 == 0){
		return num;
	}else{
		num *= -1;
		return num;
	}	
}

void test(){
    /////my_swapchar//////
    {
        char a;
        char b;
        a = 'a';
        b = 'b';
        
        my_swapchar(&a, &b);
        if(a != 'b' || b != 'a'){
            printf("my_swapchar expected a = 'b', b = 'a' / got a = %c, b = %c", a,b);
        }
    }
    {
        char a;
        char b;
        a = '&';
        b = '1';
        
        my_swapchar(&a, &b);
        if(a != '1' || b != '&'){
            printf("my_swapchar expected a = '1', b = '&' / got a = %c, b = %c", a,b);
        }
    }
    
    /////my_strlen/////
    {
        char str1[] = "";
        char str2[] = "hello";
        char str3[] = "hello world&-";
        
        int str1_len = my_strlen(str1);
        int str2_len = my_strlen(str2);
        int str3_len = my_strlen(str3);
        
        if(str1_len != 0){
            printf("\nmy_strlen expected str1_len = O / got = %d", str1_len);
        }
        if(str2_len != 5){
            printf("\nmy_strlen expected str1_len = 5 / got = %d", str2_len);
        }
        if(str3_len != 13){
            printf("\nmy_strlen expected str1_len = O / got = %d", str3_len);
        }
    }
    
    /////my_revstr/////
    {
        int i;
        i = 0;
        char str1[] = "";
        char str2[] = "olleh";
        char str3[] = "&-dlrow olleh";
        
        char str1_rev []= "";
        char str2_rev []= "hello";
        char str3_rev []= "hello world-&";
        
        my_revstr(str1);
        my_revstr(str2);
        my_revstr(str3);
        
        while(str1_rev[i] != '\0'){
            if(str1[i] != str1_rev[i]){
                printf("\nmy_revstr expected str1 =  / got = %s", str1);
            }
            i++;
        }
        
        i = 0;
        while(str1_rev[i] != '\0'){
            if(str2[i] != str2_rev[i]){
                printf("\nmy_revstr expected str2 = hello / got = %s", str2);
            }
            i++;
        }
        
        i=0;
        while(str3_rev[i] != '\0'){
            if(str3[i] != str3_rev[i]){
                printf("\nmy_revstr expected str3 = hello world-& / got = %s", str3);
            }
            i++;
        }
    }
    
    /////my_getnbr/////
    {
        char nbr1[] = "0";
        char nbr2[] = "12345";
        char nbr3[] = "--214sfd@g836";
        char nbr4[] = "2147483647";
        char nbr5[] = "-2147483647";
        char nbr6[] = "2147483648";
        char nbr7[] = "-2147483648";
        
        int result1 = my_getnbr(nbr1);
        int result2 = my_getnbr(nbr2);
        int result3 = my_getnbr(nbr3);
        int result4 = my_getnbr(nbr4);
        int result5 = my_getnbr(nbr5);
        int result6 = my_getnbr(nbr6);
        int result7 = my_getnbr(nbr7);
        
		if(result1 != 0){
		    printf("\nmy_getnbr expected result1 = 0 / got = %d", result1);
		}
        if(result2 != 12345){
		    printf("\nmy_getnbr expected result2 = 0 / got = %d", result2);
		}
		if(result3 != 214836){
		    printf("\nmy_getnbr expected result3 = 214836 / got = %d", result3);
		}
		if(result4 != 2147483647){
		    printf("\nmy_getnbr expected result4 = 2147483647 / got = %d", result4);
		}
        if(result5 != -2147483647){
		    printf("\nmy_getnbr expected result5 = 0 / got = %d", result5);
		}
		if(result6 != 0){
		    printf("\nmy_getnbr expected result6 = 0 / got = %d", result6);
		}
		if(result7 != 0){
		    printf("\nmy_getnbr expected result7 = 0 / got = %d", result7);
		}
    }
}
