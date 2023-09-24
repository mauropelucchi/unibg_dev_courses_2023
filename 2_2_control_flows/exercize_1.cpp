/*

Given a positive number Q,
- write its representation in natural binary, applying the traditional algorithm for successive divisions (by convention,
in this exercise the output is correct if read from right to left); 
- also indicate the minimum number of bits used.                              

*/

#include <iostream>
using namespace std; 

int main( ) 
{ 
   int n; /* counter */ 
   int Q;
   // control loop
   do { 
      cout << "\n Digit a positive number: "; 
      cin >> Q;
   } while (Q <= 0); 
   cout << "\n Binary: "; 
   n = 0; 
   do { 
      cout << (Q % 2); 
      Q = Q / 2; 
      n = n+1; 
   } while (Q != 0); 
   cout << "\n number of bits n = " << n << endl; 

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   //
   // for Windows Users use
   //
   // system("pause");
} // end main 

