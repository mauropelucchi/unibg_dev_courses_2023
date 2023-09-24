#include <iostream> // include standard libraries
using namespace std;

int main(int argc, char *argv[])
{  
  int num1, num2, sum;
  sum = 0;

  cout << "\nSum of 2 numbers\n\n";
  cout << "Insert 2 numbers" << endl << endl;
  cout << "First number: ";
  cin >> num1;
  cout << "\nSecond number: ";
  cin >> num2;
  sum = num1 + num2;
  cout << "\n\nThe result is " << sum << "\n\n";

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   // for Windows Users use
   //
   // system("pause");
}
