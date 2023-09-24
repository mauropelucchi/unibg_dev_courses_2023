/*

Appello del 10 Luglio 2009

Si consideri un programma che gestisce gli orari dei treni di un servizio ferroviario. 
In particolare, si definisca una lista dinamica che rappresenta le singole fermate di 
ciascun treno: ogni nodo della lista descrive un numero di treno, il numero progressivo 
della fermata (la stazione di partenza corrisponde alla fermata numero 1), il nome della 
stazione, l’ora e i minuti (si usino due campi separati di tipo intero). 
Nella stessa lista possiamo perciò trovare le fermate di treni diversi.
Dopo aver definito la struttura dati, si scriva in C/C++ la funzione TreniAlternativi, 
che riceve come parametro la lista delle fermate, e un numero di treno; la funzione 
restituisce il numero dei treni che collegano i due capolinea del treno fornito come 
parametro (se il treno indicato come parametro parte dalla stazione A e arriva alla 
stazione B, vogliamo sapere quanti sono i treni che collegano A con B, anche se A e B 
non sono capolinea).
La funzione restituisce -1 se il treno indicato come parametro non esiste.



*/

#include <cstring>

#define STRLEN 30
struct Nodo
{
  int numTreno;
  int numFermata;
  char nomeStazione[STRLEN + 1];
  int hh;
  int mm;
  Nodo *next;
};

int TreniAlternativi(Nodo *F, int numT)
{

  Nodo *Fi, Fj;
  char stazioneA[STRLEN + 1] = {'\0'}; //nome del Capolinea A del treno numT
  char stazioneB[STRLEN + 1] = {'\0'}; //nome del Capolinea B del treno numT
  int contaFermate;                    // per trovare l’ultima stazione del treno numT
  int contTreni;

  contaFermate = 1;
  Fi = F;
  while (Fi != NULL)
  {
    if (Fi->numTreno == numT)
    {
      if (Fi->numFermata == 1)
      {
        strcpy(stazioneA, Fi->nomeStazione);
      }
      else if (Fi->numFermata > contaFermate)
      {
        contaFermate = Fi->numFermata;
        strcpy(stazioneB, Fi->nomeStazione);
      }
    }
    Fi = Fi->next;
  }

  if (strlen(stazioneA) == 0)
    return -1;

  contTreni = 0; // N.B. la lista non è ordinata in nessun modo
  for (Fi = F; Fi != NULL; Fi = Fi->next)
  {
    if (strcmp(stazioneA, Fi->nomeStazione) == 0)
    {
      for (Fj = F; Fj != NULL; Fj = Fj->next)
      {
        if (Fi->numTreno == Fj->numTreno &&
            strcmp(stazioneB, Fj->nomeStazione) == 0 &&
            Fj->numFermata >= Fi->numFermata)
        {
          /* NOTA: >=, per includere il caso limite 
                              in cui stazioneA coincide 
                              con stazioneB
                 */
          contTreni++;
        } // end if
      }   // end for Fj
    }     // end if
  }       // end for Fi

  return contTreni;
} // end TreniAlternativi
