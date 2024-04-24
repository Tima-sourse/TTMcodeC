#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_ARR(arr, len) ({ \
    double _max = arr[0]; \
    for (int _i = 1; _i < len; _i++) { \
        if (arr[_i] > _max) { \
            _max = arr[_i]; \
        } \
    } \
    _max; \
})

int main() 
{
    double num_arr[50];
    int count = 0;
    char str[100];
    char *str_p = str;

    printf("Введите числа для сравнения (через пробел): ");
    fgets(str, sizeof(str), stdin);

    while (*str_p != '\0') 
    {
        char *stop;
        double num = strtod(str_p, &stop);
        if (str_p == stop) 
        {
            break;
        }
        num_arr[count++] = num;
        str_p = stop;
    }

    double max_num = MAX_NUM_ARR(num_arr, count);
    printf("Максимальное число: %.2f\n", max_num);

    return 0;
}