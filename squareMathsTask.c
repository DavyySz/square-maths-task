#include <stdio.h>
#include <math.h>

//
int main() {
long double E; // beschreibt die Seitelinks über a
long double M; // beschreibt die Seite die zu den anderen quer liegt
long double J; // beschreibt die obere Seite

// Ermitteln der Seitenlänge von f (a= E² + M²)
printf("Geben sie die Länge der Seite E an:\n ");
scanf("%Lf",    &E);

printf("Geben sie die Länge der Seite M an:\n");
scanf("%Lf",    &M);

printf("Geben sie die Länge der Seite J an:\n");
scanf("%Lf",    &J);

long double f = sqrt((E * E) * (M * M));
printf("Das Ergebniss ist:  %Lf\n",f);
return (0);
}