/*

Scrivere una funzione che calcoli il valore MN, dove M è un numero in virgola mobile e N un numero intero. 

1mo caso:
Hp: M intero, N intero con N>=0
	Specifica Liv 1:   
                  MN = M*M*M*…*M; N volte.

	Specifica Liv 2:
    		Se N = 0, allora MN  = 1           (caso base)
    		Se N è pari, allora MN = (MN/2)2     (passo induttivo)
    		Se N è dispari, allora MN = (MN-1)*M (passo induttivo)


per considerare anche il caso di potenze negative cosa occorrerebbe fare?
*/

double myExp(double M, int N)
{
  if (N < 0)
    return myExp(1.0 / M, -N);

  if (N == 0)
    return 1;

  if (N % 2 == 0)
  {
    long t = myExp(M, N / 2);
    return t * t;
  }

  if (N % 2 == 1)
    return M * myExp(M, N - 1);
}
