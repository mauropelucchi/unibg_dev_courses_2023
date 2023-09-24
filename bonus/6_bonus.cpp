/*


Scrivere una funzione per definire se un numero è primo
*/

#include <iostream>
using namespace std;

void scambia(int &numero1, int &numero2);
int main()
{
  int numero1, numero2;
  int j;
  cout << "Inserire il numero 1 ";
  cin >> numero1;
  cout << "Inserire il numero 2 ";
  cin >> numero2;
  scambia(numero1, numero2);
  cout << "Numero 1 ora vale : " << numero1 << endl;
  cout << "Numero 2 ora vale : " << numero2 << endl;


  return 0;
}
void scambia(int &a, int &b)
{
  int c;
  c = a;
  a = b;
  b = c;
}