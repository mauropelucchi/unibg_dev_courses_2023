#include <iostream> // include standard libraries   

int main(int argc, char *argv[])
{ 
  int num, max;

  max = 0;
  num = 1; 
  while (num != 0)
  {
     std::cout << "Digit a number (digit 0 to exit):";
     std::cin >> num;
     if (num > max) max = num;
  }
  std::cout << "\nThe max is " << max << "\n";
  
   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   // for Windows Users use
   //
   // system("pause");
  return EXIT_SUCCESS;
}
