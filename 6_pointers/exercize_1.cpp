/*

La seguente dichiarazione definisce il catalogo prezzi nel sistema informativo di un 
piccolo supermercato, su una piattaforma in cui 

sizeof(long)==8,  sizeof(float)==sizeof(int)==sizeof(void *)==4

*/

typedef char Descrizione[40];
typedef struct
{
  unsigned long barcode;
  Descrizione descr;
  float prezzo;
  int noPunti;
  char *descrEstesa;
} Articolo;
typedef struct
{
  Articolo list[1000];
  int numArticoli;
} CatalogoGenerale;

CatalogoGenerale cat;

/*

noPunti è un booleano che identifica gli articoli su cui per legge non si 
possono effettuare promozioni o fidelizzazioni; numArticoli indica quanti dei 1000 elementi di 
list sono effettivamente utilizzati. 

(a)  Si calcoli quanto vale sizeof(cat)

*/

sizeof(cat) == sizeof(Articolo) * 1000 + sizeof(int) sizeof(Articolo) == 8 + 40 + 4 + 4 + 4 == 60
sizeof(cat) == 60004

/* 
(b)  Sapendo  che  cat è  allocato  a  partire  dall' indirizzo  2348,  si calcoli l'
indirizzo della cella contenente la variabile cat.list[20].noPunti

*/

2348 +
20 * sizeof(Articolo) + sizeof(barcode) + sizeof(descr) + sizeof(prezzo)

== 2348 + 1252 == 3600

/* 
(c)  Si implementi una funzione C++ ...stampa(...) che riceve come parametro un Articolo (passato 
per indirizzo) e stampa su stdout una riga così come deve apparire sullo scontrino. 

*/

    void stampa(Articolo *a)
{

  cout << (*a).descr << "\t \t";
  cout << setw(5) << setprecision(2) << (*a).prezzo;
}

/*
(d)  Si  consideri  che:  
(1.)  i  cataloghi  contengono  gli  articoli  in  ordine  di  codice  a 
       barre  crescente,  e  
(2.) non possono esservi due articoli con lo stesso codice a barre.

Si implementi una funzione C ...trova(...)che riceve come parametri un catalogo di articoli 
(passato per indirizzo) e un codice a barre, e restituisce 
al chiamante l' indirizzo dell' articolo identificato dal codice, o NULL se il codice non 
corrisponde a nessun articolo in catalogo. 

*/

Articolo *trova(CatalogoGenerale *c, unsigned long bar)
{

  for (int i = 0; i < c->numArticoli; ++i)
    if (bar == c->list[i].barcode)
      return &c->list[i];

  return NULL;
}

/* 
e)  Si implementi una funzione ...scan(...) che legge da stdin una sequenza di interi positivi 
(di lunghezza  ignota  e  a  priori  illimitata),  terminata  dal  valore  0,  che  rappresentano  i  codici  
a  barre nell' ordine  in  cui  sono  letti  dallo  scanner  laser  di  una  delle  casse  del supermercato.  
La  funzione  riceve come parametro il catalogo del supermercato (passato per indirizzo), e: 

- Restituisce al chiamante l' importo totale da pagare. 
- Stampa su stdout lo scontrino (attenzione: non si perda tempo a
  organizzare intestazioni elaborate!). 
- Stampa su stdout i punti fedeltà conseguiti dal cliente (si ha diritto a   
  un punto fedeltà per ogni euro di spesa  oltre  i  primi  5€,  senza  
  considerare  i  prodotti  "non  promozionabili",  come  ad  esempio  
  giornali  e medicinali, per i quali l' attributo noPunti ha valore 1).
*/

float scan(CatalogoGenerale *c)
{
  unsigned long bar;
  Articolo *addr;
  float tot = 0.0, perPunti = 0.0;
  int puntiAcquisiti = 0;

  do
  {
    cin >> bar;

    addr = trova(c, bar);
    if (addr != NULL)
    {
      tot += addr->prezzo;

      if (addr->noPunti != 1)
        perPunti += addr->prezzo;

      stampa(addr);
    }
  } while (bar != 0L);

  if (perPunti > 5.0)
    cout << "\n Pti: " << (unsigned int)(perPunti - 5.0);
  return tot;
}


/*
f)  Si spieghi brevemente perché è particolarmente opportuno che trova() e scan() ricevano il  catalogo per indirizzo.

...

*/