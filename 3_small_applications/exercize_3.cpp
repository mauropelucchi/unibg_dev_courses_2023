/*

Si codifichi un programma C che legge dallo standard input una sequenza 
(di lunghezza arbitraria) di interi positivi terminata dal valore 0 e, al 
termine della sequenza, visualizza su standard output un messaggio che indica 
quante terne di numeri consecutivi diversi e pari sono contenute nella sequenza. 

  2  50  13  16  8  6   4  6  18  6  6  16  4  1  25  0

Le terne di numeri cercati sono 4.
Si noti che uno o due numeri potrebbero appartenere a più di una terna 
e che lo 0 è un numero pari che potrebbe far parte di una terna valida.

...


*/

#include <iostream> 
#define SENTINELLA 0
using namespace std; 

int main(int argc, char *argv[]) 
{
  int cont = 0; // variabile usata per il conteggio delle terne valide      
  int prev2, prev1 = 1, cur = 1; 
  // Le inizializzazioni di cur e prev1 a 1 sono innocue
  // perché impostate con valori positivi dispari. 
  // cur,prev1,prev2: rappresentano rispettivamente il 
  // valore corrente e i due precedenti
  int cond = 0;
  // variabile ausiliaria usata per comodità di
  // scrittura della condizione di riconoscimento di 
  // una terna valida. 
  cout << "\nSeq. di int separati da spazi ";
  cout << " (termina con " << SENTINELLA << ")\n\n";
  do {
    prev2 = prev1;
    prev1 = cur;
    cin >> cur;
    cond = (prev2 > 0  && prev1 > 0 && cur >= 0);
    cond = cond && !(prev2==prev1 || prev2==cur || prev1==cur);
    cond = cond && (prev2 % 2==0 && prev1 % 2==0 && cur % 2==0);
    if (cond) {
      cont++;
      cout<<"( "<< prev2 <<", "<< prev1<<", "<< cur<< " )\n";
    }
  } while ( cur != SENTINELLA );
  cout << "Le coppie di numeri cercati sono " << cont << "\n";

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


