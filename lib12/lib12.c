
#include <stdio.h>
#include <time.h>

int main() 
{
    struct tm date;
    time_t time_date;

    char *weekday[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};

    printf("Введите дату в формате ДД.ММ.ГГГГ: ");
    scanf("%d.%d.%d", &date.tm_mday, &date.tm_mon, &date.tm_year);

    date.tm_mon -= 1;
    date.tm_year -= 1900;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    time_date = mktime(&date);

    printf("День недели: %s\n", weekday[date.tm_wday]);

    return 0;
}
