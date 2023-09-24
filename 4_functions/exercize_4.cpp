/*

Simulare l’esecuzione di ciascuna delle 4 chiamate a sottoprogrammi, limitandosi alla descrizione dei valori stampati tramite cout << .

*/

#include <iostream>
using namespace std;

int varA = 12, varB = 25;

int proc1(int *par)
{
  *par = *par - 7;
  return (23);
}

int proc1b(int &par)
{
  par = par - 7;
  return (23);
}

void proc2(int *varX, int varY)
{
  int varB;

  *varX = varY;
  varB = *varX + varY;
}

int proc3(int varA)
{
  int varZ = 17;
  varA = varA + varZ;
  return (varA);
}

int main()
{
  int varC = 63; /* situazione iniziale */
  cout << "\n0) varA varB varC " << varA << varB << varC;

  varC = proc1(&varA); /* passo 1 */
  cout << "\n1) varA varB varC " << varA << varB << varC;

  varC = proc1b(varA); /* passo 1 */
  cout << "\n1) varA varB varC " << varA << varB << varC;

  proc2(&varA, varC); /* passo 2 */
  cout << "\n2) varA varB varC " << varA << varB << varC;
  varB = proc3(varC); /* passo 3 */
  cout << "\n3) varA varB varC " << varA << varB << varC;

  varB = proc1(&varB); /* passo 4 */
  cout << "\n4) varA varB varC " << varA << varB << varC;

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
