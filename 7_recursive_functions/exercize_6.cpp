/*

Scrivere un sottoprogramma ricorsivo che preso come parametro una stringa 
ritorni 1 se la stringa è palindroma e 0 altrimenti. 

*/

int palindromaRicorsiva(char s[], int idxInizio, int IdxFine)
{
  if (idxInizio >= IdxFine)
    return 1;
  if (s[idxInizio] != s[idxFine])
    return 0;
  return palindromaRicorsiva(s, idxInizio + 1, idxFine - 1)
}

int palindroma(char s[])
{
  return palindomaRicorsiva(s, 0, strlen(s) - 1);
}
