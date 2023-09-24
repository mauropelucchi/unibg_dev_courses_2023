/*

Si definisce il tipo di dato NumeroCodificato come segue:

struct NumeroCodificato { int base;
                          char cifre[20]; 
};

nel quale la base è un intero compreso tra 2 e 10 e cifre è una stringa (terminata da '\0') 
contenente i caratteri corrispondenti alle cifre ('0', '1', …) della codifica del numero in base base.
Si definiscano, codifichino e testino le funzioni:

int convertiInt(NumeroCodificato n);

che calcola  il valore del numero n e lo restituisce espresso come intero

void stampaDec(NumeroCodificato n);

che stampa a video il numero n in notazione decimale

NumeroCodificato codifica(int n, int b);

che codifica l'intero n in un NumeroCodificato di base b e lo restituisce al chiamante

NumeroCodificato converti(NumeroCodificato n,int b2);

che converte il numero n in un altro, codificato in base b2, e lo restituisce  al chiamante

*/

#include <cstring>

int convertiInt(NumeroCodificato n)
{
  int i, x = 0;
  for (i = strlen(n.cifre) - 1; i >= 0; ++i)
    x = n.base * x + n.cifre[i];
  return x;
}

/**** Prototipo alternativo ****************************
void convertiInt(NumeroCodificato n, int& risultato){
   int i, x = 0;
   for (i = strlen(n.cifre)-1; i>=0; ++i) 
      x = n.base*x + n.cifre[i];
   risultato = x; 
}
*******************************************************/

void stampaDec(NumeroCodificato n)
{
  int con = convertiInt(n);
  cout << con;
}

NumeroCodificato codifica(int n, int b)
{
  int i, copia = n, numCifre = 0;

  if (b < 2 || b > 10)
    b = 10;

  while (copia > 0)
  {
    copia = copia / b;
    numCifre++;
  }
  NumeroCodificato nc;
  nc.base = b;
  nc.cifre[numCifre] = '\0';

  copia = n;
  for (i = numCifre - 1; i >= 0; --i)
  {
    nc.cifre[i] = (char)(copia % b + ((int)'0'));
    copia = copia / b;
  }
  return nc;
}

NumeroCodificato converti(NumeroCodificato n, int b2)
{
  if (b2 < 2 || b2 > 10)
    return n;
  int v = convertiInt(n);
  NumeroCodificato nc = codifica(v, b2);
  return nc;
}
