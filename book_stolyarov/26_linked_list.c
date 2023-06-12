#include <stdio.h>
#include <stdlib.h>

struct item{
    int data;
    struct item *next;
};

struct item *int_array_to_list(const int *arr, int len){
    struct item *tmp;
    if (!len)
        return NULL;
    tmp = malloc(sizeof(struct item));
    tmp->data = *arr;
    tmp->next = int_array_to_list(arr + 1, len - 1);
    return tmp;

}
// struct item *int_array_to_list(const int *arr, int len){
//     struct item *first = NULL, *last = NULL, *tmp;
//     int i;
//     for (i = 0; i < len; i++){
//         tmp = malloc(sizeof(struct item));
//         tmp->data = arr[i];
//         tmp->next = first;
//         first = tmp;
//     }
//     return first;
// }




int main(){
    
    return 0;
}