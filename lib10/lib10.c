#include <stdio.h>
#include <windows.h>

#define MAX_NUM(x,y) ((x) > (y) ? (x) : (y))

int main()
{   
    char *num_P;
    char str[100];
    float max, num;

    printf("Введите числа для сравнения: ");
    fgets(str, sizeof(str), stdin);
    num_P = strtok(str, " ");
    max = atof(num_P);
    while(num_P != NULL)
    {
        num = atof(num_P);
        max = MAX_NUM(max, num);
        num_P = strtok(NULL, " ");
    }

    printf("Максимальное число: %.2f", max);

    return 0;
}