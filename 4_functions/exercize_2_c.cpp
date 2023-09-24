/*

Data una sequenza vettoriale V[n] permutare i suoi elementi in modo che risulti ordinata in senso non decrescente:
V[0]  ≤  V[1]  ≤  V[2]  ≤ … ≤  V[n-1].

Metodo di Soluzione: Ordinamento Bubblesort
L’idea di questo algoritmo è quella di confrontare i primi due elementi e se non sono ordinati li si scambia, poi si 
confrontano il secondo e il terzo e se non sono ordinati li si scambia e così via sino a confrontare penultimo e ultimo elemento.
Dopo aver scandito una prima volta tutto il vettore si è sicuri che l’elemento maggiore è nella cella più a destra, 
quindi si comincia un nuovo ciclo che confronta ancora a due a due le celle dalla prima all’ ultima. 
Se n è il numero di elementi del vettore si itera questo processo di scansione per n-1 volte al termine delle quali il 
vettore risulterà completamente ordinato.


Versione migliorata dell’algoritmo bubblesort

*/

#include <iostream>
#include <cstdlib>
#define MAX_LEN 100
using namespace std;
int V[MAX_LEN];

int main()
{
  int i, j, n, aux;

  do
  {
    cout << "\n inserire il # di elementi del vettore V, n = ";
    cin >> n;
  } while ((n <= 0) || (n > MAX_LEN));

  cout << "\ninserire gli elementi del vettore V:\n";
  i = 0;
  do
  {
    cin >> V[i];
    i++;
  } while (i < n);

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (V[j] > V[j + 1])
      {
        aux = V[j + 1];
        V[j + 1] = V[j];
        V[j] = aux;
      }
    }
  }

  cout
      << "\nil vettore ordinato e':\n ";
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
