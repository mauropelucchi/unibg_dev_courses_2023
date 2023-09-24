/*
Can an infant live for 1 billion seconds?

Write a C++ program that can display the number of years a child has completed after 1 billion seconds, using double variables. 

Note: the following C++ statement:

double seconds = 1e+9; 
declares and assigns to the seconds variable the value 1 billion, in scientific notation.                                

*/

#include <iostream>
#include <iomanip> // to import setfill(...), setw(...), setprecision(...)

using namespace std;

int main() {

   double seconds = 1e+9;
   double hours, days, years;
   
   hours = seconds / 3600.0;
   days = hours / 24.0;
   years = days / 365.0;

   cout << "\n A child, after " << seconds << " seconds, is ";
   cout << setfill('.') << setw(5) <<  setprecision(4) << years;
   cout << "  years old! " << endl << endl;



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
