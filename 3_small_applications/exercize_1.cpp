/*

Si acquisisca da tastiera una sequenza (a priori illimitata) di caratteri terminata 
da '\n' .

Per poter acquisire ed elaborare anche eventuali  caratteri di spaziatura, 
è necessario utilizzare il metodo cin.get( ... ). 
Si controlli se nella sequenza le parentesi tonde sono correttamente annidate 
e bilanciate, cioè se sono tutte ordinatamente richiuse. 
                          
Esempi:
Sequenze corrette:
    ciao  
    ()  
    (ciao)mondo
    ((ciao)(cia(o))(c(i)ao))(mond()o)

Sequenze non corrette:
   cia)o
   c(iao
   ci(ao)mo(ndo
   ci(ao)m(ond(o)!!
   ciao(ci)ao)(mondo)

*/

#include <iostream> 
using namespace std; 

int main( ) 
{
  int counter = 0;
  char c;
  cout << "\n Inserisci una sequenza di char: \n";  
  do { 
     cin.get( c );
     if ( c == '(' ) counter += 1;
     if ( c == ')' ) counter -= 1;  
   } while ( c != '\n' && counter >= 0 );

   if (counter != 0) 
     cout <<  "\n sequenza Scorretta! \n";
   else 
     cout << "\n sequenza Corretta! \n";


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

