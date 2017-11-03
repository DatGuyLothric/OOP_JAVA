#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char n;
    int i = 0, j = 0, k, l, p = 0, g;
    char a[256];
    char b[256];
    printf("- What do you want me to help you with?\n- Help me to chose between: ");
    while (p != 1)
    {
        n = getchar();
        ungetc(n, stdin);
        scanf("%c", &a[i]);
        i++;
        if (n == '&')
            p = 1;
    }
    k = i;
    p = 0;
    while (p != 1)
    {
        n = getchar();
        ungetc(n, stdin);
        scanf("%c", &b[j]);
        j++;
        if (n == '!')
            p = 1;
    }
    l = j;
    printf("- I think you must chose: ");
    srand(time(NULL));
    g = rand()%2;
    if (g == 0)
    {
        for (i = 0; i < k - 2; i++)
        printf("%c", a[i]);
    }
    else
    {
        for (j = 1; j < l - 1; j++)
        printf("%c", b[j]);
    }
    printf("!");
    return 0;
}
