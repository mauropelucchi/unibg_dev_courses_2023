/*

Definiamo la "somiglianza" S fra due stringhe come il rapporto tra il doppio del numero di "triplette di caratteri consecutivi"
comuni ad entrambe le stringhe e la somma delle "triplette di caratteri consecutivi" in ciascuna stringa. Nel caso in cui almeno una delle due stringhe
sia composta da meno di 3 caratteri, la somiglianza è nulla (S = 0.0).
Scrivere un programma C++, che acquisisca due stringhe da tastiera (standard input) e riporti sullo schermo (standard output) la loro
"somiglianza", secondo la definizione precedente.


*/

#include <iostream>
#include <cstring>
using namespace std;
#define MAXWORDLENGTH 30

float somiglianza(char string1[], char string2[]);

int main()
{
  char string1[MAXWORDLENGTH + 1], string2[MAXWORDLENGTH + 1];

  cout << "\n (max " << MAXWORDLENGTH << " chars) -- string1 = ";
  cin.getline(string1, MAXWORDLENGTH + 1, '\n');

  cout << "\n (max " << MAXWORDLENGTH << " chars) -- string2 = ";
  cin.getline(string2, MAXWORDLENGTH + 1, '\n');

  cout << endl
       << "distance S = " << somiglianza(string1, string2);

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

float somiglianza(char string1[], char string2[])
{
  int len1, len2, i, j, count;
  float S;

  len1 = strlen(string1);
  len2 = strlen(string2);

  if (len1 < 3 || len2 < 3)
    S = 0.0;
  else
  {
    count = 0;
    for (i = 2; i < len1; i++)
    {
      for (j = 2; j < len2; j++)
      {
        if (string1[i] == string2[j] && string1[i - 1] == string2[j - 1] && string1[i - 2] == string2[j - 2])
        {
          count++;
        } // end if
      }   // end for, j
    }     // end for, i

    S = ((float)(2 * count)) / (len1 + len2 - 4);
  }
  return S;
}