#include <stdio.h>
#include <stdlib.h>

char* my_strcpy(char* dest, const char* src);
char *my_strdup(const char *s1);
void my_show_tab(char** tab);
struct s_param *args_to_structs(int argc, char **argv);

struct s_param {
    char *param;
    int position;
    char **param_tab;
    char *param_copy;
};
typedef struct s_param t_param;

void show_args_structs(t_param *args);

char* my_strcpy(char* dest, const char* src){
	int i;
	i = 0;
		
	while(src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char *my_strdup(const char *s1){
    char *s2 = malloc(sizeof(s1));
    
    if(s2 == NULL){
        return NULL;
    }
    my_strcpy(s2, s1);
    return s2;
}

struct s_param *args_to_structs(int argc, char **argv) {
    int i;
    struct s_param *params = malloc(sizeof(struct s_param) * (argc + 1));
    
    i = 0;
    while(i < argc) {
        params[i].param = argv[i];
        params[i].position = i;
        params[i].param_copy = my_strdup(argv[i]);
        //params[i].param_tab = str_to_wordtab(*argv);
        i++;
    }
    params[i].param = '\0';
    params[i].position = -1;
    params[i].param_copy = '\0';
    //params[i].param_tab = '\0';

    return params;
}

void show_args_structs(t_param *args) {
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(args[i].param != '\0') {
        printf("param: %s, position: %d, copy: %s, ", args[i].param, args[i].position, args[i].param_copy);
        i++;
    }
}

int main(int argc, char **argv) {
    int i;
    char *arr[2] = {"-o", "ff"};
    
    i = 0;
    t_param *params = args_to_structs(sizeof(arr) / sizeof(arr[i]), arr);
    show_args_structs(params);
  
    return 0;
}
