#include <stdio.h>
#include <string.h>

void my_swapint(int *a, int *b);
void my_swapchar(char *a, char *b);
void my_putstr(char *s);
int my_strlen(char *s);
char* my_revstr(char *s);
int my_getnbr(char *nbr);
char* my_strcpy(char *dest, char *src);
char* my_strncpy(char *dest, char *src, size_t n);
char* my_strstr(char *s1, char *s2);
int my_strisalpha(char *s);
int my_strisnum(char *s);
char* my_str_upcase(char *s);
char* my_str_lowercase(char *s);
char* my_str_capitalize(char *s);
char *my_strcat(char *restrict s1, const char *restrict s2);
char *my_strncat(char *restrict s1, char *restrict s2, size_t n);
char *my_strdup(const char *s1);
char *my_strndup(const char *s1, size_t n);
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

	while(nbr[i] < 48 && nbr[i] != '\0'){
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

char* my_strcpy(char* dest, char* src){
	int i;
	i = 0;
		
	while(src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char* my_strncpy(char* dest, char* src, size_t n){
	int i;
	i = 0;
	
	while(i < n && src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	while(i < n){
		dest[i] = '\0';
		i++;
	}
	return dest;	
}

int my_strlen(char *s){
    int i;
    
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

char* my_strstr(char* s1, char* s2){
	int i;
	int j;
	int pointer;

	i = 0;
	
	if(my_strlen(s2) == 0){
		return s1;
	}
	while(s1[i] != '\0'){
		j = 0;
		if(s2[j] == s1[i]){
			pointer = i;
			while(s2[j] == s1[i]){
				if(s2[j + 1] == '\0'){
					return &s1[pointer];
				}
				i++;
				j++;
			}
			 
		}
		i++;
	}
}

int my_strisalpha(char *s){
	int i;
	i = 0;
	
	if(my_strlen(s) == 0){
		return 0;
	}
	while(s[i] != '\0'){
		if(s[i] < 48 || s[i] > 57){
			if(s[i] < 65 || s[i] > 90){
				if(s[i] < 97 || s[i] > 122){
					return 0;
				}
			}
		} 
		i++;
	}
	return 1;
}

int my_strisnum(char *s){
	int i;
	i = 0;
	
	if(my_strlen(s) == 0){
		return 0;
	}
	while(s[i] != '\0'){
		if(s[i] < 48 || s[i] > 57){
					return 0;
		} 
		i++;
	}
	return 1;
}

char* my_str_upcase(char *s){
    int i;
    i = 0;
    
    while(s[i] != '\0'){
        if(s[i] >= 97 && s[i] <= 122){
            s[i] = s[i] - 32;
        }
        i++;
    }
    return s;
}

char* my_str_lowercase(char *s){
    int i;
    i = 0;
    
    while(s[i] != '\0'){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] = s[i] + 32;
        }
        i++;
    }
    return s;
}

char* my_str_capitalize(char *s){
    int i;
    i = 0;
    
    while(s[i] != '\0'){
        if(s[i] >= 97 && s[i] <= 122){
            if(i == 0 || s[i - 1] == ' '){
                s[i] = s[i] - 32;
            }
        }else if(s[i] >= 65 && s[i] <= 90){
            if(i != 0 && s[i - 1] != ' '){
                s[i] = s[i] + 32;
            }
        }
        i++;
    }
    return s;
}

char *my_strcat(char *restrict s1, const char *restrict s2){
	int i;
	int j;
    i = 0;
	j = 0;

	while(s1[i] != '\0'){
		i++;
	}
	while(s2[j] != '\0'){
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return s1;
}

char* my_strncat(char *restrict s1, char *restrict s2, size_t n){
	int i;
	int j;
	i = 0;
	j = 0;

	while(s1[i] != '\0'){
		i++;
	}
	while(j < n && s2[j] != '\0'){
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return s1;
}

char *my_strdup(const char *s1){
    char *s2 = malloc(sizeof(s1));
    
    if(s2 == NULL){
        return NULL;
    }
    my_strcpy(s2, s1);
    return s2;
}

char *my_strndup(const char *s1, size_t n){
    char *s2 = malloc(sizeof(s1));
    
    if(s2 == NULL){
        return NULL;
    }
    my_strncpy(s2, s1, n);
    return s2;
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
        char nbr8[] = "++--++";
        
        int result1 = my_getnbr(nbr1);
        int result2 = my_getnbr(nbr2);
        int result3 = my_getnbr(nbr3);
        int result4 = my_getnbr(nbr4);
        int result5 = my_getnbr(nbr5);
        int result6 = my_getnbr(nbr6);
        int result7 = my_getnbr(nbr7);
        int result8 = my_getnbr(nbr8);
        
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
		if(result8 != 0){
		    printf("\nmy_getnbr expected result8 = 0 / got = %d", result8);
		}
    }
	
	/////test my_strcpy/////
    
	//test basic string
	{		
		int i;
		
		i = 0;
		char string[] = "hello";
		char copy_strcpy[100] = {0};
		char copy_my_strcpy[100] = {0};

		my_strcpy(copy_my_strcpy, string);
		strcpy(copy_strcpy, string);

		while(copy_strcpy[i] != '\0'){
			if(copy_my_strcpy[i] != copy_strcpy[i]){
			    printf("\nmy_strcpy 'hello' expected : %s / got : %s", copy_strcpy, copy_my_strcpy);
			}
			i++;
		}
	}

	// test one char
	{		
		int i;
		
		i = 0;
		char string[] = "h";
		char copy_strcpy[100] = {0};
		char copy_my_strcpy[100] = {0};

		my_strcpy(copy_my_strcpy, string);
		strcpy(copy_strcpy, string);

		while(copy_strcpy[i] != '\0'){
			if(copy_my_strcpy[i] != copy_strcpy[i]){	
				printf("\nmy_strcpy 'h' extepcted : %s / got : %s", copy_strcpy, copy_my_strcpy);
			}
			i++;
		}
	}

	//test empty string
	{		
		int i;
		
		i = 0;
		char string[] = "";
		char copy_strcpy[100] = {0};
		char copy_my_strcpy[100] = {0};

		my_strcpy(copy_my_strcpy, string);
		strcpy(copy_strcpy, string);

		while(copy_strcpy[i] != '\0'){
			if(copy_my_strcpy[i] != copy_strcpy[i]){	
				printf("\nmy_strcpy '' extepcted : %s / got : %s", copy_strcpy, copy_my_strcpy);
			}
			i++;
		}
	}

	//test symbols
	{		
		int i;
		
		i = 0;
		char string[] = "#he/llo-";
		char copy_strcpy[100] = {0};
		char copy_my_strcpy[100] = {0};

		my_strcpy(copy_my_strcpy, string);
		strcpy(copy_strcpy, string);

		while(copy_strcpy[i] != '\0'){
			if(copy_my_strcpy[i] != copy_strcpy[i]){	
				printf("\nmy_strcpy '#he/llo-' extepcted : %s / got : %s", copy_strcpy, copy_my_strcpy);
			}
			i++;
		}
	}

	//test long number
	{		
		int i;
		
		i = 0;
		char string[] = "12345678912345";
		char copy_strcpy[100] = {0};
		char copy_my_strcpy[100] = {0};

		my_strcpy(copy_my_strcpy, string);
		strcpy(copy_strcpy, string);

		while(copy_strcpy[i] != '\0'){
			if(copy_my_strcpy[i] != copy_strcpy[i]){	
				printf("\nmy_strcpy '12345678912345' extepcted : %s / got : %s", copy_strcpy, copy_my_strcpy);
			}
			i++;
		}
	}

	//test negativ number
	{		
		int i;
		
		i = 0;
		char string[] = "-12345678";
		char copy_strcpy[100] = {0};
		char copy_my_strcpy[100] = {0};

		my_strcpy(copy_my_strcpy, string);
		strcpy(copy_strcpy, string);

		while(copy_strcpy[i] != '\0'){
			if(copy_my_strcpy[i] != copy_strcpy[i]){	
				printf("\nmy_strcpy '-12345678' extepcted : %s / got : %s", copy_strcpy, copy_my_strcpy);
			}
			i++;
		}
	}
	
	/////test my_strncpy/////

	//test basic string
	{		
		int i;
		
		i = 0;
		char string[] = "hello";
		char copy_strncpy[10] = {0};
		char copy_my_strncpy[10] = {0};
		
		strncpy(copy_strncpy, string, 10);
		my_strncpy(copy_my_strncpy, string, 10);

		while(i < 10){
			if(copy_my_strncpy[i] != copy_strncpy[i]){	
                printf("\nmy_strncpy 'hello' extepcted : %s / got : %s", copy_strncpy, copy_my_strncpy);
			}
			i++;
		}
	}


	//test empty string
	{		
		int i;
		
		i = 0;
		char string[] = "";
		char copy_strncpy[10] = {0};
		char copy_my_strncpy[10] = {0};

		strncpy(copy_strncpy, string, 10);
		my_strncpy(copy_my_strncpy, string, 10);

		while(i < 10){
			if(copy_my_strncpy[i] != copy_strncpy[i]){	
                printf("\nmy_strncpy '' extepcted : %s / got : %s", copy_strncpy, copy_my_strncpy);
			}
			i++;
		}
	}
	
	// test long string
	{		
		int i;
	
		i = 0;
		char string[] = "this is a long string";
		char copy_strncpy[10] = {0};
		char copy_my_strncpy[10] = {0};

		strncpy(copy_strncpy, string, 10);
		my_strncpy(copy_my_strncpy, string, 10);

		while(i < 10){
			if(copy_my_strncpy[i] != copy_strncpy[i]){	
				printf("\nmy_strncpy 'this is a long string' extepcted : %s / got : %s", copy_strncpy, copy_my_strncpy);
			}
			i++;
		}
	}
	
	// test symbols
	{		
		int i;
		
		i = 0;
		char string[] = "my$&@/";
		char copy_strncpy[10] = {0};
		char copy_my_strncpy[10] = {0};

		strncpy(copy_strncpy, string, 10);
		my_strncpy(copy_my_strncpy, string, 10);

		while(i < 10){
			if(copy_my_strncpy[i] != copy_strncpy[i]){	
				printf("\nmy_strncpy 'my$&@/' extepcted : %s / got : %s", copy_strncpy, copy_my_strncpy);
			}
			i++;
		}

	}

	// test long number
	{		
		int i;
		
		i = 0;
		char string[] = "1234567890123";
		char copy_strncpy[10] = {0};
		char copy_my_strncpy[10] = {0};
	
		strncpy(copy_strncpy, string, 10);
		my_strncpy(copy_my_strncpy, string, 10);

		while(i < 10){
			if(copy_my_strncpy[i] != copy_strncpy[i]){	
				printf("\nmy_strncpy '1234567890123' extepcted : %s / got : %s", copy_strncpy, copy_my_strncpy);
			}
			i++;
		}
	
	}

	// test negativ number
	{		
		int i;
		
		i = 0;
		char string[] = "-1234567";
		char copy_strncpy[10] = {0};
		char copy_my_strncpy[10] = {0};

		strncpy(copy_strncpy, string, 10);
		my_strncpy(copy_my_strncpy, string, 10);

		while(i < 10){
			if(copy_my_strncpy[i] != copy_strncpy[i]){	
                printf("\nmy_strncpy '-1234567' extepcted : %s / got : %s", copy_strncpy, copy_my_strncpy);
			}
			i++;
		}
		
	}
	
	/////test my_strstr/////
	
	//test same string
	{
		char s1[] = "Une longue phrase";
		char s2[] = "Une longue phrase";
		char* res_strstr;
		char* my_res_strstr;

		res_strstr = strstr(s1, s2);
		my_res_strstr = my_strstr(s1, s2);
			if(my_res_strstr != res_strstr){
				printf("\nmy_strstr 'Une longue phrase' extepcted : %s / got : %s", res_strstr, my_res_strstr);
			}
	}


	//test short search string
	{
		char s1[] = "Une longue voiture";
		char s2[] = "lon";
		char* res_strstr;
		char* my_res_strstr;

		res_strstr = strstr(s1, s2);
		my_res_strstr = my_strstr(s1, s2);
			if(my_res_strstr != res_strstr){
				printf("\nmy_strstr 'Une longue voiture' extepcted : %s / got : %s", res_strstr, my_res_strstr);
			}
	}

	//test empty string
	{
		char s1[] = "";
		char s2[] = "une longue phrase";
		char* res_strstr;
		char* my_res_strstr;

		res_strstr = strstr(s1, s2);
		my_res_strstr = my_strstr(s1, s2);
			if(my_res_strstr != res_strstr){
				printf("\nmy_strstr '' extepcted : %s / got : %s", res_strstr, my_res_strstr);
			}
	}

	//test not matching string
	{
		char s1[] = "Un cargo bleu";
		char s2[] = "ciel";
		char* res_strstr;
		char* my_res_strstr;

		res_strstr = strstr(s1, s2);
		my_res_strstr = my_strstr(s1, s2);
			if(my_res_strstr != NULL){
				printf("\nmy_strstr 'Un cargo bleu' extepcted : %s / got : %s", res_strstr, my_res_strstr);
			}
	}

	//test empty search string
	{
		char s1[] = "Une phrase vide";
		char s2[] = "";
		char* res_strstr;
		char* my_res_strstr;

		res_strstr = strstr(s1, s2);
		my_res_strstr = my_strstr(s1, s2);
			if(my_res_strstr != res_strstr){
				printf("\nmy_strstr 'Une phrase vide' extepcted : %s / got : %s", res_strstr, my_res_strstr);
			}
	}
	
	/////test my_strisalpha/////
	
	// test number
	{	
		int result;
		char string[] = "12345678";
		
		result = my_strisalpha(string);
		
		if(result != 1){
			printf("\nmy_strisalpha '12345678' extepcted : 1 / got : %d", result);	
		}
	}

	// test char 
	{	
		int result;
		char string[] = "abcdeABCDE";
		
		result = my_strisalpha(string);
		
		if(result != 1){
			printf("\nmy_strisalpha 'abcdeABCDE' extepcted : 1 / got : %d", result);	
		}
	}

	// test alphanum
	{	
		int result;
		char string[] = "123ghkaUIT78";
		
		result = my_strisalpha(string);
		
		if(result != 1){
			printf("\nmy_strisalpha '123ghkaUIT78' extepcted : 1 / got : %d", result);	
		}
	}

	// test symbol
	{	
		int result;
		char string[] = "15Ac6&g7$8";
		
		result = my_strisalpha(string);
		
		if(result != 0){
			printf("\nmy_strisalpha '15Ac6&g7$8' extepcted : 0 / got : %d", result);	
		}
	}

	// test empty
	{	
		int result;
		char string[] = "";
		
		result = my_strisalpha(string);
		
		if(result != 0){
			printf("\nmy_strisalpha '' extepcted : 0 / got : %d", result);	
		}
	}
	
	/////test my_strisnum/////
	
	// test number
	{	
		int result;
		char string[] = "12345678";
		
		result = my_strisnum(string);
		
		if(result != 1){
			printf("\nmy_strisnum '' extepcted : 1 / got : %d", result);	
		}
	}

	// test long number
	{	
		int result;
		char string[] = "123456789012345";
		
		result = my_strisnum(string);
		
		if(result != 1){
			printf("\nmy_strisnum '123456789012345' extepcted : 1 / got : %d", result);	
		}
	}

	// test symbol
	{	
		int result;
		char string[] = "12345&678";
		
		result = my_strisnum(string);
		
		if(result != 0){
			printf("\nmy_strisnum '12345&678' extepcted : 0 / got : %d", result);	
		}
	}

	// test char
	{	
		int result;
		char string[] = "12345c678";
		
		result = my_strisnum(string);
		
		if(result != 0){
			printf("\nmy_strisnum '12345c678' extepcted : 0 / got : %d", result);
		}
	}

	// test empty
	{	
		int result;
		char string[] = "";
		
		result = my_strisnum(string);
		
		if(result != 0){
			printf("\nmy_strisnum '' extepcted : 0 / got : %d", result);	
		}
	}
	
	/////test my_str_upcase/////
	
	// test string
	{	
	    int i;
	    i= 0;
		char string[] = "abc";
		char res[] = "ABC";
		
		my_str_upcase(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_upcase 'abc' extepcted : abc / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test vide
	{	
	    int i;
	    i = 0;
		char string[] = "";
		char res[] = "";
		
		my_str_upcase(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_upcase '' extepcted : '' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test symbol
	{	
	    int i;
	    i = 0;
		char string[] = "@phrasE avec -symboles123";
		char res[] = "@PHRASE AVEC -SYMBOLES123";
		
		my_str_upcase(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_upcase '@phrasE avec -symboles123' extepcted : '@PHRASE AVEC -SYMBOLES123' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	/////test my_str_lowercasecase/////
	
	// test string
	{	
	    int i;
	    i= 0;
		char string[] = "ABC";
		char res[] = "abc";
		
		my_str_lowercase(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_lowercase 'ABC' extepcted : ABC / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test vide
	{	
	    int i;
	    i = 0;
		char string[] = "";
		char res[] = "";
		
		my_str_lowercase(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_lowercase '' extepcted : '' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test symbol
	{	
	    int i;
	    i = 0;
		char string[] = "@PHRASE AVEC -SYMBOLES123";
		char res[] = "@phrase avec -symboles123";
		
		my_str_lowercase(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_lowercase '@PHRASE AVEC -SYMBOLES123' extepcted : '@phrasE avec -symboles123' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	/////test my_str_capitalize/////
	
	// test string
	{	
	    int i;
	    i = 0;
		char string[] = "une phrase simple";
		char res[] = "Une Phrase Simple";
		
		my_str_capitalize(string);
		
		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_capitalize 'une simple phrase' extepcted : Une Simple Phrase / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test vide
	{	
	    int i;
	    i = 0;
		char string[] = "";
		char res[] = "";
		
		my_str_capitalize(string);
		
		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_capitalize '' extepcted : '' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test symbol
	{	
	    int i;
	    i = 0;
		char string[] = "phRase a*ec sYmb~les";
		char res[] = "Phrase A*ec Symb~les";
		
		my_str_capitalize(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_capitalize '@PHRASE AVEC -SYMBOLES123' extepcted : '@Phrase Avec -Syboles123' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	// test maj
	{	
	    int i;
	    i = 0;
		char string[] = "PHRASE EN MAJUSCULE";
		char res[] = "Phrase En Majuscule";
		
		my_str_capitalize(string);

		while(string[i] != '\0'){
		    if(string[i] != res[i]){
			    printf("\nmy_str_capitalize 'PHRASE EN MAJUSCULE' extepcted : 'Phrase En Majuscule' / got : %s", string);	
		    }
		    i++;
		}
	}
	
	/////my_strcat/////
    {
        int i;
        i = 0;
        char s1[] = "hello world";
        char s2[] = "hello";
        char s3[] = " world";
        
        my_strcat(s2, s3);
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strcat expected : hello world / got : %s\n", s2);
            }
            i++;
        }
    }
    
    {
        int i;
        i = 0;
        char s1[] = "h";
        char s2[] = "";
        char s3[] = "hello";
        
        my_strcat(s2, s3);
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strcat expected : h / got : %s\n", s2);
            }
            i++;
        }
    }
    
    {
        int i;
        i = 0;
        char s1[] = "hello 1@";
        char s2[] = "hello ";
        char s3[] = "1@";
        
        my_strcat(s2, s3);
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strcat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
    }
    
    /////my_strncat/////
    {
        int i;
        i = 0;
        char s1[] = "hello world";
        char s2[] = "hello";
        char s3[] = " world";
        
        my_strncat(s2, s3, sizeof(s2));
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : hello world / got : %s\n", s2);
            }
            i++;
        }
    }
    
    {
        int i;
        i = 0;
        char s1[] = "h";
        char s2[] = "";
        char s3[] = "hello";
        
        my_strncat(s2, s3, sizeof(s2));
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : h / got : %s\n", s2);
            }
            i++;
        }
    }
    
    {
        int i;
        i = 0;
        char s1[] = "hello 1@";
        char s2[] = "hello ";
        char s3[] = "1@";
        
        my_strncat(s2, s3, sizeof(s2));
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
    }
    
    /////my_strdup////
    {
        int i;
        i = 0;
        char s1[] = "hello 1@";
        char *s2 = my_strdup(s1);
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
        free(s2);
    }
    
    {
        int i;
        i = 0;
        char s1[] = "h";
        char *s2 = my_strdup(s1);
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
        free(s2);
    }
    
    {
        int i;
        i = 0;
        char s1[] = "";
        char *s2 = my_strdup(s1);
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
        free(s2);
    }
    
    /////my_strndup////
    {
        int i;
        i = 0;
        char s1[] = "hello 1@";
        char *s2 = my_strndup(s1, sizeof(s1));
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
        free(s2);
    }
    
    {
        int i;
        i = 0;
        char s1[] = "h";
        char *s2 = my_strndup(s1, sizeof(s1));
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
        free(s2);
    }
    
    {
        int i;
        i = 0;
        char s1[] = "";
        char *s2 = my_strndup(s1, sizeof(s1));
        
        while(s1[i] != '\0'){
            if(s1[i] != s2[i]){
                printf("my_strncat expected : '%c' / got : '%c'\n",s1[i], s2[i]);
            }
            i++;
        }
        free(s2);
    }
}
