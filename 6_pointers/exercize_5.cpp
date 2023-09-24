/*

Si consideri un vettore che rappresenta un elenco di N stringhe definito come segue.

#define N 4
typedef char parola[20+1];
typedef parola elenco[N];

Data una variabile:  elenco x; 
acquisire dallo standard input N stringhe e riportarle poi a video in ordine alfabetico. 

Memento: la funzione int strcmp(char s1[], char s2[]) confronta alfabeticamente s1 e s2.


*/

#include <iostream>
#include <cstring>
using namespace std;

#define N 4

typedef char parola[20 + 1];
typedef parola elenco[N];

int main()
{
  elenco x;
  int i, posmin;
  parola tmpstr;

  for (i = 0; i < N; ++i)
  {
    cout << "\n Inserisci la parola num. " << i + 1 << ": ";
    cin.getline(x[i], 20);
  }

  // selection sort
  for (i = 0; i < N; ++i)
  {
    posmin = i;
    for (int j = i + 1; j < N; ++j)
      if (strcmp(x[j], x[i]) < 0)
        posmin = j;
    strcpy(tmpstr, x[i]);
    strcpy(x[i], x[posmin]);
    strcpy(x[posmin], tmpstr);
  }
  for (i = 0; i < N; ++i)
    cout << "\n"
         << x[i];

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
