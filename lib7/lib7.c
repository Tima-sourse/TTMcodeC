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
    int i,j;
    struct human in[4];
    struct human out[4];
    char str[100];
    char fname[40], lname[40], Sdate[40];
    int sortdate=2024, sortsup, sortdatesup=1900;
    FILE *F_in = fopen("in.txt", "rt"), *F_out = fopen("out.txt", "wt");

    for (i=0; i < 4; i++)
    {
        if (fgets(str, 100, F_in) != NULL)
        {
            sscanf(str, "%s %s %s", fname, lname, Sdate);
            strcpy(in[i].firstname, fname);
            strcpy(in[i].lastname, lname);
            strcpy(in[i].date, Sdate);
        }
    }
    
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            if ((atoi(in[j].date) < sortdate) && (atoi(in[j].date) > sortdatesup))
            {
                sortdate = atoi(in[j].date);
                sortsup = j;
            }
        }   
        sortdatesup = sortdate;
        sortdate = 2024;

        strcpy(out[i].firstname, in[sortsup].firstname);
        strcpy(out[i].lastname, in[sortsup].lastname);
        strcpy(out[i].date, in[sortsup].date);
    }

    for (i = 0; i < 4; i++)
    {   
        fprintf(F_out, "%s %s %s\n", out[i].firstname, out[i].lastname, out[i].date);
    }

    fclose(F_in);
    fclose(F_out);
    return 0;
    
}