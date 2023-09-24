/*

Calcolo del coefficiente binomiale
Scrivere un programma C/C++ che stampi sullo standard output tutti i valori del 
triangolo di Tartaglia per un certo ordine N, utilizzando una funzione ricorsiva per 
il calcolo dei coefficienti binomiali, avente il seguente prototipo: 

int cobin(int n, int k);

La costruzione del triangolo di Tartaglia  è mostrata di seguito. 
Si ricorda inoltre che ognuno dei coefficienti del triangolo prende il nome di 
coefficiente binomiale cobin(n, k)

Soluzione:
Leggendo la figura del triangolo di Tartaglia riga per riga, è possibile 
dedurre come il calcolo di ognuna di esse sia funzione della riga precedente. 
Il calcolo dei coefficienti binomiali segue dunque le seguenti regole:
•	calcolo dei coefficienti agli estremi di una riga: 
        con k == 0 e k == n,  cobin(n,k) == 1   (caso base)

•	calcolo dei coefficienti per valori non validi dei parametri: 
        con n < 0 e k < 0 e n < k,  cobin(n,k) == 0   (caso base)

•	Ogni coefficiente è la somma del suo "soprastante" 
        e del predecessore di quest' ultimo.                   (passo induttivo)
/* Nota: #include <iomanip>
Larghezza campo di output (n colonne): 
			 cout << setw(n);
Numero di cifre decimali dopo la virgola (n cifre):   
			cout << setprecision(n);
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define N 6

int cobin(int n, int k);

int main()
{
  int n, k;
  for (n = 0; n <= N; n++)
  {
    for (k = 0; k <= n; k++)
         cout << setw(5) << cobin(n, k);
    cout << endl;
  }
  return 0;
} // end main

int cobin(int n, int k)
{

  if (n < k || n < 0 || k < 0)
    return 0;
  if (k == 0 || k == n || n == 0)
    return 1;

  return cobin(n - 1, k - 1) + cobin(n - 1, k);

} // end cobin
