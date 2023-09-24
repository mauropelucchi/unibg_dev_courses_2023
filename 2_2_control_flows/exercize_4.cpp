/*

Write a program that reads from stdin a sequence (of unlimited a priori length) of positive integers, ending with 0,
and indicates, at the end of the sequence, what is the length of the maximum subsequence of consecutive numbers in ascending order. 

                           
*/

#include <iostream>
using namespace std; 

int main( ) { 
    int valore, precedente = 0, lungAttuale = 0, lungMax = 0; 
    cout << "Inserisci una sequenza di int positivi terminata da 0: \n";
    do {
       do {  
            cin >> valore;
        } while (valore < 0);

        if (valore != 0 && precedente <= valore) { 
          lungAttuale += 1;
          if (lungAttuale > lungMax) lungMax = lungAttuale; 
        } else {
          lungAttuale = 1;
        }
        precedente  = valore;
   } while (valore != 0);  

   cout << endl << "Lunghezza massima delle sottosequenze crescenti =  "; 
   cout << lungMax << endl;


   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   //
   // for Windows Users use
   //
   // system("pause");
} // end main 

