# include <stdio.h>

const char NEWLINE = '\n';
#define PAPERCOST 3

int main()
{
    float costoPapel;
    float numberOfSheets = 3;
    costoPapel = PAPERCOST * numberOfSheets;
    printf("Total bill: %c %f", NEWLINE,costoPapel);

    return 0;
}
