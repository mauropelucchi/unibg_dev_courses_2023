/*

Def. funzioni con parametri di tipo matrice

Scrivere un sotto-programma in linguaggio C++ che ricevuta una matrice quadrata come parametro restituisca al 
chiamante un valore booleano indicante se la matrice è simmetrica oppure no.
Scrivere quindi un programma principale minimale che acquisisca una matrice quadrata di numeri reali dallo 
standard input e testi la funzionalità del sotto-programma precedente. Se la matrice non è simmetrica occorre annullare 
le sue diagonali principali riportare su standard-output il risultato ottenuto.


*/

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXLEN 100

bool Simmetrica(float m[][MAXLEN], int n);

int main()
{
  float mat[MAXLEN][MAXLEN];
  int i, j, n;
  do
  {
    cout << "\n ordine della matrice 0 < n <= " << MAXLEN << ": ";
    cin >> n;
  } while (n <= 0 || n > MAXLEN);

  cout << "\n inserire coeff. matrice di ordine " << n << endl;
  cout << "separare le colonne con spazio e le righe con CR\n";
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      cin >> mat[i][j];

  if (Simmetrica(mat, n) == false)
  {
    cout << "\n la matrice inserita non e'simmetrica!";
    cout << "\n annullo le diagonali principali.....\n";
    for (i = 0; i < n; i++)
    {
      mat[i][i] = 0;
      mat[i][n - i - 1] = 0;
    }
    cout << "\n i valori nella matrice sono:\n\n";
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        cout << mat[i][j];
      cout << "\n";
    }
  }
  else
    cout << "\n la matrice inserita e' simmetrica!";

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  //
  // for Windows Users use
  //
  // system("pause");
  return 0;
} // end main

bool Simmetrica(float m[][MAXLEN], int n)
{

  bool flag = true;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
      if (m[i][j] != m[j][i])
        flag = false;

    return flag;
  }
}
