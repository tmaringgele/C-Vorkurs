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