#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

void main()
{   
    SetConsoleOutputCP(CP_UTF8);
    int i, j;
    char str[81], a[2]="aA", b[2]="bB";
    
    
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
    printf("\nСтрока с заменой - %s", str);
    _getch();
}