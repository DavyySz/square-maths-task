#include <stdio.h>
#include <math.h>
#include <windows.h>

//
int main() {
long double E; // beschreibt die Seitelinks über a
long double M; // beschreibt die Seite die zu den anderen quer liegt
long double J; // beschreibt die obere Seite


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //change color
    printf("With this program we can calculate the area of the square shown in the picture. For this we need the side lengths E, M and J whose designation is also shown in the picture.\n\n\n\n");


// Ermitteln der Seitenlänge von f (a= E² + M²)
printf("enter the required length E:\n");
scanf("%Lf",    &E);

printf("enter the required length M:\n");
scanf("%Lf",    &M);

printf("enter the required length J:\n");
scanf("%Lf",    &J);
printf("\n-----------------------------------\n");
 
long double f = sqrt((E * E) + (M * M));
printf("f ist=  %Lf (unit)",f);
printf("\n-----------------------------------\n");

// Winkel Alpha berechnen
long double SinusVerhältniss = M / f; // BErechnet das Seitenverhältniss Gegenkathete / Hypotenuse
long double WinkelAlphaRad = asin(SinusVerhältniss); // Berechnet den Winkel Alpha
long double WinkelAlphaGrad = WinkelAlphaRad * (180 / M_PI);

printf("the angle alpha has %Lf degrees\n", WinkelAlphaGrad);
printf("-----------------------------------\n");

// Berechnung von dem Wert der von M abgezogen werden soll
// sinBeta = (b * sinAlpha) / a  (siehe Sinussatz)
long double SinBetaRad = asin((J * sin(WinkelAlphaRad)) / f);
long double SinBetaGrad = SinBetaRad * (180 / M_PI);

printf ("the angle beta has %Lf degrees\n", SinBetaGrad);
printf("-----------------------------------\n");

// abziehenden Wert durch (Gegenkathete = Hypotenuse * SinusBeta) Berechnen
long double radian = SinBetaGrad * M_PI / 180; // Umrechnung von Grad in Radian
long double tangenswert = tan(radian); // Berechnung des Tangenswerts
long double ergebniss = J * tangenswert; // Multiplikation mit f

printf("deductible value is %Lf (unit)\n", ergebniss); 
printf("-----------------------------------\n");

long double Abziehwert = M - ergebniss;
printf("deductible value is %Lf (unit)\n",   Abziehwert);
printf("-----------------------------------\n");


// Berechnung der Seite a
long double Diagonale = (sqrt((ergebniss * ergebniss) + (J * J)) + sqrt((E * E) + (Abziehwert * Abziehwert)) );
printf("length diagonal = %Lf (unit)\n", Diagonale);
printf("-----------------------------------\n");

long double Wbogenmaß = ((45 * M_PI) / 180);
long double kosW = cos(Wbogenmaß);
long double a = (Diagonale * kosW);
printf("length a = %Lf (unit)\n", a); 
printf("-----------------------------------\n");

// Gesammtvolumen Quadrat /////////////////////////////////////////////////////////////////////////////////////// !!!!!WICHTIG!!!!!! /////////////////////////////////////////
long double V = a * a;



     // Ändern Sie die Textfarbe auf Rot
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
printf("//////////////////////////////////total area square %Lf (unit)//////////////////////////////\n", V);
 // Ändern Sie die Textfarbe auf grün
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
printf("-----------------------------------\n");



// Berechnung der Abzuziehenden Fläche AB HIER WIRD ABGEZOGEN SOOOOOOOOOOOOOOOOOOOOS



// 1: gelbes dreieck GA = (J * M) / 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long double GA = (J * M) / 2;
printf("Area yellow triangle %Lf (unit)\n", GA); ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");


// Berechnung Teilwinkel
// Hy 

long double Hy  = (sqrt((E * E) + (M * M)));                                      
printf("hypothenuse %Lf (unit)\n",  Hy);
printf("-----------------------------------\n");
long double SchweresD = (ergebniss / Hy);  // sin wert kleines dreieck
printf("sine value %Lf (unit)\n", SchweresD);
printf("-----------------------------------\n");
long double  GelberWinkelSchwer = asin(SchweresD) * (180 / M_PI);
printf("yellow angle heavy %Lf (unit)\n",  GelberWinkelSchwer);
printf("-----------------------------------\n");


long double MarcelDavis = (M / E);                      // mir gehen die Namen für die Bezeichnungen aus!
printf("Triangle M and Hy %Lf (unit)\n", MarcelDavis);
printf("-----------------------------------\n");
long double PeterLustig = asin(MarcelDavis) * (180 / M_PI);
printf("Middle triangle %Lf degree\n", PeterLustig);
printf("-----------------------------------\n");


// Winkel von Dreieck unten links berechnen (45 + GelberwinkelSchwer (8.800771 Eduards Aufgabe)) - Mittleres Dreieck (30 Eduards Aufgabe))
long double BenjaminBlümchen = (45 + GelberWinkelSchwer) - PeterLustig; // PeterLustig = MittleresDreieck
printf("Angle sine from triangle bottom left %Lf degree\n", BenjaminBlümchen);
printf("-----------------------------------\n");

// Gekenkatete vom Dreieck unten links berechnen + Volumen von dreieck unten links berechnen (blaues Dreieck) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long double GegenkL =  (BenjaminBlümchen * M_PI) / 180; // rechnet Winkelmaß in Bogenmaß um
long double WinkelA = sin(GegenkL); // rechnet den Sinuswert des Winkels aus
long double WingelEnd = asin(WinkelA); // Berechnet den Winkel vom Sinuswert in Bogenmaß
long double WinkelAbschluss = (WingelEnd * 180) / M_PI; // Rechnet den Bogenmaß Winkel in Grad um
printf("Sine angle alpha triangle bottom left %Lf (degree)\n", WinkelAbschluss); // Gibt den vertigen Winkel an
printf("-----------------------------------\n");

long double rotG = (WinkelAbschluss * M_PI) / 180; // rechnet Winkelmaß in Bogenmaß um
long double rotGe = sin(GegenkL); // rechnet den Sinuswert des Winkels aus
long double rotKp = rotGe * E; // Berechnet die Gegenkathete mit Gegenkathete = Hypothenuse * Sinus
printf("The length of the opposite side triangle bottom left %Lf (degree)\n",    rotKp);   // Das Ergebniss der Gegenkathete ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");


// Beechnung vom  Flächeninhalt blaues Dreieck unten links  ///////////////////////////////////////////////////////////////////////////////////////////
long double FLg = E * cos(WingelEnd);
printf("Ankhetus triangle bottom left %Lf (degree)\n", FLg); // berechnet die Ankathete vom Dreieck unten links
printf("-----------------------------------\n");

long double DrBlauA = (FLg * rotKp) / 2; // der Flächeninhalt vom blauen Dreieck unten links ///////////////////////////////////////////////////////////////////////
printf("Area of the blue triangle at the bottom left %Lf (unit)\n", DrBlauA); // gibt den Flächeninhalt vom blauen Dreieck uten links aus ////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");

// Berechnung rotes quadrat unten links
long double  urs = a - FLg; // Berechnung von der Seitenlänge der untersten Seite vom Quadrat unten rechts
printf("Length of the lower side of the square bottom right %Lf(unit)\n", urs);
printf("-----------------------------------\n");
long double rotQuadrat = urs * rotKp; // Flächeninhalt vom Quadrat unten rechts /////////////////////////////////////////////////////////////////////////////////////
printf("Flächeninhalt Quadrat unten rechts %Lf (unit)\n", rotQuadrat);
printf("-----------------------------------\n");

// Flächeninhalt grünes Dreieck oben rechte Seite (zeigt spitz nach oben)
long double DgrünOben = (((a - rotKp) * urs) / 2);  // Berechnung des Dreieck oben rechts grün
printf("Area of green triangle top right %Lf\n", DgrünOben); ///////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");



//Berechnung der Zwei einzelnen Hälften des Quadrats
// Hälfte unten rechts (blaues Dreieck + rotes Dreieck + grünes Dreieck + oranges Dreieck)
long double RerchteHälfte = (GA + DrBlauA + rotQuadrat + DgrünOben);
printf("The area of the right half %Lf (unit)\n",    RerchteHälfte); ////////////////////////////////////////////////////////////////////////////
printf("-----------------------------------\n");

// berechnungfür die linke Hälfte
long double LinkeHälfte = (V - RerchteHälfte);
printf("Volumen der rechten Hälfte vom Quadrat %Lf\n",    LinkeHälfte);
printf("-----------------------------------\n\n");
printf("exit program by entering the enter key  :)  ");

getchar(); // Wartet auf eine Eingabe (Enter-Taste)
getchar();

return (0);
}
