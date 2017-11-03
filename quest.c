#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    printf("- Hello friend! Bip - bop. I just made a little quest for you. Bip - bop. Hope you will enjoy it! Bip - bop.\n");
    printf("\n- You a programmer! You want to write a programm. What will you do first?\n1. Open MacBook.\n2. Through MacBook out the window.\n");
    scanf("%d", &c);
    if (c == 1)
    {
        printf("- You opened MacBook. But it is not turning on. What will you do?\n1. Check if MacBook is plugged in.\n2. Through MacBook out the window.\n");
    }
    else
    {
        printf("Congrats! You win the game!\n");
        return 0;
    }
    scanf("%d", &c);
    if (c == 1)
    {
        printf("Oops, this is the end of alpha!\n");
    }
    else
    {
        printf("Congrats! You win the game!\n");
        return 0;
    }
    return 0;
}
