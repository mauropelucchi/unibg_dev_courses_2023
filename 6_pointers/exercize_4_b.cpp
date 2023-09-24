/*

Scrivere una funzione conc_pars(…) che riceva come parametri due stringhe, e restituisca come risultato 
una nuova stringa, ottenuta dalla concatenazione delle stringhe ricevute, facendo in modo che la nuova 
stringa occupi la quantità minima di memoria.
La funzione non deve modificare le stringhe ricevute, ma restituisce un puntatore alla nuova stringa, 
che deve essere allocata dinamicamente (o non potrebbe essere utilmente restituita dalla funzione).
Esempio: s1 = “Prima”   s2 = "Seconda"   ->   restituisce = “PrimaSeconda”

Si scriva poi una procedura void strmul(…) che, data una stringa str (che dev’essere stata allocata 
dinamicamente) e un numero intero n, modifichi la stringa str, riallocandola e assegnandole il risultato 
della concatenazione di str con se stessa per n volte. 
Si noti che str deve essere stata allocata dinamicamente (o la funzione non potrebbe deallocarla e 
sostituirla con una più lunga!)
str deve essere opportunamente riallocata in modo da contenere esattamente il risultato della 
“moltiplicazione” (dimensione minima)
per essere modificata dalla funzione, la stringa str (che nell'ambiente del programma chiamante è un puntatore a carattere) 
deve essere passata per reference oppure per indirizzo.

Esempio: s = “abC” -> moltiplicazione per 3 -> s = “abCabCabC”

Suggerimento:  
si possono usare le funzioni strcat() e/o conc_pars() ?

*/

#include <cstring>
#include <iostream>
using namespace std;

char *conc_pars(char str1[], char str2[])
{
  char *ns = new char[strlen(str1) + strlen(str2) + 1];
  strcpy(ns, str1);
  strcat(ns, str2);
  return ns;
}

void strmul(char **str, int n)
{
  if (*str == NULL || strlen(*str) == 0 || n <= 0)
    return;
  char *ns = new char[strlen(*str) * n + 1];
  strcpy(ns, *str);
  for (int i = 1; i < n; ++i)
    strcat(ns, *str);
  delete[] * str;
  *str = ns;
}
int main()
{
  char *p = new char[30];
  cout << "\n inserisci una parola: ";
  cin >> p;
  int n = 3;
  strmul(&p, n);
  cout << "\n parola per " << n << " uguale: " << p << " \n\n ";
  delete[] p;

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
