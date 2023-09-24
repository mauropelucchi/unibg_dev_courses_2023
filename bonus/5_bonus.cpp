/*


Scrivere una funzione per definire se un numero è primo
*/

#include <iostream>
using namespace std;

bool primo(int numero);
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
  return 0;
}
bool primo(int a)
{
  int j;
  bool varprimo;
  varprimo = true;
  for (j = 2; j <= a / 2; j++)
  {
    if (a % j == 0)
      varprimo = false;
  }
  return varprimo;
}