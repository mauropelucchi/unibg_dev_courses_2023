/*

Ci ispiriamo alla funzione strcmp( ... ).
Si codifichi una funzione datecmp( ... ) che stabilisce se due date, passate come parametri, sono uguali (nel qual caso restituisce 0), oppure in ordine cronologico (e allora restituisce un numero negativo), oppure in ordine cronologico inverso (restituendo un numero positivo).

Si codifichi inoltre una funzione che stampa una data nel formato
aaaa/mm/gg

Si scriva anche un piccolo programma (main) per verificare che le funzioni siano state realizzate correttamente. 

Si utilizzino le seguenti definizioni:



struct Data { int giorno;
              int mese;
              int anno; 
};

int datecmp( Data d1, Data d2 ) {
  ...
}

void stampa( Data d ) {
  ....
}

void stampaConLettere( Data d ) {

      ...
}
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Data
{
  int giorno;
  int mese;
  int anno;
};

int datecmp(Data d1, Data d2);
void stampa(Data d);

int main()
{
  Data x = {23, 11, 2016}, y = {12, 1, 2015};

  cout << endl;

  stampa(x);
  stampa(y);

  int cmp = datecmp(x, y);
  if (cmp == 0)
    cout << " Date Uguali! \n";
  else if (cmp < 0)
    cout << "Ordine cronologico inverso!\n";
  else
    cout << "Ordine cronologico!\n";

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

int datecmp(Data d1, Data d2)
{
  if (d1.giorno == d2.giorno && d1.mese == d2.mese && d1.anno == d2.anno)
    return 0;
  if (d1.anno < d2.anno ||
      (d1.anno == d2.anno && d1.mese < d2.mese) ||
      (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno < d2.giorno))
    return -1;

  return 1;
}

void stampa(Data d)
{
  cout << d.anno << "/";
  cout << d.mese << "/" << d.giorno << endl;
}