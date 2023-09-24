/*

Si scriva un sottoprogramma C/C++ che effettui la ricerca di un intero in un vettore 
ordinato (in senso crescente) in maniera ricorsiva, restituendo 
l' indice della prima occorrenza nel vettore del valore cercato.

// Restituisce l' indice della cella contenente un valore 
// uguale a x; oppure -1

*/

#include <iostream>
#include <ctime>

using namespace std;

#define N 55

int dicotomica(int v[], int left, int right, int x);
int cerca(int v[], int len, int x);
void genera(int a[N]);
int scegli_numero();
void bubble_sort(int a[N], int n);

int main()
{
  int a[N];
  int pos = -1;
  int numero;

  genera(a);
  bubble_sort(a, N);
  numero = scegli_numero();
  pos = cerca(a, N, numero);

  if (pos != -1)
    cout << "numero trovato in posizione: " << pos << endl;
  else
    cout << "numero non trovato";

  return 0;
}

void genera(int a[N])
{
  int i;

  srand(time(NULL));
  for (i = 0; i < N; i++)
  {
    a[i] = rand() % 100 + 1;
  }

  cout << "Array generato " << endl;
  for (i = 0; i < N; i++)
    cout << a[i] << "\t";
}

int scegli_numero(void)
{
  int numero = 0;
  do
  {
    cout << endl;
    cout << "Scegli un numero da cercare [1, 100]:" << endl;
    cin >> numero;
  } while (numero < 1 || numero > 100);
  return numero;
}

void bubble_sort(int vet[], int n)
{
  int tmp;
  for (int j = 0; j < n; j++)
  {

    for (int i = n - 1; i >= j; i--)
    {
      if (vet[i] > vet[i + 1])
      {
        tmp = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = tmp;
      }
    }
  }
}

int dicotomica(int v[], int left, int right, int x)
{
  int middle;

  if (left > right)
    return -1;

  middle = (left + right) / 2;

  if (x < v[middle])
  {
    return dicotomica(v, left, middle - 1, x);
  }

  if (x == v[middle])
  {
    return middle;
  }

  return dicotomica(v, middle + 1, right, x);
}

int cerca(int v[], int len, int x)
{
  return dicotomica(v, 0, len - 1, x);
}
