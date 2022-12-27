#include <stdio.h>

int my_facto_int(int nbr);
int my_facto_rec(int nbr);
int my_pwr_rec(int nbr, int pwr);
void test();

int main()
{
    test();
    return 0;
}

int my_facto_int(int nbr){
    int res;
    
    res = 1;
    if(nbr < 0){
        return 0;
    }
    while(nbr > 1){
        res *= nbr;
        nbr--;
    }
    return res;
}

int my_facto_rec(int nbr){
    if(nbr < 0){
		return 0;
	}
	else if(nbr == 1 || nbr == 0){
		return 1;
	}
	return nbr * my_facto_rec(nbr - 1);
}

int my_pwr_rec(int nbr, int pwr){
    if(nbr == 0 || pwr < 0){
		return 0;
	}
	if(pwr == 0){
		return 1; 
	}
    return nbr * my_pwr_rec(nbr, pwr - 1);
}

void test(){
    /////my_facto_int//////
    {
        int a = 5;
        int b = 10;
        int c = -10;
        int d = 0;
        int e = 1;

        int res1 = my_facto_int(a);
        int res2 = my_facto_int(b);
        int res3 = my_facto_int(c);
        int res4 = my_facto_int(d);
        int res5 = my_facto_int(e);
        
        if(res1 != 120){
            printf("\nmy_facto expected res1 = 120 / got %d", res1);
        }
        if(res2 != 3628800){
            printf("\nmy_facto expected res2 = 3628800 / got %d", res2);
        }
        if(res3 != 0){
            printf("\nmy_facto expected res3 = 0 / got %d", res3);
        }
        if(res4 != 1){
            printf("\nmy_facto expected res4 = 0 / got %d", res4);
        }
        if(res5 != 1){
            printf("\nmy_facto expected res5 = 1 / got %d", res5);
        }
    }
    
    /////my_facto_rec//////
    {
        int a = 5;
        int b = 10;
        int c = -10;
        int d = 0;
        int e = 1;

        int res1 = my_facto_rec(a);
        int res2 = my_facto_rec(b);
        int res3 = my_facto_rec(c);
        int res4 = my_facto_rec(d);
        int res5 = my_facto_rec(e);
        
        if(res1 != 120){
            printf("\nmy_facto_rec expected res1 = 120 / got %d", res1);
        }
        if(res2 != 3628800){
            printf("\nmy_facto_rec expected res2 = 3628800 / got %d", res2);
        }
        if(res3 != 0){
            printf("\nmy_facto_rec expected res3 = 0 / got %d", res3);
        }
        if(res4 != 1){
            printf("\nmy_facto_rec expected res4 = 0 / got %d", res4);
        }
        if(res5 != 1){
            printf("\nmy_facto_rec expected res5 = 1 / got %d", res5);
        }
    }
    
    /////my_pwr_rec//////
    {
        int a = 5;
        int b = 10;
        int c = -10;
        int d = 0;
        int e = 1;

        int res1 = my_pwr_rec(a, 0);
        int res2 = my_pwr_rec(b, -3);
        int res3 = my_pwr_rec(c, 2);
        int res4 = my_pwr_rec(d, 2);
        int res5 = my_pwr_rec(e, 4);
        
        if(res1 != 1){
            printf("\nmy_pwr_rec expected res1 = 0 / got %d", res1);
        }
        if(res2 != 0){
            printf("\nmy_pwr_rec expected res2 = 0 / got %d", res2);
        }
        if(res3 != 100){
            printf("\nmy_pwr_rec expected res3 = 100 / got %d", res3);
        }
        if(res4 != 0){
            printf("\nmy_pwr_rec expected res4 = 0 / got %d", res4);
        }
        if(res5 != 1){
            printf("\nmy_pwr_rec expected res5 = 1 / got %d", res5);
        }
    }
}
