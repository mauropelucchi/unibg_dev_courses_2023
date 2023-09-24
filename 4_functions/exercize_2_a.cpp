/*

Data una sequenza vettoriale V[n] permutare i suoi elementi in modo che risulti ordinata in senso non decrescente:
V[0]  ≤  V[1]  ≤  V[2]  ≤ … ≤  V[n-1].

Metodo di Soluzione: Ordinamento per selezione 
L’idea è quella di trovare il minimo fra gli elementi nella sequenza e scambiarlo con l’elemento al primo posto. 
Trovare il minimo fra gli elementi tra il secondo posto e l’ultimo, e scambiarlo con il secondo e così via. 
Il metodo è chiamato “per selezione” perché si basa sulla ripetizione della selezione dell’elemento minore, 
tra quelli rimasti da ordinare.


*/

#include <iostream>
#include <cstdlib>
#define MAX_LEN 100
using namespace std;
int main()
{
  int V[MAX_LEN], n, min, i, j, jmin;

  do
  {
    cout << "\ninserire il # di elementi del vettore V, n = ";
    cin >> n;
  } while ((n <= 0) || (n > MAX_LEN));
  cout << "\ninserire gli elementi del vettore V:\n";
  i = 0;
  do
  {
    cin >> V[i];
    i++;
  } while (i < n);

  for (i = 0; i < n; i++)
  {
    jmin = i;
    min = V[jmin];

    for (j = i + 1; j < n; j++)
    {
      if (V[j] < min)
      {
        jmin = j;
        min = V[j];
      }
    }
    /* min contiene il minimo tra gli elementi V[i]…V[n-1] */
    V[jmin] = V[i];
    V[i] = min; /* scambio tra V[i] e V[jmin]          */
  }

  cout << "\n il vettore ordinato e':\n ";
  for (i = 0; i < n; i++)
    cout << V[i] << " ";

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
