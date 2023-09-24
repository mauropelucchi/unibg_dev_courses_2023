/*

Scrivere un programma che visualizzi (come illustrato in calce) i valori di un 
array di 10 interi qualsiasi (cioè anche negativi o nulli). 


13   *
12   *                                *
11   *                *               *
10   *                *               *
 9   *        *       *               *
 8   *        *       *    *          *
 7   *        *   *   *    *          *
 6   *        *   *   *    *          *  
 5   *        *   *   *    *          *
 4   *        *   *   *    *   *      *
 3   *        *   *   *    *   *      *
 2   *        *   *   *    *   *      *
 1   *        *   *   *    *   *   *  *     
 0 --------------------------------------------------
-1        *                               *
-2        *                               *
-3        *

    13   -3   9   7   11   8   4   1  12  -2 
      0      1     2    3      4     5    6     7     8    9





*/

#include <iomanip>
#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

int main()
{
   int vett[SIZE] = {13, -3, 9, 7, 11, 8, 4, 1, 12, -2};
   int i, rigo, max = vett[0], min = vett[0];

   for (i = 1; i < SIZE; i++)
   { // Calcola max e min di vett[]
      if (max < vett[i])
         max = vett[i];
      if (min > vett[i])
         min = vett[i];
   }
   if (min > 0)
      min = 0;

   cout << endl;

   for (rigo = max; rigo >= min; rigo -= 1)
   {
      cout << setw(3) << rigo << "  ";
      for (i = 0; i < SIZE; i++)
      {
         if ((rigo > 0 && vett[i] >= rigo) ||
             (rigo < 0 && vett[i] <= rigo))
            cout << "  *  ";
         else
         {
            if (rigo == 0)
               cout << "-----";
            else
               cout << "     ";
         }
      }
      cout << endl;
   }

   cout << endl
        << setw(5) << " ";
   for (i = 0; i < SIZE; i++)
      cout << setw(3) << vett[i] << "  ";

   cout << endl
        << endl
        << setw(5) << " ";
   for (i = 0; i < SIZE; i++)
      cout << setw(3) << i << "  ";

   cout << endl;

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
