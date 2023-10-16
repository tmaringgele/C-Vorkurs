#include <stdio.h>
#include <stdlib.h>

enum gebaecksorten
{
    toast,
    schwarzbrot,
    croissant,
};

typedef enum gebaecksorten sorte;

void gebaeck(sorte g){

    char *s;
    switch (g)
    {
    case toast:
        s = "toast";
        break;
    
    case schwarzbrot:
        s = "schwarzbrot";
        break;
    
    case croissant:
        s = "croissant";
        break;

    default:
        s = "smth went wrong";
        break;
    }

    printf("Mhhm, heute habe ich lust auf %s \n", s);
}

int main()
{
    gebaeck(croissant);
}
