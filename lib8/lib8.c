#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b);

struct humen
{
    char firstname[40];
    char lastname[40];
    int date;
    char gender[1];
    float height;
};

struct humen people[10];


int num_factors, factors[5], comparison;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    FILE *f_in = fopen("in.txt", "r");
    if (f_in == NULL)
    {
        printf("Error: Не удалось открыть файл in.txt\n");
        return 1;
    }

    int i = 0;
    while (fscanf(f_in, "%s %s %d %s %f", people[i].firstname, people[i].lastname, &people[i].date, people[i].gender, &people[i].height) != EOF)
    {
        i++;
    }
    fclose(f_in);


    printf("Введите количество полей для сортировки: ");
    scanf("%d", &num_factors);
    getchar();

    int j;
    printf("Введите номера полей для сортировки (1 - имя | 2 - фамилия | 3 - год рождения | 4 - пол | 5 - рост): \n");
    for (j = 0; j < num_factors; j++) 
    {
        scanf("%d", &factors[j]);
        getchar();
    }
	
	qsort(people, i, sizeof(struct humen), comp);

    
    for(j = 0; j < i; j++) 
    {
        printf("%s %s %d %s %.2f\n", people[j].firstname, people[j].lastname, people[j].date, people[j].gender, people[j].height);
	}

    return 0;
}


int comp(const void *a, const void *b)
{
    struct humen *person_a = (struct humen *)a;
    struct humen *person_b = (struct humen *)b;
    int i;
    for (i = 0; i < num_factors; i++)
    {
        switch (factors[i])
        {
        case 1:
        { 
            comparison = strcmp(person_a->firstname, person_b->firstname);
            if (comparison != 0)
            {
                return comparison;
            }
            break;
        }

        case 2: 
        {
            comparison = strcmp(person_a->lastname, person_b->lastname);
            if (comparison != 0)
            {
                return comparison;
            }
            break;
        }

        case 3: 
        {
            if (person_a->date != person_b->date)
            {
                return person_a->date - person_b->date;
            }
            break;
        }

        case 4: 
        {
            comparison = strcmp(person_a->gender, person_b->gender);
            if (comparison != 0)
            {
                return comparison;
            }
            break;
        }

        case 5:
        {
            if (person_a->height != person_b->height)
            {
                return (person_a->height > person_b->height) - (person_a->height < person_b->height);
            }
            break;
        }
        }
    }
}