/*


Scrivere un programma che dato in input un numero stampi tutti i divisori del numero dato

*/

#include <iostream>
using namespace std;

int main()
{
  int numero;
  int j;
  cout << "Inserire il numero ";
  cin >> numero;
  for (j = 1; j <= numero / 2; j++)
  {
    if (numero % j == 0)
      cout << "Divisibile per " << j << endl;
  }
  cout << "Divisibile per " << numero << endl;

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  // for Windows Users use
  //
  // system("pause");

  return 0;
}