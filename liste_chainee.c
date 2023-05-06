#include <stdio.h>
#include <stdlib.h>

struct s_list{
    int i;
    struct s_list *next;
};

int list_len(struct s_list **begin){
    int i;
    struct s_list *ptr = *begin;
    
    i = 0;
    while(ptr != 0){
        ptr = ptr->next;
        i++;
    }
    return i;
}

void list_push_front(struct s_list **begin, int value){
    struct s_list *new_node = 0;
    
    new_node = malloc(sizeof(*new_node));
    new_node->i = value;
    new_node->next = *begin;
    *begin = new_node;
}

void list_push_back(struct s_list **begin, int value){
    struct s_list *ptr = *begin;
    struct s_list *new_node = 0;
    
    new_node = malloc(sizeof(*new_node));
    new_node->i = value;
    new_node->next = 0;
    
    while(ptr->next != 0){
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void remove_node(struct s_list **begin, int pos){
    int i;
    
    if (pos == 0){
        struct s_list *tmp = *begin;
        *begin = (*begin)->next;
        free(tmp);
        return;
    }
    
    struct s_list *idx = *begin;
    i = 0;
    
    while(idx != NULL && i < pos - 1){
        idx = idx->next;
        i++;
    }

    if(idx == NULL || idx->next == NULL){
        return;
    }

    struct s_list *tmp = idx->next;
    idx->next = idx->next->next;
    free(tmp);
}

struct s_list *get_node(struct s_list *begin, int pos) {
    int i;
    
    if (begin == NULL || pos < 0) {
        return NULL;
    }
    
    struct s_list *idx = begin;
    
    i = 0;
    while(i < pos) {
        idx = idx->next;
        i++;
    }
    
    return idx;
}

void rev_list(struct s_list **begin){
    int i;
    int tmp;
    
    if (*begin == NULL){
        return;
    }
    
    int size = list_len(begin);
    int middle = size / 2;
    struct s_list *a = *begin;
    struct s_list *b = *begin;
    
    i = 0;
    while(i < size - 1) {
        b = b->next;
        i++;
    }
    
    i = 0;
    while(i < size / 2){
        tmp = a->i;
        a->i = b->i;
        b->i = tmp;
        printf("a->i = %d\n", a->i);
        printf("b->i = %d\n", b->i);
        
        a = a->next;
        b = get_node(*begin, size - i - 1);
        printf("getnodeb = %d\n", b->i);
        
        i++;
    }
}

int main()
{
    struct s_list *l = 0;
    struct s_list *tmp = 0;
    
    list_push_front(&l, 5);
    list_push_front(&l, 4);
    list_push_front(&l, 3);
    list_push_front(&l, 2);
    list_push_front(&l, 1);
    list_push_back(&l, 6);
    //remove_node(&l, 5);
    
    tmp = l;
    
    while(tmp != 0){
        printf("%d\n", tmp->i);
        tmp = tmp->next;
        
    }
    
    rev_list(&l);
    
    int length = list_len(&l);
    
    printf("length = %d\n", length);
    return 0;
}
