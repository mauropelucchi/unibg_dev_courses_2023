/*

Scrivere una funzione in linguaggio C che elimini tutti i nodi di 
posto dispari in una lista semplicemente concatenata di interi.
Es:   1 5 7 9 3 diventa 5 9 


*/

#include <iostream>
#include <cstdlib>

struct node
{
  int data;
  node *next;
};
typedef node *list;

list DeleteOdd(list h);

int main()
{
  int info;
  list h = NULL; /* Dichiarazione e inizializzazione lista */
                 /* (lista vuota)                          */
  DeleteOdd(h);
  return 0;
}

list DeleteOdd(list h)
{

  node *aux, *curr, *prev;
  int count;

  if (h == NULL)
    return h;
  aux = h;
  h = h->next;
  delete aux;
  prev = NULL;
  curr = h;
  count = 2;
  while (curr != NULL)
  {
    if (count % 2 == 1)
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
} // end DeleteOdd
