/*


Si consideri la definizione  
struct Nodo { int numero;
  Nodo* next; };
typedef Nodo * Lista;

Si codifichi la funzione …spargidivisori(…), che riceve come parametri 
una lista di interi, una matrice NxN di interi, tutti strettamente positivi 
(come matrice dinamica), e la lunghezza N. 
La funzione deve cercare di copiare ogni valore v della lista nella 
matrice, inserendolo al posto di un valore che sia multiplo di v. Se ci riesce, 
restituisce 1, e la matrice deve contenere tutti i valori modificati, se non ci riesce, 
però, oltre a restituire 0, deve lasciare inalterata la matrice. 

Attenzione: 
i valori v devono sempre essere confrontati con la versione iniziale della 
matrice, non con le "versioni intermedie" derivanti dalla sostituzione 
di alcuni valori, se ci sono più multipli di v, se ne può sostituire 
uno a piacere (il primo che si incontra), si badi a definire chiaramente 
e/o dichiarare eventuali opportune strutture dati di appoggio o funzioni ausiliarie.

*/

int spargidivisori(Lista L, int **mat, int N)
{

  int auxmat = (int **)new (int *)[N];
  for (i = 0; i < N; i++)
  {
    auxmat[i] = (int *)new int[N];
    for (j = 0; j < N; j++)
      auxmat[i][j] = 0;
  } // end for

  int i, j, flag;
  int contL = 0, contFlag = 0;

  while (L != NULL)
  {
    contL++;

    flag = 0;
    for (i = 0; i < N && !flag; i++)
      for (j = 0; j < N && !flag; j++)
        if (L->numero % mat[i][j] == 0)
        {
          flag = 1;
          auxmat[i][j] = L->numero;
          contFlag++;
        }

    L = L->next;
  } // end while
  if (contL != contFlag)
    flag = 0;
  else
  {
    flag = 1;
    for (i = 0; i < N; i++)
      for (j = 0; j < N; j++)
        if (auxmat[i][j] != 0)
          mat[i][j] = auxmat[i][j];
  } // end else

  for (i = 0; i < N; i++)
    delete[] auxmat[i];
  delete[] auxmat;

  return flag;
}