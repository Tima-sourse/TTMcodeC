#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char str[100], leksema_str[20];
    float res = 0;
    int j = 0;
    int operand = 1; 

    printf("Введите вычисляемое выражение: ");
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; i <= strlen(str); i++)
    {   
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            leksema_str[j] = '\0';
            res += operand * atof(leksema_str);
            strcpy(leksema_str, "");
            j = 0;
            
            if (str[i] == '-' && str[i - 1] == '-')
            {
                operand = 1;
            }
            else if (str[i] == '-' && str[i - 2] == '-' && str[i - 1] == ' ')
            {
                operand = 1;
            }
            else if (str[i] == '-') 
            {
                operand = -1;
            }
            else 
            {
                operand = 1;
            }
        }
        else
        {
            leksema_str[j++] = str[i];
        }
    }

    printf("Результат вычисления: %.2f", res);
    return 0;
}