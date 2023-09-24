/*

Scrivere un programma in linguaggio C che risolva il problema seguente.
Leggere un polinomio di grado n a coefficienti reali e valutarlo in un dato punto x.



*/

#include <iostream>
#define MAX_LEN 100
using namespace std;

int main(int argc, char *argv[])
{
   float V[MAX_LEN];
   float pot, f, x;
   int i, n;

   do
   {
      cout << "\ninserire il grado del polinomio, n = ";
      cin >> n;
   } while ((n <= 0) || (n >= MAX_LEN));
   
   cout << "\ninserire i coeff. del pol. V_" << n << " … V_0:  \n";
   i = 0;
   do
   {
      cin >> V[i];
      i++;
   } while (i <= n);

   cout << "\nInserire il valore in cui valutare il polinomio, x = ";
   cin >> x;

   f = 0;
   pot = 1;
   for (i = n; i >= 0; i--)
   {
      f = f + V[i] * pot;
      pot = pot * x;
   }

   cout << "\n f(" << x << ") = " << f << ".\n ";

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
