/*

Facendo uso dei comandi messi a disposizione dalla libreria standard del
C++ definiti in <cstring>, risolvere il seguente problema.

Leggere due stringhe str1, str2 dallo standard input, stampare a video lunghezza di str1 e str2, stampare il risultato della
concatenazione delle due stringhe: str1 concatenata str2, confrontare le due stringhe e stamparle in ordine alfabetico. 



*/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LEN 100

int main(int argc, char *argv[])
{
  char str1[MAX_LEN], str2[MAX_LEN], str3[2 * MAX_LEN];
  int len1, len2, cmp;

  cout << "\n Inserire la prima stringa, str1:";
  cin >> str1;
  cout << "\n Inserire la prima stringa, str2:";
  cin >> str2;

  len1 = strlen(str1);
  len2 = strlen(str2);
  cout << "\n la lunghezza della 1-ma stringa  e’: " << len1;
  cout << "\n la lunghezza della 2-da stringa  e’: " << len2;

  strcpy(str3, str1);
  strcat(str3, str2);
  cout << "\n Il risultato della concatenazione e': " << str3;

  cmp = strcmp(str1, str2);
  if (cmp > 0)
  {
  cout << "\n str1 > str2!";
  cout << "\n 1. " << str2 << " \n 2. " << str1;
  }
  else if (cmp < 0)
  {
    cout << "\n str2 > str1!";
    cout << "\n 1. " << str1 << " \n 2." << str2;
  }
  else
    cout << "\n str1 == str2 : " << str1;

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
