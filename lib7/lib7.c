#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct human
{
    char firstname[40];
    char lastname[40];
    char date[40];
};

int main()
{
    SetConsoleCP(CP_UTF8);
    int i, j, n=0, k;
    struct human num[4];
    char str[100];
    char fname[40], lname[40], date[40], sortsup[40];
    FILE *F_in = fopen("in.txt", "rt"), *F_out = fopen("out.txt", "wt");

    while (fscanf(F_in, "%s %s %s", num[n].firstname, num[n].lastname, num[n].date) != EOF)
    {
        n++;
    }


    while(j > 1) // Бабл сортировка
    {
        k=0;
        for (i = 1; i < n; ++i)
        {
            if (atoi(num[i].date) < atoi(num[i-1].date))
            {
                strcpy(sortsup, num[i].date);
                strcpy(num[i].date, num[i-1].date);
                strcpy(num[i].lastname, num[i-1].lastname);
                strcpy(num[i].firstname, num[i-1].firstname);
                strcpy(num[i-1].date, sortsup);
                k=i;
            }
        }
        j=k;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(F_out, "%s %s %s\n", num[i].firstname, num[i].lastname, num[i].date);
    }

    fclose(F_in);
    fclose(F_out);
    return 0;
}