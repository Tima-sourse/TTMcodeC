#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

struct humen
{
    char firstname[15];
    char lastname[15];
    int date[4];
};



int main()
{
    SetConsoleCP(CP_UTF8);
    int i;
    struct humen in[4];
    struct humen out[4];
    char str[60], str_split[3];
    
    FILE *F_in = fopen("in.txt", "rt"), *F_out = fopen("out.txt", "wt");

    while (fgets(str, 60, F_in) != NULL)
    {   
        
        for (i = 0; i < 4; i++) 
        {
            char word = strtok(str, " ");
            while (word != NULL)
            {   
                strcpy(str_split[i], word);
                word = strtok(NULL, " ");
            }
            strcpy(in[i].firstname, str_split[0]);
            strcpy(in[i].lastname, str_split[1]);
            strcpy(in[i].date, str_split[2]);
        }
        
    }
    fputs(in, F_out);

    fclose(F_in);
    fclose(F_out);
    return 0;
}