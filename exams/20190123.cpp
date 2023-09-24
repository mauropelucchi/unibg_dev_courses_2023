/*


INFORMATICA 12 CFU – Modulo di Programmazione 
(ING. INFORMATICA)
Prof. G. PSAILA

APPELLO DEL 23/01/2019


Si consideri un programma per gestire la raccolta delle informazioni relative ai coupon per acquisto di 
servizi, venduti da un sito di vendita di questi coupon. Un coupon è descritto da un tipo strutturato denominato COUPON, 
i cui campi sono un codice di 10 caratteri (che identifica univocamente un coupon), la data di emissione (stringa nel 
formato internazionale aaaa-mm-gg ), la data di scadenza, il codice dell’esercente (stringa di 10 caratteri), l’indirizzo 
email dell’acquirente (stringa di 250 caratteri), il valore del coupon in Euro, lo stato del coupon (numero intero, dove 
1 indica che il coupon non è stato ancora utilizzato, 2 indica che è stato utilizzato).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua 
volta basato sul tipo COUPON.

Si scriva la funzione denominata FondiNonDuplicatiInDate che riceve come parametri due liste di coupon, 
denominate rispettivamente lista1 e lista2. La funzione accoda a lista2 tutti i coupon in lista1 che non sono 
precedentemente presenti in lista2 (si usi il codice del coupon per fare la verifica). La funzione restituisce il 
numero di coupon accodati a lista2, mentre restituisce -1 in caso di errore.
N.B. Si eviti la duplicazione del codice.
N.B. si noti che lista2 potrebbe essere vuota all’inizio.


*/

#include <cstring>
#include <iostream>
using namespace std;

struct COUPON
{
    char codice[11];
    char data_emissione[11];
    char data_scadenza[11];
    char codice_esercente[11];
    char email_acquirente[251];
    float valore;
    int stato;
};

struct NODO
{
    COUPON info;
    NODO *next;
};

void CreaListaCoupon(NODO *&head);
int Inserimento_in_Coda(NODO *&head, COUPON info);
bool VerificaCoupon(NODO *head, char *codice);
int FondiNonDuplicatiInDate(NODO *lista1, NODO *lista2);
void StampaLista(NODO *head);

int main()
{

    NODO *head1 = NULL;
    NODO *head2 = NULL;
    int totale_coupon_accodati;
    CreaListaCoupon(head1);
    CreaListaCoupon(head2);

    totale_coupon_accodati = FondiNonDuplicatiInDate(head1, head2);
    if (totale_coupon_accodati == -1)
        cout << "Errore" << endl;
    else
        cout << "Sono stati accodati " << totale_coupon_accodati << " coupon." << endl
             << endl;

    StampaLista(head2);
}

void CreaListaCoupon(NODO *&head)
{
    int scelta = -1;
    while (scelta != 0)
    {
        COUPON info;
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
        cout << "Inserisci lo stato (1 non utilizzato, 2 utilizzato)" << endl;
        cin >> info.stato;
        cin.ignore(55, '\n');

        int esito = Inserimento_in_Coda(head, info);
        cout << "Esito inserimento " << esito << endl;

        cout << "Vuoi continuare (0 termina, <> 0 continuo)" << endl;
        cin >> scelta;
        cin.ignore(55, '\n');
    }
}

int Inserimento_in_Coda(NODO *&head, COUPON info)
{
    NODO *t;
    t = new NODO;
    if (t == NULL)
        return -1;

    t->info = info;
    t->next = NULL;
    if (head == NULL)
    {
        head = t;
        return 0;
    }

    NODO *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = t;
    return 0;
}

bool VerificaCoupon(NODO *head, char *codice)
{
    NODO *p = head;
    while (p != NULL)
    {
        if (strcmp(p->info.codice, codice) == 0)
        {
            return false;
        }
        p = p->next;
    }
    return true;
}


int FondiNonDuplicatiInDate(NODO *lista1, NODO *lista2) {
	int numero_elementi_accodati = 0;
	NODO *t;

	if (lista1 == NULL && lista2 == NULL) {
		return -1;
    }

	if (lista1 == NULL) {
		return 0;
    }

	t = lista1;
	while (t != NULL)
	{
		if (VerificaCoupon(lista2, t->info.codice)) {
            int esito = Inserimento_in_Coda(lista2, t->info);
            cout << "Esito inserimento " << esito << endl;
            if (esito != 0) {
                return -1;
            }
            numero_elementi_accodati++;
        }
		t = t->next;
	}

	return numero_elementi_accodati;
}

void StampaLista(NODO *head)
{
    NODO *p = head;
    while (p != NULL)
    {
        cout << p->info.codice << " -- " << p->info.stato << endl;
        p = p->next;
    }
}