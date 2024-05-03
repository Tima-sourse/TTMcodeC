
#include <stdio.h>
#include <time.h>
#include <string.h>
int month_days(int m, int y);

int main() 
{   
    struct tm date;
    time_t time_date;
    char *weekday[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    char *month[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    char str[20];
    int week_int = 0, day_int = 0;

    printf("Что нужно сделать?\n Введите ДД.ММ.ГГГГ - получить день недели\n Введите ММ.ГГГГ - получить календарь за месяц\n Введите ГГГГ - получить календарь за год\n Введите now - получить текущую дату\n");
    printf("\nВведите нужный формат - ");
    fgets(str, sizeof(str), stdin);
    

    if (strlen(str) == 11)
    {      
        sscanf(str, "%d.%d.%d", &date.tm_mday, &date.tm_mon, &date.tm_year);

        date.tm_mon -= 1;
        date.tm_year -= 1900;
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        date.tm_isdst = -1; 
        time_date = mktime(&date);

        printf("\nДень недели: %s", weekday[date.tm_wday]);
    }

    if (strlen(str) == 8)
    {
        sscanf(str, "%d.%d", &date.tm_mon, &date.tm_year);
        date.tm_mday = 1;
        date.tm_mon -= 1;
        date.tm_year -= 1900;
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        date.tm_isdst = -1;   
        time_date = mktime(&date);

        printf("\n               %s\n", month[date.tm_mon]); 
        printf("  Пнд  Втр  Срд  Чтв  Птн  Сбт  Вск\n");
        week_int = date.tm_wday-1; if(week_int == -1){week_int = 6;}//фикс английского представления дней недели

        for (int i = 0; i < week_int; i++) 
        {
            printf("     ");
        }

        day_int = month_days(date.tm_mon+1, date.tm_year+1900);
        for (int i = 1; i <= day_int; i++) 
        {
            printf("%5d", i);
            if ((week_int + i) % 7 == 0 || i == day_int)
            {
                printf("\n");
            }
        }
    }

    if (strlen(str) == 5)
    {               
        sscanf(str, "%d", &date.tm_year);
        date.tm_mday = 1;
        date.tm_mon = 0;
        date.tm_year -= 1900;
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        date.tm_isdst = -1;   
        time_date = mktime(&date);

        for (int j = 0; j < 12; j++)
        {
            printf("\n               %s\n", month[date.tm_mon]);  
            printf("  Пнд  Втр  Срд  Чтв  Птн  Сбт  Вск\n");
            week_int = date.tm_wday-1; if(week_int == -1){week_int = 6;} //фикс английского представления дней недели

            for (int i = 0; i < week_int; i++) 
            {
                printf("     ");
            }

            day_int = month_days(date.tm_mon+1, date.tm_year+1900);
            for (int i = 1; i <= day_int; i++) 
            {
                printf("%5d", i);
                if ((week_int + i) % 7 == 0 || i == day_int)
                {
                    printf("\n");
                }
            }

            date.tm_mon += 1;
            time_date = mktime(&date);
        }
    }

    if (strlen(str) == 4)
    {
        time(&time_date);
        struct tm *now = localtime(&time_date);
        printf("Текущая дата: %d.%d.%d", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    return 0;
}

int month_days(int m, int y) 
{
    if (m == 2) 
    {
        return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0) ? 29 : 28;
    } 
    else if (m == 4 || m == 6 || m == 9 || m == 11) 
    {
        return 30;
    } 
    else 
    {
        return 31;
    }
}