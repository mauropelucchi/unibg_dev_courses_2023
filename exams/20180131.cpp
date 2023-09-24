/*

INFORMATICA 12 CFU – Modulo di Programmazione 
(ING. INFORMATICA)
Prof. G. PSAILA

APPELLO DEL 31/01/2018



Si consideri un programma per gestire la raccolta delle informazioni relative ai buoni sconto offerti
da un sito di prenotazione alberghi ai propri clienti. Un buono sconto è descritto da un tipo strutturato
denominato BUONO, i cui campi sono un codice di 10 cifre (che identifica univocamente un buono), la data di
emissione (stringa nel formato internazionale aaaa-mm-gg ), l’indirizzo email del cliente al
quale viene proposto (stringa di 250 caratteri), il valore del buono in Euro, la data di scadenza,
lo stato del buono (numero intero, dove 1 indica che il buono non è stato ancora utilizzato,
2 indica che è stato utilizzato e 3 indica che è scaduto).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a
sua volta basato sul tipo BUONO.

Si scriva la funzione denominata QualeElenco che riceve come parametri due liste di buoni, denominate
rispettivamente lista1 e lista2, un vettore di date di scadenza (puntatori a carattere)  denominato
datescadenza e un numero intero size (che indica gli elementi nel vettore datescadenza) .
La funzione calcola il valore conta1, che indica quanti buoni in lista1 hanno come data di scadenza
una delle date riportate nel vettore dateScadenza, ed il valore conta2, che indica quanti
buoni in lista2 hanno come data di scadenza una delle date riportate nel vettore dateScadenza.
La funzione restituisce 1 se conta1 è maggiore di conta2, restituisce 2 se conta2 è maggiore di conta1,
restituisce 0 se conta1 e conta2 sono uguali. Non sono previste condizioni di errore.
N.B. Si eviti la duplicazione del codice.



*/

#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_DATE 8

struct BUONO
{
    char codice[11];
    char data_emissione[11];
    char data_scadenza[11];
    char email_acquirente[251];
    float valore;
    int stato;
};

struct NODO
{
    BUONO info;
    NODO *next;
};

void CreaLista(NODO *&head);
int CreaListaDataScadenza(char *datescadenza[]);
NODO *Inserimento_in_Testa(NODO *head, BUONO info);

int ControllaBuoni(NODO *lista, char *datescadenza[], int size);
int QualeElenco(NODO *lista1, NODO *lista2, char *datescadenza[], int size);

int main()
{

    NODO *head1 = NULL;
    NODO *head2 = NULL;
    char *datescadenza[MAX_DATE];
    int i;

    for (int i = 0; i < MAX_DATE; i++)
    {
        datescadenza[i] = (char *) malloc(11);
    }
    int size;
    int controllo;
    size = CreaListaDataScadenza(datescadenza);
    CreaLista(head1);
    CreaLista(head2);

    controllo = QualeElenco(head1, head2, datescadenza, size);
    cout << controllo;
}

int CreaListaDataScadenza(char *datescadenza[])
{
    int scelta = -1;
    int i = 0;
    while (scelta != 0)
    {
        cout << "Inserisci la data di scadenza" << endl;
        cin.getline(datescadenza[i], 10, '\n');
        i++;
        if (i < MAX_DATE)
        {
            cout << "Vuoi continuare (0 termina, <> 0 continuo)" << endl;
            cin >> scelta;
            cin.ignore(55, '\n');
        }
        else
        {
            scelta = 0;
        }
    }
    return i;
}

void CreaLista(NODO *&head)
{
    int scelta = -1;
    while (scelta != 0)
    {
        BUONO info;
        cout << "Inserisci il codice" << endl;
        cin.getline(info.codice, 10, '\n');
        cout << "Inserisci la data di emissione" << endl;
        cin.getline(info.data_emissione, 10, '\n');
        cout << "Inserisci la data di scadenza" << endl;
        cin.getline(info.data_scadenza, 10, '\n');
        cout << "Inserisci la mail dell'acquirente" << endl;
        cin.getline(info.email_acquirente, 250, '\n');
        cout << "Inserisci il valore" << endl;
        cin >> info.valore;
        cout << "Inserisci lo stato (1 non utilizzato, 2 utilizzato, 3 scaduto)" << endl;
        cin >> info.stato;
        cin.ignore(55, '\n');

        head = Inserimento_in_Testa(head, info);

        cout << "Vuoi continuare (0 termina, <> 0 continuo)" << endl;
        cin >> scelta;
        cin.ignore(55, '\n');
    }
}

NODO *Inserimento_in_Testa(NODO *head, BUONO info)
{
    NODO *t;
    t = new NODO;  // (NODO *) malloc(sizeof(NODO))
    if (t == NULL)
        return NULL;

    t->info = info;
    t->next = NULL;
    if (head == NULL)
        return t;

    t->next = head;
    return t;
}

int ControllaBuoni(NODO *lista, char *datescadenza[], int size)
{
    int totale = 0;
    while (lista != NULL)
    {
        for (int i = 0; (i < size); i++)
        {
            if (strcmp(lista->info.data_scadenza, datescadenza[i]) == 0)
            {
                totale++;
                break;
            }
        }
        lista = lista->next;
    }
    return totale;
}

int QualeElenco(NODO *lista1, NODO *lista2, char *datescadenza[], int size)
{

    int conta1 = ControllaBuoni(lista1, datescadenza, size);
    int conta2 = ControllaBuoni(lista2, datescadenza, size);

    if (conta1 > conta2) {
        return 1;
    } else if (conta1 < conta2) {
        return 2;
    } else {
        return 0;
    }
}
