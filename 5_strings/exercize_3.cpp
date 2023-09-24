/*

Scrivere un programma in linguaggio C++ che verifichi se una parola inserita dallo standard input è palindroma e in caso
contrario stampa a video la parola inserita partendo dall’ultimo carattere sino al primo. 
Le parole palindrome sono quelle che possono essere lette indifferentemente da sinistra a destra e da destra a sinistra. 

Esempio: 
"anna", "abba", "onorarono", "radar", 
"a" (parola di una lettera).



*/

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXLEN 100

int main()
{
  char parola[MAXLEN];
  int i, n;

  cout << "\nparola = ";
  cin >> parola;

  n = 0;
  while (parola[n] != '\0')
    n++;

  i = 0;
  while ((i < n / 2) && (parola[i] == parola[n - i - 1]))
  {
    i = i + 1;
  }
  if (i < n / 2)
  {
    cout << "\n NO palindroma!\n";
    cout << "\n Inversa = ";
    for (i = n - 1; i >= 0; i--)
      cout << parola[i];
  }
  else
    cout << "\n palindroma";

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  //
  // for Windows Users use
  //
  // system("pause");
  return 0;
}
