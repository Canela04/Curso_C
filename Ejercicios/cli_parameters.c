#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("Argumento %d = %s\n", i, argv[i] );
    }

    char buffer[20];
    char * buffer2 = "This will be overwritten";

    printf("Original buffer2: %s\n", buffer2);
    if (buffer >= argv[1])
    {
        strcpy(buffer, argv[1]);
        printf("New buffer2: %s\n", buffer2);
    }else{
        printf("No se pudo copiar el argumento \nNew buffer2: %s\n", buffer2);
    }
    return 0;
}
