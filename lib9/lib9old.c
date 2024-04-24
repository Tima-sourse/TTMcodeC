#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char str[100], leksema_str[20], operand;
    float res = 0;
    char *leksema_p;

    printf("Введите вычисляемое выражение: ");
    fgets(str, sizeof(str), stdin);
    
    leksema_p = strtok(str, " ");
    strcpy(leksema_str, leksema_p);
    res += atof(leksema_str);

    while (leksema_p != NULL)
    {
        leksema_p = strtok(NULL, " ");
        if (leksema_p != NULL)
        {
            strcpy(leksema_str, leksema_p);
            if (strlen(leksema_str) == 1)
            {
                operand = leksema_str[0];
            }
            else if(operand == '+')
            {
                res += atof(leksema_str);
            }
            else if(operand == '-')
            {
                res -= atof(leksema_str);
            }
        }
    }

    printf("Результат вычисления: %.2f", res);
    return 0;
}