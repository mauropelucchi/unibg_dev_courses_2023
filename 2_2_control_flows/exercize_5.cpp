/*

Write a program that reads a positive integer n from stdin and checks if it 
can be broken down into the sum of two squares 
                           
*/

#include <iostream>
using namespace std; 

int main( ) { 
  int n,a,b; 
  int nonScomponibile = 1;

  cout << "Inserisci un numero: ";
  cin >> n;
  cout << "Scomposizione: \n"; 

  for (a = 1; a <= n/2; ++a) {      // basterebbe: a < square-root(n/2) 
     for (b = 1; b <= n-a*a; ++b) { // basterebbe: b < square-root(n-a*a)
        if (a*a + b*b == n) {
           cout << n << "=" << a*a << "+" << b*b << endl;
           nonScomponibile = 0;  
        }
     } 
  }
  if (nonScomponibile == 1) 
    cout << n << " -> NON SCOMPONIBILE ! " << endl;



   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   //
   // for Windows Users use
   //
   // system("pause");
} // end main 

