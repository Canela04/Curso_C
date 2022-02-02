#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    time_t oneDay=24 * 60 * 60, today = time(NULL)/*forma de expresar la fecha actual en segundos*/, nextDate;
    nextDate = today + oneDay * atoi(argv[1]);

    printf("%s\n", ctime(&nextDate));

    return 0;
}