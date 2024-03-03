#include <stdio.h>
#include <windows.h>
#include <math.h>
int math1();
int math2();
int a, b, c, P, S;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    printf("Введите длины сторон черех пробел: ");
    scanf("%d %d %d", &a , &b , &c);
    
    if ((a + b > c) && (a + c > b) && (b + c > a))
    { 
        P = math1();
        printf("Периметр треугольника - %d", P);

        printf("\n");

        S = math2();
        printf("Площадь треугольника - %d", S);
    }
    else 
    {
        printf("Треугольник не существует");
    }

    _getch();
}

int math1()
{
    P = a + b + c;
    return P;
}

int math2()
{  
    int p = P/2;
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    return S;
}