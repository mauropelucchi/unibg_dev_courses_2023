/*


Scrivere un programma che dopo aver acquisito un certo numero di voti di un esame,
numero non noto a priori ,calcoli il valore medio, il voto minimo e quello massimo
*/

#include <iostream>
using namespace std;

int main()
{
  int voto;
  int j = 0;
  int k;
  int somma = 0;
  float media;
  int minimo;
  int massimo;
  do
  {
    cout << "Inserire il voto (0 per terminare) : ";
    cin >> voto;
    if (voto != 0)
    {
      j++;
      somma += voto;
      if (j == 1)
      {
        minimo = voto;
        massimo = voto;
      }
      else
      {
        if (voto < minimo)
          minimo = voto;
        if (voto > massimo)
          massimo = voto;
      }
    }
  } while (voto != 0);
  media = (float)somma / j;
  cout << "Media : " << media << endl;
  cout << "Voto minimo :" << minimo << endl;
  cout << "Voto massimo :" << massimo << endl;

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  // for Windows Users use
  //
  // system("pause");
  return 0;
}