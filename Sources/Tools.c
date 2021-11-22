#include "../Includes/Tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct line
{
    char *line;
}c;

struct tab
{
    char tab[100][100];

}t;

struct prio
{
    int prio;   
}p;

void my_getnextline()
{
    FILE *fp;
    size_t len = 0;
    ssize_t read;

    read = getline(&c.line, &len, stdin);
}
void load()
{
     int i = 0, j = 0;

    for (int n = 0; c.line[n] != '\0'; n++)
    {
        if (c.line[n] >= '0' && c.line[n] <= '9' )
        {
            t.tab[i][j] = c.line[n];
            j++;
        }

        if(c.line[n] == '+' || c.line[n] == '-' || c.line[n] == '*' || c.line[n] == '/'){
            i++;
            j = 0;
            t.tab[i][j] = c.line[n];
            i++;
        }
    }   
}

void seek()
{
    bool ismult = false;
    int i = 0;
    p.prio = 0;
    while (t.tab[i][0] != '\0')
    {
        if (t.tab[i][0] == '+' || t.tab[i][0] == '-' && ismult == false)
        {
            p.prio = i;
        }

        if (t.tab[i][0] == '/' || t.tab[i][0] == '*')
        {
            ismult = true;
            p.prio = i;
        }
        i++;
    }
}

void calcul()
{
    int a, b, res;
    a = atoi(t.tab[p.prio - 1]);
    b = atoi(t.tab[p.prio + 1]);
    if (p.prio != 0)
    {
       switch (t.tab[p.prio][0]) {
            case '+': {
                res = a + b;
                break;
            }
            case '-': {
            res = a - b;
            break;
        }
        case '*': {
            res = a * b;
            break;
        }
        case '/': {
            if (b == 0)
            {
                printf("Have you ever seen somebody who divide by 0 ? A**hole \n");
                break;
            }
            if (b != 0)
            {
                res = a / b;
                break;
            }
        }
        default :
        printf("Opperator error");
        exit (0);
        break;
    }

    printf("%s", t.tab[p.prio-1]);
    seek();
    calcul(p.prio);
    }
}

void test() {
    int a = atoi(t.tab[p.prio - 1]);
    printf("%d\n", a);
    printf("%s", t.tab[p.prio-1]);
}