/*

Scrivere un programma C che, dato un numero calcola la somma dei primi N 
numeri pari positivi in maniera ricorsiva.

Specifica Liv 1:    
La somma dei primi N numeri pari è data dalla seguente,
          
           SN = 2*1 +  2*2 + 2*3 + … + 2*i + … + 2*(N-1) + 2*N.

Specifica Liv 2:    
se N =1, SN = 2,            (CASO BASE)
se N >1,  SN  = 2 * N + SN-1 (PASSO INDUTTIVO)
                           (somma dell’N-esimo numero pari +
                            la somma dei primi N-1 numeri pari.)

*/

int somma_pari(int N)
{
  if (N <= 1)
    return 2;
  else
    return 2 * N + somma_pari(N - 1);
}
