/*

We define Triangular a number consisting of the sum of the first N positive integers for a certain N.
Example: for Q = 10 we have Q = 1 + 2 + 3 + 4, from which N=4.
Write a program C++ that determines whether a positive integer Q, read from the standard input,
is a triangular number or not, using only integer operations.
If yes, print on screen the number entered and the maximum number of addendums that compose it.

                           
*/

#include <iostream>
using namespace std; 

int main( ) 
{ 
   int i;
   int Q;
   int S;
   do { 
      cout << "\n Digit a positive number: "; 
      cin >> Q;
   } while (Q <= 0); 

   S = Q;
   i = 0;
   while (S > 0) { 
      i = i + 1; 
      S = S - i; 
   } 

   /* check the result from the cycle */
   if (S == 0) { 
      cout << "\n " << Q << " is equal to the sum of the first "; 
      cout << i << " positive number! \n";
   } else { 
      cout << "\n The number " << Q;
      cout << " is not triangular! \n"; 
   } 


   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   //
   // for Windows Users use
   //
   // system("pause");
} // end main 

