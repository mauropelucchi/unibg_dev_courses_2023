/*

Scrivere i sottoprogrammi di manipolazione delle liste concatenate semplici 
(di interi), indicate di seguito, utilizzando un procedimento ricorsivo e uno iterativo per ognuna di esse:

-	Creazione di un nuovo nodo: 
           nodo *createNode(int d);
-	Inserimento in testa di un nuovo nodo con prototipo seguente:
           list insertHead(list h, node *el);
-	Inserimento in coda di un nuovo nodo con prototipo seguente:
                     list insertTail(list h, node *el);
-	Stampa di una lista : 
           void printList(list h);
-	Calcolo della lunghezza di una lista: 
           int lenLista(list h);
-	Ricerca elemento in una  lista: 
           list searchList(list h, int x); 
-	Copia di una lista: 
           list copyList(list h); 
-	Concatenazione di due liste:
                     void appendLista(list& h1, list& h2);
-	Inserimento in una lista ordinata: 
           list insertSorted(list h, int x);
-	Cancellazione di una lista: 
           void  wipeList(list& h);
-	Cancellazione 1ma occorrenza di un elemento da una lista: 
                     void deleteList(list& h, int x); 
-	Cancellazione di tutte le occorrenze di un elemento in lista:
           void  deleteListAll(list& h, int x);

*/

#include <iostream>
using namespace std;
#define N 5

struct node
{
  int data;
  node *next;
};

typedef node *list;

node *createNode(int d);
list insertHead(list h, node *el);
list insertTail(list h, node *el);
void printList(list h);
int lenLista(list h);
list searchList(list h, int x);
list copyList(list h);
void appendList(list &h1, list &h2);
list insertSorted(list h, int x);
void deleteListAll(list &h, int x);
void deleteList(list &h, int x);
void wipeList(list &h);

int main()
{

  list head = NULL;
  // supponiamo di creare una lista con N numeri interi

  int i, numero;
  node *t;

  for (i = 0; i < 5; ++i)
  {
    cout << "\n Inserisci numero : ";
    cin >> numero;
    t = createNode(numero);
    head = insertTail(head, t);
  }

  cout << "\n I numeri inseriti sono : \n";
  printList(head);

  // copio la lista
  list headListaCopiata = NULL;
  headListaCopiata = copyList(head);

  cout << "\n I numeri della lista copiata sono : \n";
  printList(headListaCopiata);

  // concateno la seconda lista alla prima
  appendList(head, headListaCopiata);

  cout << "\n I numeri nella lista dopo la concatenazione, sono : \n";
  printList(head);

  // dealloco tutti i nodi creati
  wipeList(head);

  return 0;
}

// Definizione dei sottoprogrammi:

node *createNode(int d)
{
  node *p;
  p = new node; /* Creazione nuovo nodo */
  p->data = d;
  p->next = NULL;
  return p;
}

list insertHead(list h, node *el)
{
  if (h == NULL)
    return el;
  if (el == NULL)
    return h;

  el->next = h;
  return el;
}

list insertTail(list h, node *el)
{
  node *aux;

  if (h == NULL)
    return el;
  if (el == NULL)
    return h;
  aux = h;
  while (aux->next != NULL)
    aux = aux->next;

  aux->next = el;
  return h;
}

void printList(list h)
{ /* stampa ricorsiva */
  if (h != NULL)
  {
    cout << " -> " << h->data;
    printList(h->next);
  }
}

int lenList(list h)
{
  if (h == NULL)
    return 0;
  else
    return (1 + lenList(h->next));
}

list searchList(list h, int x)
{
  /* ricerca ricorsiva, ritorna il puntatore al nodo che       */
  /* contiene la prima occorrenza di x.                        */
  if (h == NULL)
    return NULL;
  if (h->data == x)
    return h; /* caso base */
  else
    return searchList(h->next, x);
}

list copyList(list h)
{
  list ch = NULL, aux;
  while (h != NULL)
  {
    aux = (node *)new node;
    aux->data = h->data;
    aux->next = NULL;
    ch = insertTail(ch, aux);
    h = h->next;
  }
  return ch;
}

void appendList(list &h1, list &h2)
{
  // restituisce h1 = h1 concatenato h2
  if (h1 == NULL)
    h1 = h2;                 // caso base
  else if (h1->next == NULL) // caso base
    h1->next = h2;
  else
    appendList(h1->next, h2);
}

list insertSorted(list h, int x)
{
  node *prev = NULL, *curr = h;
  if (curr == NULL)
  { // se nella lista non ci sono nodi
    curr = createNode(x);
    return curr;
  }
  while (curr != NULL && curr->data < x)
  {
    prev = curr;
    curr = curr->next;
  }
  if (prev == NULL)
  {
    prev = createNode(x);
    prev->next = curr;
    return prev;
  }
  else
  {
    prev->next = createNode(x);
    prev->next->next = curr;
    return h;
  }
}

void wipeList(list &h)
{
  node *aux;
  if (h != NULL)
  {
    aux = h->next; /* salva punt. al nodo successivo */
    delete h;      /* cancella il primo elemento     */
    h = NULL;
    wipeList(aux); /* cancella il resto della lista   */
  }
}

void deleteList(list &h, int x)
{
  // soluzione ricorsiva
  // per esercizio scriverne una versione iterativa
  node *aux;
  if (h == NULL)
    return;
  if (h->data == x)
  {
    aux = h;
    h = h->next;
    delete aux;
    return;
  }
  deleteList(h->next, x);
}

void deleteListAll(list &h, int x)
{
  // soluzione ricorsiva
  // per esercizio scriverne una versione iterativa
  node *aux;
  if (h == NULL)
    return;
  if (h->data == x)
  {
    aux = h;
    h = h->next;
    delete aux;
    deleteListAll(h, x);
  }
  else
    deleteListAll(h->next, x);
}
