/*

INFORMATICA 12 CFU – Modulo di Programmazione 
(ING. INFORMATICA)
Prof. G. PSAILA

PRE-APPELLO DEL 09/01/2020


Si consideri un programma per gestire la raccolta delle informazioni relative agli abbonamenti 
ad un parcheggio. Un abbonamento è descritto da un tipo strutturato denominato ABBONAMENTO, i cui campi 
sono un codice di 10 caratteri (che identifica univocamente l’abbonamento), 
la data di emissione (stringa nel formato internazionale aaaa-mm-gg ), 
la data di scadenza, il numero di targa (stringa di 10 caratteri), 
l’importo residuo (numero in virgola mobile), il valore dell’ultimo addebito e la data dell’ultimo addebito..
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo ABBONAMENTO.

Si scriva la funzione denominata EstraiNonDuplicati che riceve come parametri due liste di 
abbonamenti, denominate rispettivamente lista1 e lista2, ed un vettore di caratteri denominato 
data_cercata. La funzione restituisce una nuova lista che contiene tutti gli abbonamenti emessi in 
data_cercata che non sono presenti in entrambe le liste, ma solo in una delle due (si usi il codice 
dell’abbonamento per fare la verifica). In caso di errore, la funzione restituisce il valore NULL.
N.B. Si eviti la duplicazione del codice.


*/

#include <cstring>
#include <iostream>
using namespace std;


struct ABBONAMENTO
{
    char codice[11];
    char data_emissione[11];
    char data_scadenza[11];
    char targa[11];
    float importo_residuo;
    float ultimo_addebito;
    char data_ultimo_addebito[11];
};

struct NODO
{
    ABBONAMENTO info;
    NODO *next;
};

void CreaLista(NODO *&head);
NODO* Inserimento_in_Testa(NODO *head, ABBONAMENTO info);
bool VerificaAbbonamento(NODO *head, char *codice);
NODO* EstraiNonDuplicati(NODO *lista1, NODO *lista2, char *data_cercata);
void StampaLista(NODO *head);

int main() {

    NODO *head1 = NULL;
    NODO *head2 = NULL;
    NODO *head3 = NULL;
    char data_cercata[11];
    CreaLista(head1);
    CreaLista(head2);
    cout << "Inserisci la data cercata" << endl;
    cin.getline(data_cercata, 10, '\n');
    

    head3 = EstraiNonDuplicati(head1, head2, data_cercata);
    StampaLista(head3);

}


void CreaLista(NODO *&head) {
    int scelta = -1;
    while(scelta != 0) {
        ABBONAMENTO info;
        cout << "Inserisci il codice" << endl;
        cin.getline(info.codice, 10, '\n');
        cout << "Inserisci la data di emissione" << endl;
        cin.getline(info.data_emissione, 10, '\n');
        cout << "Inserisci la data di scadenza" << endl;
        cin.getline(info.data_scadenza, 10, '\n');
        cout << "Inserisci la targa" << endl;
        cin.getline(info.targa, 10, '\n');
        cout << "Inserisci la data dell'ultimo addebito" << endl;
        cin.getline(info.data_ultimo_addebito, 10, '\n');
        cout << "Inserisci il importo residuo" << endl;
        cin >> info.importo_residuo;
        cout << "Inserisci l'ultimo addebito" << endl;
        cin >> info.ultimo_addebito;
        cin.ignore(55, '\n');
        
        head = Inserimento_in_Testa(head, info);

        cout << "Vuoi continuare (0 termina, <> 0 continuo)" << endl;
        cin >> scelta;
        cin.ignore(55, '\n');

    }
}

NODO* Inserimento_in_Testa(NODO *head, ABBONAMENTO info) {
    NODO *t;
    t = new NODO;
    if( t == NULL)
        return NULL;
    
    t->info = info;
    t->next= NULL;
    if (head == NULL)
        return t;

    t->next = head;
    return t;
}

bool VerificaAbbonamento(NODO *head, char *codice) {
    while (head != NULL) {
        if(strcmp(head->info.codice, codice) == 0) {
            return false;
        }
        head = head->next;
    }
    return true;
}


int CopiaAbbonamento(NODO *&head, NODO *lista, NODO *lista2, char *data_cercata) {
    NODO *p = lista;
    while (p != NULL) {
        if(VerificaAbbonamento(lista2, p->info.codice) && strcmp(data_cercata, p->info.data_emissione)) {
            head = Inserimento_in_Testa(head, p->info);
            if (head == NULL) {
                return 1;
            }
        }
        p = p->next;
    }
    return 0;
}

NODO* EstraiNonDuplicati(NODO *lista1, NODO *lista2, char *data_cercata)
{

    NODO *nuovaHead = NULL;
    int esito;
    esito = CopiaAbbonamento(nuovaHead, lista1, lista2, data_cercata);
    if (esito != 0) {
            return NULL;
    }
    esito = CopiaAbbonamento(nuovaHead, lista2, lista1, data_cercata);
    if (esito != 0) {
        return NULL;
    }
    return nuovaHead;
}

void StampaLista(NODO *head) {
    while (head != NULL) {
        cout << head->info.codice << " -- " << head->info.data_emissione << endl;
        head = head->next;
    }
}