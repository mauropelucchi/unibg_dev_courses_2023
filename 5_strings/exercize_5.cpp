/*

Scrivere un programma in linguaggio C++ che conti il numero di parole contenute in una frase inserita dall’utente.

Considerare qualsiasi carattere non alfanumerico come un   
possibile separatore di parola.
 
Strutturare il programma prevedendo la definizione e l’utilizzo 
di  un sottoprogramma con il seguente prototipo 

bool alfanum(char c)

che restituisce true nel caso il carattere passato come parametro sia alfanumerico
([‘A'...'Z', 'a'...'z', '0'...'9']), false in caso contrario.

Esempi:
		"Oggi piove" : 2 parole 
		"Oggi c'e' il sole" : 5 parole 


*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXLEN 100

bool alfanum(char c);

int main(int argc, char *argv[])
{

  char frase[MAXLEN], c;
  int i, count;
  bool test_current, test_previous;

  cout << "\n Ins. una frase terminata dal carattere <INVIO>: ";
  cin.getline(frase, MAXLEN);

  count = 0;
  i = 0;
  c = frase[i];
  test_previous = false;
  test_current = alfanum(c);
  while (c != '\0')
  {
    if (test_current == true && test_previous == false)
    {
      count = count + 1;
    }
    i = i + 1;
    c = frase[i];
    test_previous = test_current;
    test_current = alfanum(c);
  }
  cout << "\n Num parole = " << count;

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

bool alfanum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    return true;
  else
    return false;
} // end alfanum
