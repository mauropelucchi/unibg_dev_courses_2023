/*
Write a program that solves the following problem.

Read three whole numbers a, b, c from the standard input, print the sequence of the three 
numbers at the terminal in non-degressive order.
Example: a = 10, b = 7, c = 9 must output 7 9 10.

*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {  
  int a,b,c;       // variables  

  // reads a, b, c from standard input
  cout << "\n Insert the number a: ";
  cin >> a;         
  cout << "\n Insert the number b: ";
  cin >> b;         
  cout << "\n Insert the number c: ";
  cin >> c;         
  
  if (a < b) {

   if (b < c) { 
      cout << "\n Result: ";
      cout << a << " " << b << " " << c;    
   }
   else { 
      if (a < c) { 
         cout << "\n Result: ";
         cout << a << " " << c << " " << b;
      }
      else { 
             cout << "\n Result: "; 
             cout << c << " " << a << " " << b;
      }
   }
  } 
  else {
    if (b > c) { 
      cout << "\n Result: ";
      cout << c << " " << b << " " << a;
    }
    else { 
      if (c > a) { 
         cout << "\n Result: ";
         cout << b << " " << a << " " << c;
      }
      else { 
         cout << "\n Result: ";
         cout << b << " " << c << " " << a;
      }
    } 
  }

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   // for Windows Users use
   //
   // system("pause");

}
