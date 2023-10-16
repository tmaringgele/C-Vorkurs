# Setup
## Kompilieren
```terminal
gcc -Wall -Wextra -o hello.o hello.c
```

# Operatoren

## Inkrement/Dekrement

```C
int n = 3;

//n wird vor benutzung inkrementiert
x = ++n; // x == 4, n == 4

int n = 3;
//n wird nach benutzung inkrementiert
x = n++; // x == 3, n == 4
```

## Komma-Operator
* Auswertung von links nach rechts
* Ergebnis ist der Wert des letzten Ausdrucks
```C
void reverse_string (char s[]){
    int i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++; j--){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
```
Im Grunde äquivalent zu bspw. einem setzen von ```i = 0``` vor der Schleife.

# Funktionen
Funktionen müssen in .c Dateien am beginn deklariert werden! (Oder **vor** dem Funktionsaufruf definiert werden) \
Beispiel:
```C
#include <stdio.h>
#include <math.h>

int doubled(int);

int main() {
    printf("Hallo Welt! %f \n ", sin(0));
}

int doubled (int a) {
    return 2 * a;
}
```

# Modularisierung
```rot13.c``` benutzt die Funktion ```f```

```C
#include <stdio.h>
#include <stdlib.h>
#include "mein_f.h"

#define MAX_LINE_SZ 1024

extern char f(char, unsigned int);

int main() {
    char buf[MAX_LINE_SZ];
   
     while (fgets(buf, sizeof(buf), stdin)) {
        size_t n = 0;
        for (n = 0; n < sizeof(buf) && buf[n]; n++) {
            printf("%c", f(buf[n], 13u));
        }
    } 

    return EXIT_SUCCESS;
}
```
Die Funktion f ist ausgelagert in ```mein_f.c```:
```C
#include <ctype.h>

char f(char c, unsigned int ofs) {
    return toupper(c);
}
```
mit Headerdatei ```mein_f.h```:
```C
#ifndef MEIN_H_INCLUDED
#define MEIN_H_INCLUDED
char f(char, unsigned int);
#endif
```

## Komplieren
Die Module müssen zuerst einzeln kompiliert werden: 
```C
gcc -c mein_f.c //erzeugt mein_f.o
gcc -c rot13.c //erzeugt rot13.o
```
Am ende wird dann alles zusammengefügt
```C
gcc -o app.o mein_f.o rot13.o //erzeugt app.o
```

# Pointer

Seiteneffekte existieren nur für Pointer Variablen.
Wenn eine Funktion mit einer normalen Variable als Parameter aufgerufen wird, wird diese für die Verwendung innerhalb der Funktion kopiert. Das Original bleibt unberührt:
```C
int main() {
    int a = 4;
    doubled(a);
    printf("Hallo Welt! %d \n ", a);
}

void doubled (int a) {
    a = a * 2;
}
```
Output: ```Hallo Welt! 4 ```

Um einen Seiteneffet für eine Variable zu erzeugen muss der Pointer dieser Variable übergeben werden.
Die aufgerufene Funktion kann, dann den Pointer auf einen anderen Wert zeigen lassen um somit einen Seiteneffekt zu erzeugen.



```C
int main() {
    int vier = 4;
    doubled(&vier);

    printf("Hallo Welt! %d \n ", vier);
}

void doubled (int *aptr) {
    *aptr = *aptr *  2;
   
}
```
Output: ```Hallo Welt! 8 ```

## Ergebnisparameter
Hier wird zuerst ein Platzhalter für das Ergebnis reserviert und dann mit einem Seiteneffekt befüllt:
```C
int main() {
    int *result = malloc(sizeof(int));

    sieben(result);

    printf("Hallo Welt! %i \n ", *result);
}

void sieben (int *aptr) {
    int seven = 7;
    *aptr = seven;
}
```