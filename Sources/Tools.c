#include "../Includes/Tools.h"
#include <stdbool.h>
#include <stdio.h>
struct calc
{
    double a,c;
    char b, rep;
}ca;
void calculs()
{
    switch (ca.b) {
        case '+': {
            printf("Result : %lf\n", ca.a + ca.c); break;
        }
        case '-': {
            printf("Result : %lf\n", ca.a - ca.c); break;
        }
        case '*': {
            printf("Result : %lf\n", ca.a * ca.c); break;
        }
        case '/': {
            if (ca.c == 0)
            {
                printf("Have you ever seen somebody who divide by 0 ? A**hole \n"); break;
            }
            if (ca.c != 0)
            {
                printf("Result : %lf\n", ca.a / ca.c); break;
            }
        }
        default :
            printf("Try another operator\n"); break;
    }
}

void calcul()
{
    bool play = true;
    while (play == true) {
    printf("Calcul :\n");
    scanf("%lf %c %lf", &ca.a, &ca.b, &ca.c);
    calculs();
    printf("Again ? y/n\n");
    scanf("%s", &ca.rep);
    if (ca.rep == 'n')
    {
        play = false;
    }
    }
}

