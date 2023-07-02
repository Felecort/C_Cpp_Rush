#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_len(char * s){
    int counter = 0;
    while(s[counter] != '\0')
        counter++;
    // counter++;
    return counter;
}


char *convert(char *string, int num_rows){
    if (num_rows == 1) return string;
    int total_step = num_rows * 2 - 2;
    int string_length = get_len(string);
    char *new_s_arr = malloc(sizeof(string[0]) * (string_length + 1));
    int index, step_1, step_2;
    int index_new_arr = 0;

    for (int row = 0; row < num_rows; row++){
        index = row;
        if (index >= string_length) break;
        step_1 = total_step - (row * 2);
        step_2 = total_step - step_1;
        while (1)
        {
            if(step_1 != 0){
               new_s_arr[index_new_arr] = string[index];
               index += step_1;
               index_new_arr++;
            }
            if (index >= string_length) break;

            if(step_2 != 0){
               new_s_arr[index_new_arr] = string[index];
               index += step_2;
               index_new_arr++;
            }
            if (index >= string_length) break;
        }
    }
    // strcpy(string, new_s_arr);
    // free(new_s_arr);
    new_s_arr[index_new_arr] = '\0';
    return new_s_arr;
}


int main(void){

    char arr[] = "PAYPALISHIRING";
    int num_rows = 4;
    char * new_srt;
    new_srt = convert(arr, num_rows);

    printf("%s", new_srt);
    return EXIT_SUCCESS;
}