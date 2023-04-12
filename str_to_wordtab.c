#include <stdio.h>
#include <stdlib.h>

char** str_to_wordtab(char *s);
void my_show_tab(char** tab);

int main()
{
    char str[] = " .this i.s";
    char** tab = str_to_wordtab(str);
    int i = 0;

    return 0;
}

void my_show_tab(char** tab){
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(*tab[i] != '\0'){
            printf("my tab %d:\n", i);
        while(tab[i][j] != '\0'){
            printf("c = %c", tab[i][j]);
            printf("\n");
            j++;
        }
        i++;
        j = 0;
    }
}

int my_count_words(char *s){
    int i;
    int words_count;
    
    i = 0;
    words_count = 0;
    while(s[i] != '\0'){
        if(s[i] == ' '){ 
            words_count++;
        }
        i++;
    }
    words_count += 1;
    printf("words_count : %d\n", words_count);
    return words_count;
}

int my_word_size(char* s){
    int i;
    int word_size;
    
    i = 0;
    word_size = 0;
    while(s[i] != ' ' && s[i] != '\0'){
        if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')){
            i++;
            continue;
        }
        word_size++;
        i++;
    }
    //printf("word_size : %d\n", word_size);
    return i;
}

char** str_to_wordtab(char *s){
    int i;
    int j;
    int k;
    int words_count;
    int word_size;
    int word_start;
    
    i = 0;
    word_start = 0;
    while((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')){
        i++;
        word_start++;
    }
    
    words_count = my_count_words(&s[i]);
    char **tab = malloc(sizeof(*tab) * (words_count + 1));
    
    j = 0;
    k = 0;
    while(s[i] != '\0'){
        word_size = my_word_size(&s[i]);
        tab[j] = malloc(sizeof(*tab) * (word_size + 1));
        while(s[word_start] != ' ' && s[word_start] != '\0'){
            if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')){
                i++;
                word_start++;
            }
            tab[j][k] = s[word_start];
            //printf("k = %d, tab[j][k] = %c\n", k, tab[j][k]);
            i++;
            k++;
            word_start++;
        }
        tab[j][k] = '\0';
        //printf("tab[j] = %p", tab[j]);
        //printf(" k = %d, tab[j][k] = %s\n", k, tab[j]);
        i++;
        j++;
        k = 0;
        word_start++;
    }
    tab[j] = '\0';
    my_show_tab(tab);
    return tab;
}

