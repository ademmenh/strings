#include <stdio.h>

int main ()
{
    char Buffer [6];
    char Buffer2 [6];
    printf ("Enter your string: ");
    scanf ("%5s", Buffer);
    printf ("%s\n", Buffer);
    scanf ("%5s", Buffer2);
    printf ("%s\n", Buffer2);
    
    return 0;
}