/*
Realize a program that, given in input an angle specified in degrees as an integer number, 
provides the relative conversion into radians. The angle must be between 0 and 360 degrees, 
otherwise the program prints an error message and finishes.

Note: Consider 3.14159265 the value of pi.                                     
*/

#include <iostream>
using namespace std;

#define PIGRECO 3.14159265 
// with preprocessor #define we can define the constant PIGRECO
// otherwise
//           const double PIGRECO = 3.14159265 
// What are advantages/disadvantages for each method?

int main(int argc, char *argv[])
{  
  int degrees;
  float rad; 
  cout << "\nDigit a angle from 0 to 360 degrees: ";
  cin >> degrees;

  if (degrees < 0 || degrees > 360) // error: out of range
  {
    cout << "\nError: out of range value [0,360]";
  }
  else
  {
    rad = ((float) degrees) / 180.0 * PIGRECO; 
    // note 1: explict casting, we can remove it because
    // to use the operator '/' between NO integer numbers 
    // it is mandatory that at least one of the two operands is a 
    // float or double variable type
 
    cout << "\n\nFrom degrees " << degrees; 
    cout << " to " << rad <<" rad";
  }

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   // for Windows Users use
   //
   // system("pause");

} // end main
