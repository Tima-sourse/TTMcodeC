#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum) 
{
    switch(signum) 
    {
        case SIGABRT:
            printf("Получен сигнал SIGABRT\n\n");
            break;
        case SIGFPE:
            printf("Получен сигнал SIGFPE\n\n");
            break;
        case SIGILL:
            printf("Получен сигнал SIGILL\n\n");
            break;
        case SIGINT:
            printf("Получен сигнал SIGINT\n\n");
            break;
        case SIGSEGV:
            printf("Получен сигнал SIGSEGV\n\n");
            break;
        case SIGTERM:
            printf("Получен сигнал SIGTERM\n\n");
            break;
        default:
            printf("Получен неизвестный сигнал %d\n\n", signum);
    }
}

int main() 
{   
    int signum;

    signal(SIGABRT, handler);
    signal(SIGFPE, handler);
    signal(SIGILL, handler);
    signal(SIGINT, handler);
    signal(SIGSEGV, handler);
    signal(SIGTERM, handler);

    while(1) 
    {
        printf("Выберите сигнал для генерации:\n");
        printf("1. SIGABRT\n");
        printf("2. SIGFPE\n");
        printf("3. SIGILL\n");
        printf("4. SIGINT\n");
        printf("5. SIGSEGV\n");
        printf("6. SIGTERM\n");
        printf("7. Выход\n");
        scanf("%d", &signum);

        switch(signum) 
        {
            case 1:
                raise(SIGABRT);
                break;
            case 2:
                raise(SIGFPE);
                break;
            case 3:
                raise(SIGILL);
                break;
            case 4:
                raise(SIGINT);
                break;
            case 5:
                raise(SIGSEGV);
                break;
            case 6:
                raise(SIGTERM);
                break;
            case 7:
                printf("Выход из программы\n");
                return 0;
            default:
                printf("Неверный выбор\n");
        }
    }

    return 0;
}