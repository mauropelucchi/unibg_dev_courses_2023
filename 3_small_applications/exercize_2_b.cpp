/*

Scrivere un programma che legge da stdin un numero intero positivo n e stampa a video le 
prime  n  righe del triangolo di Floyd (un triangolo rettangolo che contiene 
tutti i numeri naturali disposti come segue). 
Ad esempio, per n=10 :

  1
  2   3
  4   5   6
  7   8   9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31 32 33 34 35 36
37 38 39 40 41 42 43 44 45
46 47 48 49 50 51 52 53 54 55

La soluzione più immediata utilizza due cicli annidati. 
Si progetti, come esercizio di "elasticità espressiva", anche una 
soluzione che usa un solo ciclo.

Variante (probabilmente a prima vista non banale)
Si stampi il triangolo partendo dall'ultima riga (nell'es.: da 46):

46 47 48 49 50 51 52 53 54 55
37 38 39 40 41 42 43 44 45
29 30 31 32 33 34 35 36
22 23 24 25 26 27 28
...

*/

#include <iostream> 
using namespace std; 

int main( ) {
  int i, j, n, counter;

  do {
     cout <<  "\n Inserisci un numero positivo: ";
     cin >> n; 
  } while (n <= 0);

  counter = 1; // conteggia il numero di righe 
  for (i = 1; i <= (n*(n+1))/2; ++i) {
     cout << i;  

     if ( i == (counter*(counter+1))/2 ) { 
       cout << "\n"; 
       counter += 1;   
     }
     else {  
       cout << " ";
     }
  } 
 

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   //
   // for Windows Users use
   //
   // system("pause");
   return 0;
} // end main 

