/*

Modificare l'esercizio della precedente lezione ( Archivio di videocassette) in modo da gestire il
tutto utilizzando allocazione dinamica di memoria
e liste mantenendo in fase di inseriemento i dati sempre ordinati per codice.
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
  video *next;
};
void carica(video *&);
void stampa(video *);
void registra(video *&);
int fcarica(video *&);
void mettibianchi(char *stringa, int quanti);
int insordinato(video *&, video *&);
int inserisci_coda(video *&, video *&);

int main()
{
  video *head = NULL;
  int n;
  int s;
  s = 1;
  n = 0;
  // Chiamo la funzione che carica in memoria i dati
  n = fcarica(head);
  while (s != 0)
  {
    cout << "scelta : 0=termina 1=nuovo 2=stampa 3=salva" << endl;
    cout << "Inserire la scelta : ";
    cin >> s;
    switch (s)
    {
    case 1:
      carica(head);
      n++;
      break;
    case 2:
      stampa(head);
      break;
    case 3:
      registra(head);
      break;
    }
  }
}

// funzione per inserire una video cassetta
void carica(video *&p_head)
{
  char acapo;
  video *c;
  c = new video;

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

  // inserisco la nuova video cassetta ordinando la lista
  insordinato(p_head, c);
}

// inserisce ordinando per codice nella lista un elemento
int insordinato(video *&p_head2, video *&t)
{
  video *p;
  video *prec;
  // caso nessun elemento inserito
  if (p_head2 == NULL)
  {
    p_head2 = t;
    t->next = NULL;
    return 0;
  }
  // caso : il testo è minore del primo elemento
  if (strcmp(t->cod, p_head2->cod) < 0)
  {
    t->next = p_head2;
    p_head2 = t;
    return 0;
  }
  // caso : un solo elemento inserito e maggiore del primo
  if (p_head2->next == NULL)
  {
    p_head2->next = t;
    t->next = NULL;
    return 0;
  }
  // caso : lista con più elementi
  prec = p_head2;
  p = p_head2->next;
  // scorro la lista attuale
  while (p != NULL)
  {
    if (strcmp(t->cod, p->cod) < 0)
    {
      t->next = p;
      prec->next = t;
      return 0;
    }
    p = p->next;
    prec = prec->next;
  }
  // caso : inserisco in coda
  prec->next = t;
  t->next = NULL;
  return 0;
}

// funzione per stampare tutte le video cassette
void stampa(video *p_head)
{
  video *c;
  c = p_head;
  while (c != NULL)
  {
    cout << "Codice " << c->cod << '\n';
    cout << "Titolo " << c->tit << '\n';
    cout << "Regista " << c->reg << '\n';
    cout << "Anno " << c->anno << '\n';
    cout << "----------------------\n";
    c = c->next;
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
void registra(video *&p_head)
{
  ofstream fout;
  int j;
  char bianchi[30];
  video *c;
  c = p_head;
  // apro in scrittura il file
  fout.open("elenco.txt");
  // ciclo di registrazione
  while (c != NULL)
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
    c = c->next;
  }
  fout.close();
}

// funzione per recuperare i dati da file
int fcarica(video *&p_head)
{
  ifstream fin;
  int j = 0;
  char buffer[100];
  char buffer2[100];
  // apro il file in lettura
  fin.open("elenco.txt");
  video *c;

  while (!fin.eof())
  {
    fin.getline(buffer, 99); // E' una video cassetta
    if (strlen(buffer) != 0)
    {
      c = new video;
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
      inserisci_coda(p_head, c);
    }
  }
  fin.close();

  // restituisco il numero di video cassette lette
  return (j);
}

// inserisco la video cassetta nella lista in coda
int inserisci_coda(video *&p_head, video *&p_c)
{
  //nodo *varnodo; video *precedente;
  p_c->next = NULL;
  if (p_head == NULL)
    p_head = p_c;
  else
  {
    video *precedente = p_head;
    while (precedente->next != NULL)
      precedente = precedente->next;
    precedente->next = p_c;
  }
  return 0;
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
