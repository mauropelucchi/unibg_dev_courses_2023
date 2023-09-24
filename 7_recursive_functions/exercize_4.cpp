/*

Scrivere un sottoprogramma che restituisca il valore massimo di un 
vettore di interi con procedimento ricorsivo.

Specifica Liv 1:
Si pensi di assegnare il primo elemento dell’array come massimo e 
confrontarlo con tutti gli altri cambiando il valore del massimo se questo è minore della cella corrente del vettore.

Specifica Liv 2:
Detta N la lunghezza del vettore array

Se N = 1, allora max = array[0]           (caso base)             

Se N > 1, allora il massimo del vettore di N elementi (max) sarà uguale 
al risultato del confronto  tra array[0] e il massimo degli elementi del sotto-vettore 
che che va da array[1] a array[N].  (N.B.:  quindi è lungo N-1)  (passo induttivo)

*/

int myMaxArray(int v[], int N)
{
  if (N <= 0)
    return 0; // valore massimo convenzionale!

  if (N == 1)
    return v[0];
  else
  {
    int t = myMaxArray(&v[1], N - 1);
    if (t > v[0])
      return t;
    else
      return v[0];
  }
}

// Chiamata nel main():
// ...
int vett[3] = {18, 21, 27}, lung = 3, m;
m = myMaxArray(vett, lung);
// ...

// Soluzione con prototipo alternative: main():
int myMaxArray(int v[], int indiceInizio, int indiceFine)
{
  if (indiceInizio > indiceFine)
    return 0; // valore massimo convenzionale!

  if (indiceInizio == indiceFine)
    return v[indiceInizio];
  else
  {
    int t = myMaxArray(v, 1 + indiceInizio, indiceFine);
    if (t > v[indiceInizio])
      return t;
    else
      return v[indiceInizio];
  }
}

//Chiamata nel main():
// ...
int vett[3] = {18, 21, 27}, lung = 3, m;
m = myMaxArray(vett, 0, lung - 1);
// ...
