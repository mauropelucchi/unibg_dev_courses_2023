/*

INFORMATICA 12 CFU – Modulo di Programmazione 
(ING. INFORMATICA)
Prof. G. PSAILA

PROVA IN ITINERE DEL 27/01/2017


Si consideri un programma per gestire la raccolta delle informazioni relative ad un listino prezzi di prodotti da vendere,
organizzato in una lista dinamica. Un prodotto è definito da un tipo strutturato denominato PRODOTTO, i cui campi sono il codice
(stringa di 12 caratteri) la data di inserimento nel listino (stringa nel formato internazionale aaaa-mm-gg ), il prezzo (numero in virgola mobile),
la percentuale IVA (numero intero) e una tipologia di prodotto (un numero intero positivo).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo PRODOTTO.

Si scriva la funzione denominata ProdottiTipologiaTop che riceve come parametro la lista dei prodotti.
La funzione calcola la media dei prezzi media,
quindi cerca il prodotto con il prezzo più alto (in caso di più prodotti con lo stesso prezzo, considera il primo trovato) e ne estrae la tipologia tipMax. 
Fatto questo, la funzione deve produrre un vettore di PRODOTTO (restituisce l’indirizzo del primo elemento) che contiene tutti i prodotti di tipologia tipMax aventi prezzo maggiore o uguale a media.
Il vettore deve contenere un elemento in più, con il codice impostato come stringa vuota, che serve per indicare al chiamante che il vettore è finito. Nel caso in cui non vi siano prodotti nella lista, ovvero si verifichi qualche errore, la funzione restituisce il valore NULL.
N.B. Si eviti la duplicazione del codice.



*/

#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;


struct PRODOTTO
{
    char codice[13];
    char data_inserimento[11];
    float prezzo;
    unsigned int percentuale_iva;
    unsigned int tipologia_prodotto;
};

struct NODO
{
    PRODOTTO info;
    NODO *next;
};

void CreaLista(NODO *&head);
NODO *Inserimento_in_Testa(NODO *head, PRODOTTO info);
float CalcolaMedia(NODO *head);
PRODOTTO* ProdottiTipologiaTop(NODO *lista, int &tipMax, float &media_prezzi);
void StampaLista(PRODOTTO *prodotti);

int main()
{

    NODO *head = NULL;
    PRODOTTO *prodotti;
    float media;
    int tipMax;

    CreaLista(head);

    prodotti = ProdottiTipologiaTop(head, tipMax, media);
    StampaLista(prodotti);
}

void CreaLista(NODO *&head)
{
    int scelta = -1;
    while (scelta != 0)
    {
        PRODOTTO info;
        cout << "Inserisci il codice" << endl;
        cin.getline(info.codice, 12, '\n');
        cout << "Inserisci la data di inserimento" << endl;
        cin.getline(info.data_inserimento, 10, '\n');
        cout << "Inserisci il prezzo" << endl;
        cin >> info.prezzo;
        cout << "Inserisci iva" << endl;
        cin >> info.percentuale_iva;
        cout << "Inserisci la tipologia prodotto" << endl;
        cin >> info.tipologia_prodotto;
        cin.ignore(55, '\n');

        head = Inserimento_in_Testa(head, info);

        cout << "Vuoi continuare (0 termina, <> 0 continuo)" << endl;
        cin >> scelta;
        cin.ignore(55, '\n');
    }
}

NODO *Inserimento_in_Testa(NODO *head, PRODOTTO info)
{
    NODO *t;
    t = new NODO;
    if (t == NULL)
        return NULL;

    t->info = info;
    t->next = NULL;
    if (head == NULL)
        return t;

    t->next = head;
    return t;
}

float CalcolaMedia(NODO *head) {
    int num = 0;
    float s = 0;
    while (head != NULL) {
        num++;
        s = s + head->info.prezzo;
        head = head->next;
    }
    return (s / num);
}

PRODOTTO* ProdottiTipologiaTop(NODO *lista, int &tipMax, float &media_prezzi)
{
    if(lista == NULL) {
        return NULL;
    }
    // calcolo il num max di elementi
    NODO *p = lista;
    int numero_elementi = 0;
    while (p != NULL) {
        numero_elementi++;
        p = p->next;
    }

    numero_elementi++;
    PRODOTTO* nuova_lista = new PRODOTTO[numero_elementi];
    
    // calcolo la media
    media_prezzi = CalcolaMedia(lista);
    p = lista;

    // prezzo max, tipo max
    float prezzo_max = p->info.prezzo;
    tipMax = p->info.tipologia_prodotto;
    while (p != NULL) {
        if(p->info.prezzo > prezzo_max) {
            prezzo_max = p->info.prezzo;
            tipMax = p->info.tipologia_prodotto;
        }
        p = p->next;
    }
    p = lista;
    int i =  0;
    while (p != NULL) {
        if((p->info.prezzo >= media_prezzi) && (p->info.tipologia_prodotto == tipMax)) {
            nuova_lista[i] = p->info;
            i++;
        }
        p = p->next;
    }
    PRODOTTO coda;
    strcpy(coda.codice, "\0");
    nuova_lista[i] = coda;

    return (nuova_lista);
}

void StampaLista(PRODOTTO *prodotti) {
    while (strcmp(prodotti->codice, "\0") != 0) {
        cout << prodotti->prezzo << " - " << prodotti->prezzo << endl;
        prodotti = prodotti + 1;
    }
}
