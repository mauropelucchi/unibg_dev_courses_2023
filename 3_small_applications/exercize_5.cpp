/*

Scrivere un programma che acquisisca una sequenza di 10 interi positivi e visualizzi
l’istogramma corrispondente, come illustrato di seguito.

Variante: considerare anche valori numeri negativi o nulli. 

Element        Value        Histogram
      0           19        *******************
      1            3        ***
      2           15        ***************
      3            7        *******
      4           11        ***********
      5            9        *********
      6           13        *************
      7            5        *****
      8           17        *****************
      9            1        *



*/

#include <iomanip>
#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

int main()
{

   int i, vett[SIZE];

   cout << "\n Inserisci 10 numeri interi positivi: ";
   for (i = 0; i < SIZE; i++)
   {
      do
      {
         cin >> vett[i];
      } while (vett[i] <= 0);
   }

   int rigo, max = vett[0];
   for (i = 1; i < SIZE; i++)
   { // Calcola max di vett[]
      if (max < vett[i])
         max = vett[i];
   }

   cout << "Element"
        << "     "
        << "Value"
        << "     ";
   cout << "Histogram" << endl;

   for (rigo = 0; rigo < SIZE; rigo = rigo + 1)
   {
      cout << setw(7) << rigo << "     ";
      cout << setw(5) << vett[rigo] << "     ";
      for (i = 0; i < (vett[rigo] * 10 / max); i++)
      {
         cout << "*";
      }
      cout << endl;
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
