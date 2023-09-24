/*

Si scriva una funzione che, ricevendo come parametri una stringa str ed un carattere car,
restituisca UNA NUOVA stringa di lunghezza minima (allocata dinamicamente) uguale a 
str ma priva di tutte le occorrenze del carattere car.

Esempio: 
dati  "esercizio semplice"    e    ’s’ 
la funzione dovrà allocare e restituire la stringa "eercizio emplice"

Attenzione:
La funzione non conosce a priori la lunghezza della stringa str.
Si richiede esplicitamente di restituire una nuova stringa di lunghezza minima, 
cioè che occupi la minima quantità di memoria: occorre calcolare tale quantità prima della new.



*/

char *fun(char str[], char c)
{

  char *ns = NULL;
  int count = 0, i, k;

  for (i = 0; i < strlen(str); i++)
    if (str[i] == c)
      count++;

  ns = new char[strlen(str) - count + 1]; // +1 perché sarà una stringa

  k = 0;
  for (i = 0; i < strlen(str); ++i)
  {
    if (str[i] != c)
    {
      ns[k] = str[i];
      k++;
    }
  }
  ns[k] = '\0';
  return ns;
}
