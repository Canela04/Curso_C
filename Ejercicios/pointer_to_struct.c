#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char NAME [100];
typedef int AGE;

struct PERSON{
    NAME name;
    AGE age;
};

void fillPersonData(struct PERSON *person, const char *name, int age)
{
    if (strlen (name) < 100)
    {
        //son lo mismo
        //strcpy((*person).name, name);
        strcpy(person->name, name);
    }
    person->age = age;
}

int main(int argc, char const *argv[])
{
    struct PERSON person;

    if (argc < 3)
    {
        printf("Indique nombre y edad porfavor\n");
        return 1;
    }

    fillPersonData(&person, argv[1], atoi(argv[2]));

    //person.age = atoi(argv[2]); atoi permite convertir un string a entero

    printf("Name = %s, age = %d\n", person.name, person.age);
    
    return 0;
}

