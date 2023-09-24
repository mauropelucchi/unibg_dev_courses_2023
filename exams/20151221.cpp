
#include <cstring>

struct Biglietto
{
  char numero[11];
  char data[11];
  char spettacolo[11];
  int giorno;
  char poltrona;
  float prezzo;
};

struct Nodo
{
  Biglietto biglietto;
  Nodo *next;
};

Biglietto *BigliettiTipologiaRedditizia(Nodo *testa,
                                        char tipologiaVoluta,
                                        float soglia)
{

  Nodo *currPtr = testa;
  float somma = 0.0;
  int count = 0 while (currPtr != NULL)
  {
    if (tipologiaVoluta == currPtr->biglietto.poltrona)
    {
      somma += currPtr->biglietto.prezzo;
      count++;
    }
    currPtr = currPtr->next;
  }

  if (count == 0)
    return NULL;

  float media = somma / count;

  if (media <= soglia)
    return NULL;

  Biglietto *vett = new Biglietto[count];
  int z = 0;
  currPtr = testa;
  while (currPtr->next != NULL)
  {
    if (tipologiaVoluta == currPtr->biglietto.poltrona)
    {
      vett[z] = currPtr->biglietto;
      z += 1;
    }
    currPtr = currPtr->next;
  }

  // bubble-sort
  Biglietto temp;
  for (i = 0; i < count - 1; i++)
  {
    for (j = 0; j < count - 1 - i; j++)
    {
      if (strcmp(vett[j].numero, vett[j + 1].numero) > 0)
      {
        temp = vett[j];
        vett[j] = vett[j + 1];
        vett[j + 1] = temp;
      }
    }
  }

  return vett;
}
