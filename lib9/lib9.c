#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
float sum(char *num1, char *num2);
float diff(char *num1, char *num2);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char str[100], num1[50], num2[50], operand;
    float res;

    printf("Введите вычисляемое выражение: ");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%s %c %s", num1, &operand, num2);
    

    if (operand == '+')
    {
        res = sum(num1, num2);
    }
    else
    {
        res = diff(num1, num2);
    }

    printf("Результат вычисления: %.2f", res);

    return 0;
}

float sum(char *num1, char *num2)
{   
    return (atof(num1) + atof(num2));
}

float diff(char *num1, char *num2)
{   
    return (atof(num1) - atof(num2));
}