/*

INFORMATICA 12 CFU – Modulo di Programmazione 
(ING. INFORMATICA)
Prof. G. PSAILA

APPELLO DEL 24/02/2017



Si consideri un programma per gestire la raccolta delle informazioni relative ad un listino prezzi di 
prodotti da vendere, organizzato in una lista dinamica. Un prodotto è definito da un tipo strutturato 
denominato PRODOTTO, i cui campi sono il codice (stringa di 12 caratteri) la data di inserimento 
nel listino (stringa nel formato internazionale aaaa-mm-gg ), il prezzo (numero in virgola mobile), 
la percentuale IVA (numero intero) e una tipologia di prodotto (un numero intero positivo).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è 
a sua volta basato sul tipo PRODOTTO.

Si scriva la funzione denominata UnisciListini che riceve come parametri due liste di prodotti. La 
funzione crea uno nuova lista ottenuta fondendo i prodotti presenti nelle due liste nel modo seguente:
•	se un codice di prodotto è presente in una sola delle due liste, viene riportato così com’è nella nuova lista;
•	se un codice di prodotto è presente in entrambe le liste, viene riportata nella nuova lista la versione con il prezzo più basso.
La funzione restituisce l’indirizzo della testa della nuova lista; in caso di problemi, restituisce il valore NULL.
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
PRODOTTO VerificaProdotto(NODO *head, PRODOTTO info);
int SpostaProdotto(NODO *&head, NODO *lista, NODO *lista_controllo);
NODO *UnisciListini(NODO *lista1, NODO *lista2);
void StampaLista(NODO *head);

int main()
{

    NODO *head1 = NULL;
    NODO *head2 = NULL;
    NODO *head3 = NULL;

    CreaLista(head1);
    CreaLista(head2);

    head3 = UnisciListini(head1, head2);
    StampaLista(head3);
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

bool VerificaCodice(NODO *head, char *codice) {
    while (head != NULL) {
        if(strcmp(head->info.codice, codice) == 0) {
            return false;
        }
        head = head->next;
    }
    return true;
}

PRODOTTO VerificaProdotto(NODO *head, PRODOTTO info) {
    while (head != NULL) {
        if(strcmp(head->info.codice, info.codice) == 0) {
            if(info.percentuale_iva > head->info.prezzo) {
                return head->info;
            } else {
                return info;
            }
        }
        head = head->next;
    }
    return info;
}

int SpostaProdotto(NODO *&head, NODO *lista, NODO *lista_controllo) {
    while (lista != NULL) {
        if(VerificaCodice(head, lista->info.codice)) {
            PRODOTTO info = VerificaProdotto(lista_controllo, lista->info); 
            head = Inserimento_in_Testa(head, lista->info);
            if (head == NULL) {
                return 1;
            }
        }
        lista = lista->next;
    }
    return 0;
}

NODO *UnisciListini(NODO *lista1, NODO *lista2)
{

    NODO *nuovaHead = NULL;
    int esito;
    esito = SpostaProdotto(nuovaHead, lista1, lista2);
    if (esito != 0) {
            return NULL;
    }
    esito = SpostaProdotto(nuovaHead, lista2, lista1);
    if (esito != 0) {
        return NULL;
    }
    return nuovaHead;
}


void StampaLista(NODO *head) {
    NODO *p = head;
    while (p != NULL) {
        cout << p->info.codice << " -- " << p->info.prezzo << endl;
        p = p->next;
    }
}
