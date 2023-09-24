/*


Si consideri la seguente definizione:    

struct Nodo { char * parola; 
  Nodo * next;  };
typedef Nodo * Lista;

(a)	Si disegni la struttura allocata dalle istruzioni del blocco 
di codice a lato, si indichino i valori di ogni variabile 
(sia statica sia dinamica: per i puntatori si usino le frecce, 
per i valori ignoti i punti interrogativi), e se ne calcoli la 
dimensione totale in byte. MMMMMMMMM sizeof(char) = 1, 
sizeof(void *) = 4) 
 
Dimensione: 
2 puntatori, 3 array da 8 char, 3 nodi formati da 2 puntatori = 8 ptr + 24 char = 56 byte

(b)	Due parole si dicono simili se hanno al più due caratteri diversi. Una catena di
 parole si dice compatibile col telefono senza fili (cctsf) se ogni parola è 
 simile alle adiacenti.

La funzione int simili (char *s1, char *s2); restituisce 1 se s1 e s2 
sono simili, 0 altrimenti.
Usando la funzione simili(…) (senza codificarla), si codifichi una funzione f(…), 
opzionalmente anche ricorsiva, che riceve come parametro una lista 
dinamica di parole (secondo la definizione soprastante) e restituisce 
1 se la lista rappresenta una catena cctsf, 0 altrimenti. 

*/

int f(Lista a)
{ /* Versione ricorsiva */
  if (a == NULL || a->next == NULL)
    return 1;
  if (!simili(a->parola, a->next->parola))
    return 0;
  else
    return f(a->next);
}

int f(Lista a)
{ /* Versione iterativa */
  while (a != NULL && a->next != NULL)
  {
    if (!simili(a->parola, a->next->parola))
      return 0;
    a = a->next;
  }
  return 1;
}

// (c)	Si codifichi  la funzione int simili (char *s1, char *s2 );

int simili(char *s1, char *s2)
{
  int i;
  int cont = strlen(s1) - strlen(s2);
  if (cont > 2 || cont < -2)
    return 0;
  cont = i = 0;
  while (i < strlen(s1) && i < strlen(s2))
  {
    cont += (s1[i] != s2[i]);
    i++;
  } // end while
  return cont < 3;
}

/*

(d)Si consideri poi la definizione di una lista di catene di parole (da ogni 
NodoTesta inizia una Lista).

struct NodoTesta { Lista catena;
                   NodoTesta * next;  };
typedef NodoTesta *ListaDiListe;


Si codifichi  una funzione che riceve una lista di liste così definita 
e dealloca interamente dalla lista di liste le sequenze di parole che non sono cctsf. 
Attenzione: si ipotizzi che nelle catene non ci siano parole allocate staticamente,
e si badi a deallocare tutta la memoria dinamica. 
*/

void deallocaCatena(Lista a)
{
  if (a != NULL)
  {
    deallocaCatena(a->next);
    delete[] a->parola; /* deallocazione del vettore dinamico */
    delete a;
  }
}

ListaDiListe sfrondaListaDiListe(ListaDiListe b)
{
  if (b != NULL)
  {
    ListaDiListe tmp = sfrondaListaDiListe(b->next);
    if (!f(b->catena))
    {
      deallocaCatena(b->catena);
      delete b;
      return tmp;
    }
    else
      b->next = tmp;
  }
  return b;
}
