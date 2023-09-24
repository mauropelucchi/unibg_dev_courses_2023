/*


Scrivere un programma che dopo aver acquisito un certo numero di voti di un esame,
numero non noto a priori ,calcoli il valore medio, il voto minimo e quello massimo

(Con uso di vettori)
*/

#include <iostream>
using namespace std;

int main()
{
  int voti[100];
  int varvoto;
  int j = 0;
  int k;
  int somma = 0;
  float media;
  int minimo;
  int massimo;
  do
  {
    cout << "Inserire il voto (0 per terminare) : ";
    cin >> varvoto;
    if (varvoto != 0)
    {
      voti[j] = varvoto;
      j++;
    }
  } while (varvoto != 0);

  for (k = 0; k < j; k++)
  {
    somma += voti[k];
    if (k == 0)
    {
      minimo = voti[k];
      massimo = voti[k];
    }
    else
    {
      if (voti[k] < minimo)
        minimo = voti[k];
      if (voti[k] > massimo)
        massimo = voti[k];
    }
  }


    media = (float)somma / j;
    cout << "Media : " << media << endl;
    cout << "Voto minimo : " << minimo << endl;
    cout << "Voto massimo : " << massimo << endl;
    // wait for user to hit enter or another key
    std::cin.sync();
    std::cout << "press enter to exit...";
    std::cin.ignore();
    // for Windows Users use
    //
    // system("pause");
    return 0;
  }