/*

Scrivere un programma in linguaggio C che lette dallo standard input due sequenze vettoriali ordinate di interi V1[n], 
V2[m] ne crei una terza V3[n+m] anch’essa ordinata, che contenga tutti gli elementi di V1 e di V2.
Esempio: V1 = < 1, 2, 5, 6 >;  V2 = < 3, 4, 5, 7, 9 >; allora V3 = <1, 2, 3, 4, 5, 5, 6, 7, 9 >

Idea di soluzione: 
si suppone l’array V3 vuoto inizializzando un indice k all’inizio di quest’ ultimo e si inizializzano due indici i,j 
rispettivamente all’inizio dei vettori V1 e V2.
Si entra quindi in un ciclo in cui si ricopia nel terzo vettore V3 il minore tra V1[i] e V2[j], incrementando l’indice corrispondente. 
Il ciclo termina quando una delle due sequenze V1 o V2 è terminata, dopodiché si procede con l’accodare in V3 
la restante parte del vettore rimasto.

*/


#include <iostream>
#include <cstdlib>
#define MAX_LEN 100
using namespace std;

int main()
{
  int V1[MAX_LEN], V2[MAX_LEN]; /* dichiarazione delle variabili */
  int V3[2 * MAX_LEN];
  int n, m;
  int i, j, k;

  /* prima parte dell’algoritmo:  acquisizione dei due vettori */
  do
  {
    cout << "\n inserire il # di elementi del vettore V1, n = ";
    cin >> n;
  } while ((n <= 0) || (n > MAX_LEN));
  cout << "\n inserire gli elementi ordinati del vettore V1:\n ";
  i = 0;
  do
  {
    cin >> V1[i];
    i++;
  } while (i < n);

  do
  {
    cout << "\n inserire il # di elementi del vettore V2, m = ";
    cin >> m;
  } while ((m <= 0) || (m > MAX_LEN));
  cout << "\ninserire gli elementi ordinati del vettore V2:\n";
  j = 0;
  do
  {
    cin >> V2[j];
    j++;
  } while (j < m);

  /* seconda parte dell’algoritmo:   fusione delle due sequenze */

  i = 0;
  j = 0;
  k = 0;

  while (i < n && j < m)
  {

    if (V1[i] < V2[j])
    {
      V3[k] = V1[i];
      i++;
    }
    else
    {
      V3[k] = V2[j];
      j++;
    }
    k++;
  }

  while (i < n)
  {
    V3[k] = V1[i];
    i++;
    k++;
  }

  while (j < m)
  {
    V3[k] = V2[j];
    j++;
    k++;
  }

  cout << "\nil risultato della fusione dei due vettori e’:\n";
  k = 0;

  do
  {
    cout << V3[k] << " ";
    k++;
  } while (k < n + m);

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
