/*


Si considerino due matrici di interi A e B, di uguali dimensioni (R e C, costanti, che indicano il numero di righe e colonne). 
Diciamo che A domina B se, confrontando i valori in posizioni corrispondenti, risulta che il numero dei valori in A maggiori dei
corrispondenti valori in B è più grande del numero di quelli di B maggiori dei corrispondenti in A e inoltre gli elementi corrispondenti non sono mai uguali
(se due elementi corrispondenti sono uguali la dominanza non è definita).

Si proponga un prototipo per la funzione domina(...) che riceve le matrici come parametri e restituisce 1 se la prima domina la seconda, -1
se la seconda domina la prima, 0 altrimenti. 

Si dia una descrizione breve ma precisa di un algoritmo per implementare la funzione.
 
Si codifichi la funzione in C. 


*/

int domina(int A[][C], int B[][C])
{

  int bilancio = 0, i, j;

  /* Ipotizziamo che gli interi possano */
  /* rappresentare il valore R*C        */

  for (i = 0; i < R; i++)
    for (j = 0; j < C; j++)
    {
      if (A[i][j] == B[i][j])
        return 0;
      if (A[i][j] > B[i][j])
        bilancio++;
      else
        bilancio--;
    }

  if (bilancio > 0)
    return 1;
  if (bilancio < 0)
    return -1;
  return 0;
}
