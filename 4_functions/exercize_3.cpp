/*

(Definizione funzioni–passaggio parametri per copia)
Scrivere una funzione per definire se un numero è primo e un programma principale minimale che ne testa la funzionalità.


*/

#include <cstdlib>
#include <iostream>
using namespace std;

int primo(int a);

int main()
{
  int numero;
  int j;

  cout << "Inserire il numero ";
  cin >> numero;

  if (primo(numero))
    cout << "Numero primo ";
  else
    cout << "Numero non primo ";

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  //
  // for Windows Users use
  //
  // system("pause");
  return EXIT_SUCCESS;
}

int primo(int a)
{
  int j = 2;
  while ((j <= a / 2) && (a % j != 0))
    j = j + 1;

  if (j > a / 2)
    return 1;
  return 0;
} // end primo
