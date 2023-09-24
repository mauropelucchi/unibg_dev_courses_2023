/*


struct Nodo { char c; 
              Nodo * next; };
typedef Nodo * Lista;

Si considerino una lista L di almeno N nodi e un vettore v di esattamente 
N puntatori a Nodo, tutti diversi da NULL e diversi tra loro, che puntano a un 
sottoinsieme dei nodi di L. Diciamo che L è compatibile con v se i nodi puntati da 
v compaiono in L in un ordine compatibile con l'ordine in cui i puntatori sono contenuti 
in v (cioè non succede mai che un nodo n1 puntato dal puntatore v[i] preceda in L il nodo 
n2 puntato dal puntatore v[j] che però si trovi "più avanti" in v).



a)	Si codifichi la funzione …compatibili(…) che controlla che una lista e un vettore 
siano compatibili secondo la precedente definizione.

La soluzione più semplice si ha notando che la lista che inizia da ogni elemento 
v[i] deve avere più nodi di ogni lista che inizia da ogni elemento v[j] con j>i. 
Si noti che a rigore non è necessario passare L alla funzione.

*/

int contanodi(Lista x)
{
  if (x == NULL)
    return 0;
  return 1 + contanodi(x->next);
}

int compatibili(Lista v[])
{
  int i = 0;
  for (i = 1; i < N; i++)
    if (contanodi(v[i - 1]) < contanodi(v[i]))
      return 0;
  return 1;
}

/* Esiste anche una soluzione di complessità lineare 
(la precedente è quadratica) che scandisce la lista e il vettore, 
sempre "in avanti" – se termina prima il vettore sono compatibili, 
se termina prima la lista, no:

*/
int compatibili(Lista v[], Lista L)
{
  int i = 0;
  while (L != NULL && i < N)
  {
    if (L == v[i])
      i++;
    L = L->next;
  }
  return i == N;
}

/*
b)	Si codifichi la funzione …vprintf(…) che stampa su stdout la 
parola ottenuta seguendo nell'ordine i puntatori di v e accedendo 
ai caratteri contenuti nella lista, se L e v sono compatibili, e 
nulla se sono incompatibili (stamperebbe "ciao" nel caso dell'esempio soprastante).


*/

void vprintf(Lista v[])
{
  int i;
  if (compatibili(v))
    for (i = 0; i < N; i++)
      cout << v[i]->c;
}
