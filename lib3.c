#include <stdio.h>
#include <windows.h>
#include <string.h>

void main()
{   
    SetConsoleOutputCP(CP_UTF8);
    int i, j, end=1;
    char str[81], a[2]="aA", b[2]="bB";
    
    while (end != 0)
    {
        printf("Введите строку - ");
        scanf("%s", &str);
        for (i = 0; i < strlen(str) ; i++)
        {
            if (str[i] == a[0])
            {
                str[i] = a[1];
            }
            if (str[i] == b[0])
            {
                str[i] = b[1];
            }
        }
        printf("\nСтрока с заменой - %s\n", str);
        printf("\n\nЧто сделать: 0-закрыть программу | любое другая цифра-повторить\n>> ");
        scanf("%d", &end);
    }
}
