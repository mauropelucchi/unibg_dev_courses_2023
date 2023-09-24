/*

Scrivere un programma per la gestione di un archivio di videocassette (al massimo 200) Per ogni videocassetta si deve poter memorizzare:
<codice cassetta [max 10 caratteri]>, <titolo film [max 30 caratteri]>,
<regista [max 30 caratteri]
<anno di produzione [numero di 4 cifre]>.
Il programma deve proporre dopo aver caricato in memoria i dati presenti su disco un menù che permetta le seguenti operazioni:
- Inserimento di una nuova cassetta nell’archivio
- Stampare l’archivio in ordine alfabetico per titolo;
- Salvataggio in un archivio
- Preparazione di un file HTML per visualizzare una tabella contenente i dati in archivio

*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

struct video
{
  char cod[11];
  char tit[31];
  char reg[31];
  int anno;
};

void carica(video *);
void stampa(video *, int);
void registra(video *, int);
int fcarica(video *);
void mettibianchi(char *stringa, int quanti);
void stampahtml(video *, int);

int main()
{
  video arc[200];
  int n;
  int s;
  s = 1;
  n = 0;
  // Chiamo la funzione che carica in memoria i dati
  n=fcarica(arc);
  while (s != 0)
  {
    cout << "scelta : 0=termina 1=nuovo 2=stampa 3=salva 4=Html" << endl;
    cout << "Inserire la scelta : ";
    cin >> s;
    switch (s)
    {
    case 1:
      carica(&arc[n]);
      n++;
      break;
    case 2:
      stampa(arc, n);
      break;
    case 3:
      registra(arc, n);
      break;
    case 4:
      stampahtml(arc, n);
      break;
    }
  }
}

// funzione per inserire una video cassetta
void carica(video *c)
{
  char acapo;
  cout << "Codice ";
  cin >> c->cod;
  cout << "Titolo ";
  cin.get(acapo);
  cin.get(c->tit, 30);
  cout << "Regista ";
  cin.get(acapo);
  cin.get(c->reg, 30);
  cout << "Anno ";
  cin >> c->anno;
}

// funzione per stampare tutte le video cassette
void stampa(video *c, int n)
{
  int j;
  for (j = 0; j < n; j++)
  {
    cout << "Codice " << c->cod << '\n';
    cout << "Titolo " << c->tit << '\n';
    cout << "Regista " << c->reg << '\n';
    cout << "Anno " << c->anno << '\n';
    cout << "----------------------\n";
    c++;
  }
  // wait for user to hit enter or another key
  std::cin.sync();
  std::cout << "press enter to exit...";
  std::cin.ignore();
  //
  // for Windows Users use
  //
  // system("pause");
}

// funzione per registrare su file tutte le video cassette
void registra(video *c, int n)
{
  ofstream fout;
  int j;
  char bianchi[30];
  // apro in scrittura il file
  fout.open("elenco.txt");
  // ciclo di registrazione
  for (j = 0; j < n; j++)
  {
    fout << c->cod;
    // inserisco gli spazi per arrivare a 10 caratteri
    mettibianchi(bianchi, 10 - strlen(c->cod));
    fout << bianchi;
    fout << c->tit;
    // inserisco gli spazi per arrivare a 30 caratteri
    mettibianchi(bianchi, 30 - strlen(c->tit));
    fout << bianchi;
    fout << c->reg;
    // inserisco gli spazi per arrivare a 30 caratteri
    mettibianchi(bianchi, 30 - strlen(c->reg));
    fout << bianchi;
    fout << c->anno;

    fout << '\n';
    c++;
  }
  fout.close();
}

// funzione per recuperare i dati da file
int fcarica(video *c)
{
  ifstream fin;
  int j = 0;
  char buffer[100];
  char buffer2[100];
  // apro il file in lettura
  fin.open("elenco.txt");
  while (!fin.eof())
  {
    fin.getline(buffer, 99); // E' una video cassetta
    if (strlen(buffer) != 0)
    {
      // copio in buffer2 i primi 10 caratteri
      strncpy(buffer2, buffer, 10);
      buffer2[10] = '\0';
      strcpy(c->cod, buffer2);
      // copio in buffer2 i successivi 30 caratteri
      strncpy(buffer2, buffer + 10, 30);
      buffer2[30] = '\0';
      strcpy(c->tit, buffer2);
      // copio in buffer2 i successivi 30 caratteri
      strncpy(buffer2, buffer + 40, 30);
      buffer2[30] = '\0';
      strcpy(c->reg, buffer2);
      // copio in buffer2 i successivi 4 caratteri
      strncpy(buffer2, buffer + 70, 4);
      buffer2[4] = '\0';
      // trasformo la stringa in un intero
      c->anno = atoi(buffer2);
      c++;
      j++;
    }
  }
  fin.close();

  // restituisco il numero di video cassette lette
  return (j);
}

// funzione per preparare una stringa di spazi
void mettibianchi(char *stringa, int quanti)
{
  int j;
  for (j = 0; j < quanti; j++)
  {
    stringa[j] = ' ';
  }
  stringa[j] = '\0';
}
// funzione per generare un file HTML contenente i dati dell'archivio

void stampahtml(video *c, int n)
{
  ofstream fout;
  int j;
  char bianchi[30];
  char buffer[100];
  fout.open("elenco.html");
  fout << "<html>" << endl;
  fout << "<head>" << endl;
  fout << "<title>Elenco</title>" << endl;
  fout << "</head>" << endl;
  fout << "<body>" << endl;
  fout << "<table border=1 cellpadding=2 width='100%'>" << endl;
  fout << "<tr>" << endl;
  fout << "<td with='25%'>Codice></td><td with='25%'>Titolo</td><td width='25%'>Regista</td><td with='25%'>Anno</td></tr>" << endl;
      for (j = 0; j < n; j++)
  {
    fout << "<tr>" << endl;
    fout << "<td>" << endl;
    fout << c->cod << endl;
    fout << "</td>" << endl;
    fout << "<td>" << endl;
    fout << c->tit << endl;
    fout << "</td>" << endl;
    fout << "<td>" << endl;
    fout << c->reg << endl;
    fout << "</td>" << endl;
    fout << "<td>" << endl;
    fout << c->anno << endl;
    fout << "</td>" << endl;
    fout << "</tr>" << endl;
    c++;
  }
  fout << "</table>" << endl;
  fout << "</body>" << endl;
  fout << "</html>" << endl;
  fout.close();
}