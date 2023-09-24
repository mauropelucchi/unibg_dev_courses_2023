/*

Def. funzioni con parametri di tipo vettore

Si progetti e codifichi una funzione C++ che riceve come parametri due stringhe che rappresentano due parole e restituisce un valore intero,
da interpretarsi come valore di verità, che indichi se le due parole sono anagrammi, cioè se sono ottenibili l’una dall’altra tramite una permutazione
delle lettere che le compongono.
Ad esempio le parole POLENTA e PENTOLA sono anagrammi.

Si presti attenzione al fatto che parole come TAPPO e PATTO non sono anagrammi, anche se ogni lettera dell’una è contenuta nell’altra.


*/

/* Restituisce 1 se le due parole sono una l'anagramma
   dell'altra, 0 altrimenti                               */

int anagrammi(char a[], char b[])
{

  int len = strlen(a),
      contA, contB, // contatori di occorrenze di una lettera
      i, k;         // indici di sevizio

  if (len != strlen(b))
    return 0;

  for (i = 0; i < len; i++)
  {
    contA = contB = 0;
    for (k = 0; k < len; k++)
    {
      if (a[k] == a[i])
        ++contA;
      if (b[k] == a[i])
        ++contB;
    }
    if (contA != contB)
      return 0;
  }
  return 1;
} // end anagrammi
