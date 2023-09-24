/*
Write a program that acquires from the keyboard a sequence of 
characters finished by !
and you report a derived sequence on the monitor
from the previous one according to the rules of the F-alphabet
(each vowel is doubled by inserting an f in between). 

Example:
how much I love this course!
hofow mufuch I lofovefo thifis cofoufursefe!
For simplicity, let's consider only lower case letters. 
Every character other than vowels must remain unchanged. 
Acquire one character at a time from the keyboard.

*/

#include <iostream>
using namespace std; 

int main( ) { 
   char c; 
   cout << "Digit a sentences: \n";
   do {
      cin.get(c);
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
         cout << c << "f" << c;
      else 
      cout << c;  
   } while (c != '!');  
   cout << endl;
   
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

