#include <stdio.h>
#include <math.h>

//
int main() {
long double E; // beschreibt die Seitelinks über a
long double M; // beschreibt die Seite die zu den anderen quer liegt
long double J; // beschreibt die obere Seite

// Ermitteln der Seitenlänge von f (a= E² + M²)
printf("Geben sie die Länge der Seite E an:\n");
scanf("%Lf",    &E);

printf("Geben sie die Länge der Seite M an:\n");
scanf("%Lf",    &M);

printf("Geben sie die Länge der Seite J an:\n");
scanf("%Lf",    &J);
printf("\n-----------------------------------\n");
 
long double f = sqrt((E * E) + (M * M));
printf("f ist=  %Lf (Einheit)",f);
printf("\n-----------------------------------\n");

// Winkel Alpha berechnen
long double SinusVerhältniss = M / f; // BErechnet das Seitenverhältniss Gegenkathete / Hypotenuse
long double WinkelAlphaRad = asin(SinusVerhältniss); // Berechnet den Winkel Alpha
long double WinkelAlphaGrad = WinkelAlphaRad * (180 / M_PI);

printf("Der Winkel Alpha hat %Lf Grad\n", WinkelAlphaGrad);
printf("-----------------------------------\n");

// Berechnung von dem Wert der von M abgezogen werden soll
// sinBeta = (b * sinAlpha) / a  (siehe Sinussatz)
long double SinBetaRad = asin((J * sin(WinkelAlphaRad)) / f);
long double SinBetaGrad = SinBetaRad * (180 / M_PI);

printf ("Winkel Beta hat %Lf Grad\n", SinBetaGrad);
printf("-----------------------------------\n");

// abziehenden Wert durch (Gegenkathete = Hypotenuse * SinusBeta) Berechnen
long double radian = SinBetaGrad * M_PI / 180; // Umrechnung von Grad in Radian
long double tangenswert = tan(radian); // Berechnung des Tangenswerts
long double ergebniss = J * tangenswert; // Multiplikation mit f

printf("AbziehwertA %Lf in (Einheit)\n", ergebniss); 
printf("-----------------------------------\n");

long double Abziehwert = M - ergebniss;
printf("Der Abziehwert Beträgt %Lf (Einheit)\n",   Abziehwert);
printf("-----------------------------------\n");


// Berechnung der Seite a
long double a = (sqrt((ergebniss * ergebniss) + (J * J)) + sqrt((E * E) + (Abziehwert * Abziehwert)) );
printf("Länge a = %Lf (Einheit)\n", a);
printf("-----------------------------------\n");

// Gesammtvolumen Quadrat /////////////////////////////////////////////////////////////////////////////////////// !!!!!WICHTIG!!!!!! /////////////////////////////////////////
long double V = a * a;
printf("/////////////////////////////////////////////////////////Gesammtfläche Quadrat %Lf (Einheit)/////////////////////////////////////////////////////////////////\n", V);
printf("-----------------------------------\n");



// Berechnung der Abzuziehenden Fläche AB HIER WIRD ABGEZOGEN SOOOOOOOOOOOOOOOOOOOOS



// 1: gelbes dreieck GA = (J * M) / 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long double GA = (J * M) / 2;
printf("Flächeninhalt gelbes Dreieck %Lf (Einheit)\n", GA); ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");


// Berechnung Teilwinkel
// Hy 

long double Hy  = (sqrt((E * E) + (M * M)));                                      
printf("Hypotenuse %Lf (Einheit)\n",  Hy);
printf("-----------------------------------\n");
long double SchweresD = (ergebniss / Hy);  // sin wert kleines dreieck
printf("sinwert %Lf (EInheit)\n", SchweresD);
printf("-----------------------------------\n");
long double  GelberWinkelSchwer = asin(SchweresD) * (180 / M_PI);
printf("GelberWinkelSchwer %Lf (Einheit)\n",  GelberWinkelSchwer);
printf("-----------------------------------\n");


long double MarcelDavis = (M / E);                      // mir gehen die Namen für die Bezeichnungen aus!
printf("Dreieck M und Hy %Lf (Einheit)\n", MarcelDavis);
printf("-----------------------------------\n");
long double PeterLustig = asin(MarcelDavis) * (180 / M_PI);
printf("Mittleres Dreieck %Lf Grad\n", PeterLustig);
printf("-----------------------------------\n");


// Winkel von Dreieck unten links berechnen (45 + GelberwinkelSchwer (8.800771 Eduards Aufgabe)) - Mittleres Dreieck (30 Eduards Aufgabe))
long double BenjaminBlümchen = (45 + GelberWinkelSchwer) - PeterLustig; // PeterLustig = MittleresDreieck
printf("Winkel Sinus vom Dreieck unten links %Lf Grad\n", BenjaminBlümchen);
printf("-----------------------------------\n");

// Gekenkatete vom Dreieck unten links berechnen + Volumen von dreieck unten links berechnen (blaues Dreieck) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long double GegenkL =  (BenjaminBlümchen * M_PI) / 180; // rechnet Winkelmaß in Bogenmaß um
long double WinkelA = sin(GegenkL); // rechnet den Sinuswert des Winkels aus
long double WingelEnd = asin(WinkelA); // Berechnet den Winkel vom Sinuswert in Bogenmaß
long double WinkelAbschluss = (WingelEnd * 180) / M_PI; // Rechnet den Bogenmaß Winkel in Grad um
printf("Sinus Winkel Alpha Dreieck unten links %Lf (Einheit)\n", WinkelAbschluss); // Gibt den vertigen Winkel an
printf("-----------------------------------\n");

long double rotG = (WinkelAbschluss * M_PI) / 180; // rechnet Winkelmaß in Bogenmaß um
long double rotGe = sin(GegenkL); // rechnet den Sinuswert des Winkels aus
long double rotKp = rotGe * E; // Berechnet die Gegenkathete mit Gegenkathete = Hypothenuse * Sinus
printf("Die Länge der Gegenkathete Dreieck unten links %Lf (Einheit)\n",    rotKp);   // Das Ergebniss der Gegenkathete ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");


// Beechnung vom  Flächeninhalt blaues Dreieck unten links  ///////////////////////////////////////////////////////////////////////////////////////////
long double FLg = E * cos(WingelEnd);
printf("Ankathete Dreieck unten links %Lf (Einheit)\n", FLg); // berechnet die Ankathete vom Dreieck unten links
printf("-----------------------------------\n");

long double DrBlauA = (FLg * rotKp) / 2; // der Flächeninhalt vom blauen Dreieck unten links ///////////////////////////////////////////////////////////////////////
printf("Flächeninhalt vom blauen Dreieck unten links %Lf (Einheit)\n", DrBlauA); // gibt den Flächeninhalt vom blauen Dreieck uten links aus ////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");

// Berechnung rotes quadrat unten links
long double  urs = a - FLg; // Berechnung von der Seitenlänge der untersten Seite vom Quadrat unten rechts
printf("Länge der unteren Seite vom Quadrat unten rechts %Lf(Einheit)\n", urs);
printf("-----------------------------------\n");
long double rotQuadrat = urs * rotKp; // Flächeninhalt vom Quadrat unten rechts /////////////////////////////////////////////////////////////////////////////////////
printf("Flächeninhalt Quadrat unten rechts %Lf (Einheit)\n", rotQuadrat);
printf("-----------------------------------\n");

// Flächeninhalt grünes Dreieck oben rechte Seite (zeigt spitz nach oben)
long double DgrünOben = (((a - rotKp) * urs) / 2);  // Berechnung des Dreieck oben rechts grün
printf("Flächeninhalt grünes Dreieck oben rechts %Lf\n", DgrünOben); ///////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");



//Berechnung der Zwei einzelnen Hälften des Quadrats
// Hälfte unten rechts (blaues Dreieck + rotes Dreieck + grünes Dreieck + oranges Dreieck)
long double RerchteHälfte = (GA + DrBlauA + rotQuadrat + DgrünOben);
printf("Der Flächeninhalt der rechten Hälfte %Lf (Einheit)\n",    RerchteHälfte); ////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");

// berechnungfür die linke Hälfte
long double LinkeHälfte = (V - RerchteHälfte);
printf("Volumen der rechten Hälfte vom Quadrat %Lf\n",    LinkeHälfte);
printf("-----------------------------------\n\n");
printf("PROGRAMMENDE");
return (0);
}
