

int main(int argc, char *argv[])
{  
  int num, sum;

  sum = 0;
  num = 1;
  while (num != 0) 
  {
      cout << "\n Digit a number (digit 0 to exit): ";
      cin >> num;
      sum = sum + num;
  }
  cout << "\nThe resuklt is " << sum << endl << endl;

   // wait for user to hit enter or another key
   std::cin.sync();
   std::cout << "press enter to exit...";
   std::cin.ignore();
   // for Windows Users use
   //
   // system("pause");
  return EXIT_SUCCESS;
}
