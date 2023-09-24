/*


Scrivere un programma che inserisca un certo numero di parole e successivamente
le stampi nell'ordine di inserimento e nell'ordine contrario

*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct nodo
{
  char testo[31];
  struct nodo *next;
};
int inserisci_testa(nodo *&, char *);
int inserisci_coda(nodo *&, char *);
int stampa(nodo *);

int main()
{
  // dischiaro un puntatore a nodo e lo valorizzo a NULL mi serve per la testa
  nodo *head = NULL;
  // dischiaro un puntatore a nodo e lo valorizzo a NULL mi serve per la coda
  nodo *head1 = NULL;
  char vartesto[31];
  // ciclo di lettura termina con una stringa vuota
  do
  {
    cout << "Inserisci la parola : (invio per terminare) ";
    cin.getline(vartesto, 30, '\n');
    if (strlen(vartesto) != 0)
    {
      inserisci_testa(head, vartesto);
      inserisci_coda(head1, vartesto);
    }
  } while (strlen(vartesto) != 0);

  // stampe
  stampa(head);
  stampa(head1);
  return 0;
}

int inserisci_testa(nodo *&p_head, char *p_vartesto)
{
  nodo *varnodo;
  // alloco memoria
  varnodo = new nodo;
  strcpy(varnodo->testo, p_vartesto);
  varnodo->next = p_head;
  // head punta alla nuova struct
  p_head = varnodo;
  return 0;
}

int inserisci_coda(nodo *&p_head, char *p_vartesto)
{
  nodo *varnodo;
  nodo *precedente;
  // alloco nuova memoria
  varnodo = new nodo;
  strcpy(varnodo->testo, p_vartesto); // è l'ultimo elemento
  varnodo->next = NULL;
  // se è il primo inserimento
  if (p_head == NULL)
    p_head = varnodo;
  else
  {
    precedente = p_head;
    while (precedente->next != NULL)
      precedente = precedente->next;
    precedente->next = varnodo;
  }
  return 0;
}

int stampa(nodo *p_head)
{
  nodo *varnodo;
  varnodo = p_head;
  while (varnodo != NULL)
  {

    cout << varnodo->testo << endl;
    varnodo = varnodo->next;
  }
  return 0;
}