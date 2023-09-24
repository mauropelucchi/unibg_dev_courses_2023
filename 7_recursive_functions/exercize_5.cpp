/*

Scrivere un sottoprogramma che inverta un vettore di interi con 
procedimento ricorsivo.
*/

void invertiVettore(int v[], int n)
{
  if (n <= 1)
    return;
  int t = v[0];
  v[0] = v[n - 1];
  v[n - 1] = t;
  invertiVettore(&v[1], n - 2);
}

//Chiamata nel main():
// ...
int vett[3] = {18, 21, 27}, lung = 3, m;
invertiVettore(vett, lung);
// ...

// Soluzione con prototipo alternativo:
void invertiVettore(int v[], int indiceInizio, int indiceFine)
{
  if (indiceFine <= indiceInizio)
    return;
  int t = v[indiceInizio];
  v[indiceInizio] = v[IndiceFine];
  v[Indicefine] = t;
  invertiVettore(v, indiceInizio + 1, indiceFine - 1);
}

// Chiamata nel main():
// ...
int vett[3] = {18, 21, 27}, lung = 3, m;
invertiVettore(v, 0, lung - 1);
// ...
