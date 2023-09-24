/*

Write a program in C++ language that reads a positive integer from the standard input,
display at the terminal the square of the same number using only sum operations.
Note that the square of each positive integer N can be constructed by adding the first N odd numbers together.
                           
*/

#include <iostream>

using namespace std; 

int main( ) 
{ 
   int i; /* counter */ 
   int N;
   int S;

   do { 
      cout << "\n Digit a positive number: "; 
      cin >> N;
   } while (N <= 0); 

   S = 0; /* init the accumulator */
   
   i = 0; 
   while(i < N) { 
      /* while counter is less than read number */ 
      S = S + (i+i+1); 
      i = i + 1;
   } 
   cout << "\n The square is: " << S << "\n"; 

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   //
   // for Windows Users use
   //
   // system("pause");
} // end main 

