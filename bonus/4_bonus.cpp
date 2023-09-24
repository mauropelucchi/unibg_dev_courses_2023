/*


Si vuole creare un programma che permetta di memorizzare per ogni studente il numero di matricola e il voto d’esame.
Al termine dell’inserimento occorre evidenziare :
• La lista delle matricole che hanno ottenuto un voto positivo
• La lista delle matricole che hanno ottenuto il voto più alto
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct st_studente
{
  int matricola;
  int voto;
} STUDENTE;


int main()
{
  STUDENTE studenti[100];
  int numstud;
  int j;
  int max;
  cout << "Numero studenti ";
  cin >> numstud;
  for (j = 0; j < numstud; j++)
  {
    cout << "Matricola : ";
    cin >> studenti[j].matricola;
    cout << "Voto : ";
    cin >> studenti[j].voto;
  }
  cout << "Lista Studenti che hanno superato l'esame\n";
  for (j = 0; j < numstud; j++)
    if (studenti[j].voto >= 18)
      cout << "La matricola " << studenti[j].matricola << " ha ottenuto il voto " << studenti[j].voto << "\n";
  max = studenti[0].voto;
  for (j = 0; j < numstud; j++)
    if (max < studenti[j].voto)
      max = studenti[j].voto;
  cout << "I migliori studenti\n";
  for (j = 0; j < numstud; j++)
    if (studenti[j].voto == max)
      cout << "La matricola " << studenti[j].matricola << " ha ottenuto il voto " << studenti[j].voto << "\n";

  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  // for Windows Users use
  //
  // system("pause");
  return 0;
}