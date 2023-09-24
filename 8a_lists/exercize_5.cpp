/*

La funzione …toro(…)  riceve come parametro un vettore di interi e la specifica 
della sua dimensione, e alloca e restituisce una lista dinamica "circolare" di 
interi che contiene solo i valori del vettore positivi e divisibili per 11.

Ovviamente la lista può essere circolare solo se non è vuota, quindi si suggerisce 
di renderla circolare solo alla fine dell'analisi del vettore [N.B. una lista è 
circolare se l'ultimo elemento invece di avere un puntatore a NULL ha un puntatore alla testa].

*/

// (a)	Si definiscano la struttura della lista e il prototipo della funzione toro.

struct Nodo
{
  int numero;
  Nodo *next;
};
typedef Nodo *ListaC;
ListaC toro(int v[], int len);

// (b)	Si codifichi la funzione (unitamente alle eventuali funzioni di supporto).

ListaC toro(int v[], int len)
{
  int i = 0;
  ListaC ptr, testa;
  testa = ptr = NULL;
  while (i < len)
  {
    if (v[i] > 0 && v[i] % 11 == 0)
    {
      if (testa == NULL)
      {
        testa = creaNodo(v[i]);
        ptr = testa;
      }
      else
      {
        ptr->next = creaNodo(v[i]);
        ptr = ptr->next;
      }
    }
    ptr->next = testa;
    return testa;
  }

  Nodo *creaNodo(int a)
  {
    ListaC ptr = (Nodo *)new Nodo;
    ptr->numero = a;
    ptr->next = NULL;
  }

  // (c)	Si disegni, la lista ottenuta con la funzione passando come parametro il vettore
  // [111, 0, 11, -8, 73, -29, 121, 49, 16, 33, -110, 101, 44, 21]
