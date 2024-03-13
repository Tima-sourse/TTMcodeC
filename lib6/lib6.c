#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{   
    SetConsoleCP(CP_UTF8);
    int i, j;
    double limit_f;
    char str[60], limit_s[4];
    FILE *F_in = fopen("in.txt", "rt"), *F_out = fopen("out.txt", "wt");

    while (fgets(str, 60, F_in) != NULL)
    {
        for (i = 0; i < 61; i++)
        {
            if ((str[i] == '1') && (str[i + 1] == '9'))
            {   
                limit_s[0] = str[i];
                limit_s[1] = str[i + 1];
                limit_s[2] = str[i + 2];
                limit_s[3] = str[i + 3];
                limit_f = atof(limit_s);
                if (limit_f > 1980)
                {   
                    fputs(str, F_out);
                    printf("%s", str);
                }
                
            }
        }
    }

    fclose(F_in);
    fclose(F_out);
    return 0;
}