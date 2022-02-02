# include <stdio.h>

enum  weekDays {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
enum deck 
{
    club = 0,
    diamonds = 5,
    hearts = 10,
    spades = 15,

}card;

int main()
{
      
    enum weekDays today;
    today = Wednesday;
    printf("Day %d \n", today+1);

    card = spades;
    printf("Card Value %d \n", card);
    printf("Size of var %d \n", sizeof(card));
    
    return 0;
}