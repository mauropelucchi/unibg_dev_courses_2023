#include <cstdlib>
#include <iostream>

using namespace std;
/*
  example of multi-line comments
*/

int main(int argc, char *argv[])
{
  int i = 5; // single line comment
  char letter = 'A';

  cout << "Hello World !" << endl;
  cout << "An integer value (i: " << i << ")" << endl;
  cout << "A character value (letter: " << letter << ")" << endl;

  // wait for user to hit enter or another key
  // std::cin.sync();
  // std::cout << "press enter to exit...";
  // std::cin.ignore();
  // for Windows Users use
  //
  system("pause");
  return EXIT_SUCCESS;
}
