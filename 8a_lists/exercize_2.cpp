/*

Scrivere una funzione in linguaggio C che elimini tutti i 
nodi di posto pari in una lista semplicemente concatenata di interi.
Es:   1 5 7 9 3 diventa 1 7 3

*/

#include <iostream>
#include <cstdlib>

struct node
{
  int data;
  node *next;
};
typedef node *list;

list DeleteEven(list h);

int main()
{

  int info;
  list h = NULL; /* Dichiarazione e inizializzazione lista */
                 /* (lista vuota)                          */
  h = DeleteEven(h);
  return 0;
}

list DeleteEven(list h)
{

  node *curr, *prev;
  int count;

  if (h == NULL || h->next == NULL)
    return h;
  prev = h;
  curr = h->next;
  count = 2;
  while (curr != NULL)
  {
    if (count % 2 == 0)
    {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    }
    else
    {
      prev = curr;
      curr = curr->next;
    }
    count++;
  } // end while
  return h;
} // end DeleteEven
